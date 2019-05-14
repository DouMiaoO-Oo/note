# -*- coding: utf-8 -*-
# !usr/bin/env python3 
"""
-------------------------------------------------
   File Name：     KD-Tree
   Description :
   Author :       yuwei liu
   date：          2019/4/23
-------------------------------------------------
   Change Activity:
                   2019/5/14:
-------------------------------------------------
"""

import numpy as np
from numpy.linalg import norm


# 参考资料：https://sine-x.com/statistical-learning-method/#%E7%AC%AC3%E7%AB%A0-k%E9%82%BB%E8%BF%91%E7%AE%97%E6%B3%95
# 备注：np的切片是view，fancy index是copy


def dis_for_mat(x, mat):
    """
    :param x: np.ndarray, test sample
    :param mat: np.ndarray
    2-d matrix, each row vector is a training sample.
    :return:
    """
    if mat.ndim == 1:  # e.g., mat = np.array([1, 2]), shape of (2, )
        mat = mat.reshape(mat.shape[0], 1)
        # mat = mat.reshape(1, mat.shape[0])
    return norm(x - mat, axis=1)


def dis_for_vec(x, y):
    """
    :param x: np.ndarray, test sample
    :param y: np.ndarray
    :return:
    """
    return norm(x - y)


def find_k_nearest_naive(x, mat, k):
    """
    最基础的用来寻找k近邻的方法
    :param x: np.ndarray, test sample
    :param mat: np.ndarray
    2-d matrix, each row vector is a training sample.
    :param k:
    :return:
    """
    return np.argpartition(dis_for_mat(x, mat), k - 1)[:k]


class Node:
    def __init__(self, point, dimension):
        """

        :param point: point (training sample) id
        :param dimension:
        """
        self.point = point
        self.dimension = dimension
        self.left = None
        self.right = None


def kdtree_build_recur(mat, id_list, d):
    """
    :param mat: np.ndarray,
    2-d matrix, each row vector is a training sample.
    :param id_list: id of sample in this region
    :param d: current dimension
    :return:
    """
    assert type(id_list) == np.ndarray and id_list.ndim == 1
    cnt = len(id_list)  # r 这个维度下样本点的个数
    dim = mat.shape[1]  # dimension of sample vector
    if cnt == 1:  # 这个if可以省略
        return Node(id_list[0], d)  # point, dimension
    else:
        mid = cnt // 2
        # print("id_list = ", id_list)
        # print("mid=%s, point=%s" %(mid, id_list[mid]))
        # print()
        node = Node(id_list[mid], d)
        new_d = (d + 1) % dim
        if mid > 0:  # exist left tree
            left = id_list[:mid]  # 子树包含样本的序号, type of np.ndarray
            left_val_list = mat[left, new_d]  # 子树包含样本的序号在new_d维度上的取值 (X的view)
            left = left[np.argsort(left_val_list)]  # 根据new_d维度上元素的取值重排. （得到的left是copy，不是id_list的view）
            node.left = kdtree_build_recur(mat, left, new_d)

        if cnt > mid + 1:  # exist right tree
            right = id_list[mid + 1:]
            right_val_list = mat[right, new_d]
            right = right[np.argsort(right_val_list)]
            node.right = kdtree_build_recur(mat, right, new_d)
        return node


def kdtree_build(mat):
    """
    :param mat: np.ndarray,
    2-d matrix, each row vector is a training sample.
    :return:
    """
    return kdtree_build_recur(mat, np.argsort(mat[:, 0]), 0)


def kdtree_cand_fartest(x, mat, candidate):
    """
    :param x: np.ndarray, test sample
    :param mat: np.ndarray,
    2-d matrix, each row vector is a training sample.
    :param candidate: candidate point id list, type of np.ndarray, shape of (len(candidate), )
    :return:
    """
    index = np.argmax(dis_for_mat(x, mat[candidate]))
    return candidate[index]


def kdtree_cand_insert(x, mat, candidate, k, point):
    """
    :param x: np.ndarray, test sample
    :param mat: np.ndarray,
    2-d matrix, each row vector is a training sample.
    :param candidate: candidate point id list, type of np.ndarray, shape of (len(candidate), )
    :param k:
    :param point: point (sample id) to be check if it is k-nearest-neighborhood
    :return:
    """
    if point in candidate:  # 避免重复 （事实上不会重复）
        print("重复")
        return candidate

    if len(candidate) < k:  # number of candidates less than `k`
        candidate = np.append(candidate, point)
    else:
        fartest = kdtree_cand_fartest(x, mat, candidate)
        if dis_for_vec(x, mat[fartest, :]) > dis_for_vec(x, mat[point, :]):
            candidate[candidate == fartest] = point  # replace with `point`
    return candidate


def kdtree_find_recur(x, mat, candidate, node, k):
    """
    先深度遍历找到叶子节点，并将叶节点插入k近邻候选列表candidate，
    然后回溯之前遍历过的每个祖先节点并判断是否需要把该祖先节点插入进kd-tree,
    在回溯每个节点时判断该节点的另一个子节点..
    总的流程：先左（右）子节点 → 当前节点 → 最后检查与右（左）节点的区间是否有交集，再决定是否遍历该子节点
    Note：建议直接看下面的代码来理解
    :param x: np.ndarray, test sample
    :param mat: np.ndarray,
    2-d matrix, each row vector is a training sample.
    :param candidate: candidate point id list, type of np.ndarray, shape of (len(candidate), )
    :param node: current node of kd-tree
    :param k:
    :return:
    """
    point = node.point
    dimension = node.dimension
    if x[dimension] < mat[point][dimension]:  # x shape = (dimension of sample, )
        # search in left sub-tree
        if node.left is not None:
            candidate = kdtree_find_recur(x, mat, candidate, node.left, k)
        # insert (may or may not) current point into `candidate`
        candidate = kdtree_cand_insert(x, mat, candidate, k, point)
        # search right sub-tree if necessary
        fartest = kdtree_cand_fartest(x, mat, candidate)  # 这里多计算了一次，应该可以优化
        radius = dis_for_vec(x, mat[fartest, :])  # 这里多计算了一次，应该可以优化
        if node.right is not None \
                and (len(candidate) < k  # 下面判断交集放松了条件，只判断了一个维度？应该判断两点的距离是否小于radius
                     # 下方的代码其实是: x[dimension]+radius >= mat[point][dimension])
                     or radius >= np.abs(x[dimension] - mat[point][dimension])):
            candidate = kdtree_find_recur(x, mat, candidate, node.right, k)
    else:
        # search in right sub-tree
        if node.right is not None:
            candidate = kdtree_find_recur(x, mat, candidate, node.right, k)
        # insert (may or may not) current point into `candidate`
        candidate = kdtree_cand_insert(x, mat, candidate, k, point)
        # search left sub-tree if necessary
        fartest = kdtree_cand_fartest(x, mat, candidate)  # 这里多计算了一次，应该可以优化
        radius = dis_for_vec(x, mat[fartest, :])  # 这里多计算了一次，应该可以优化
        if node.left is not None \
                and (len(candidate) < k
                     or radius >= np.abs(mat[point][dimension] - x[dimension])):
            candidate = kdtree_find_recur(x, mat, candidate, node.left, k)
    return candidate


def kdtree_find(tree, x, mat, k):
    """
    :param tree: kd-tree
    :param x: np.ndarray, test sample
    :param mat: np.ndarray,
    2-d matrix, each row vector is a training sample.
    :param k:
    :return:
    """
    return kdtree_find_recur(x, mat, np.array([], dtype=int), tree, k)


def demo():
    import math
    import random
    test_times = 100
    sample_cnt = 200
    sample_dimension = 50
    correct = 0
    for _ in range(test_times):
        # 采用小数的特征
        mat = np.random.rand(sample_cnt, sample_dimension)  # training set
        x = np.random.rand(sample_dimension)  # test sample, shape = (sample_dimension, )
        # 使用int类型的特征
        # mat = np.random.randint(0, 100, size=(sample_cnt, sample_dimension))  # training set
        # x = np.random.randint(0, 100, size=sample_dimension)  # test sample, shape = (sample_dimension, )
        k = math.ceil(random.random() * sample_cnt)
        root = kdtree_build(mat)  # root of kd-tree
        cand_kd_tree = np.sort(kdtree_find(root, x, mat, k))
        cand_naive = np.sort(find_k_nearest_naive(x, mat, k))
        correct += sum(cand_naive == cand_kd_tree) == k
    print("correct number is ", correct)


def verify():
    def write_back(mat, x, k):
        with open("mat", 'w', encoding="utf8") as wf:
            m, n = mat.shape
            wf.write('[')
            for i in range(m):
                wf.write(str(mat[i][0]))
                for j in range(1, n):
                    wf.write(", %s" % mat[i][j])
                wf.write(';\n')
            wf.write(']\n')
        with open("x_k", 'w', encoding="utf8") as wf:
            wf.write('[')
            wf.write(str(x[0]))
            for i in range(1, len(x)):
                wf.write(", %s" % x[i])
            wf.write(']\n')
            wf.write(str(k))
            wf.write('\n')

    def print_kd_tree(root, depth):
        for i in range(depth):
            print('\t', end='')
        print(root.point)
        if root.left is not None:
            print_kd_tree(root.left, depth + 1)
        if root.right is not None:
            print_kd_tree(root.right, depth + 1)

    mat = np.array(
        [[69, 14, 31, 37, 8], [7, 85, 42, 16, 85], [50, 99, 38, 33, 15], [72, 53, 39, 69, 86], [42, 12, 24, 70, 6],
         [84, 95, 19, 69, 90], [23, 9, 80, 97, 95], [24, 79, 37, 12, 4], [43, 3, 75, 55, 35], [71, 71, 86, 1, 84],
         [11, 72, 33, 20, 83], [4, 6, 84, 28, 99], [70, 24, 7, 55, 5], [14, 53, 49, 84, 37], [6, 89, 64, 9, 71],
         [14, 80, 54, 59, 95], [16, 17, 70, 16, 51], [63, 74, 49, 89, 64], [30, 67, 86, 72, 3], [26, 24, 6, 34, 87]])
    x = np.array([80, 44, 91, 68, 55])
    k = 6
    # write_back(mat, x, k)  # 写入
    root = kdtree_build(mat)  # root of kd-tree
    print_kd_tree(root, 0)
    cand_kd_tree = np.sort(kdtree_find(root, x, mat, k))
    cand_naive = np.sort(find_k_nearest_naive(x, mat, k))
    correct_rate = sum(cand_naive == cand_kd_tree) / k
    print(correct_rate)


if __name__ == '__main__':
    demo()
    # verify()
