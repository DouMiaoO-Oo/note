#!/usr/bin/env python3
# _*_coding:utf-8_*_
import random
from collections import Counter
import numpy as np


def sample(arr):
    """
    Assume there are N items in arr, where we do not know the N before we finishing travel the array.
    We sample 1st item in 1/1% probability, sample the 2nd, 3rd ... i-th item with probability of 1/2, 1/3, ..., 1/i.
    For the ith item, it will be sampled at the last with probability of 1/i * (1- 1/(i+1)) * ....*(1-1/N) = 1/N.
    From the above analysis, we have proved that the process of sampling
     can assume each item of stream data `arr` has equal probability to be sampled.
    :param arr: stream data with unknown size
    :param k: target sample size
    [20, 31, 108, 489, 2597, 16309, 119084, 972214, 8887967, 90001181]
    :return:
    """
    res = None  # the item we sampled
    i = 0
    for v in arr:
        i += 1
        p = random.random()
        if p <= 1/i:
            res = v
    return res


def sample_k(arr, k):
    """

    :param arr: stream data with unknowed size
    :param k: The number of items needed to be sampled.
    :return:
    """
    res = arr[:k]  # save first k sample
    i = k
    for v in arr[k:]:
        i += 1
        p = random.random()
        if p < k/i:
            rid = random.randint(0, k-1)  # rid \in [0, k)
            res[rid] = v
    return res


def trial1():
    """ 实验1 """
    arr = list(range(10))
    t = 1000000
    cnt = [0 for _ in range(len(arr))]
    for _ in range(t):  # t rounds of trials
        sample_id = sample(arr)
        cnt[sample_id] += 1

    print("样本被采样到的次数分布 = %s" % cnt)
    print("样本被采样到的次数概率分布 = %s" % (np.array(cnt) / sum(cnt)).tolist())
    print("样本在每轮中被采样到的概率 = %s" % (np.array(cnt) / t).tolist())


def trial2():
    """ 实验2 """
    arr = list(range(10))
    t = 1000000
    cnt = np.zeros(len(arr))
    for _ in range(t):  # t rounds of trials
        sample_id = np.array(sample_k(arr, 3))
        cnt[sample_id] += 1

    print("样本被采样到的次数分布 = %s" % cnt)
    print("样本被采样到的次数概率分布 = %s" % (np.array(cnt) / sum(cnt)).tolist())
    print("样本在每轮中被采样到的概率 = %s" % (np.array(cnt) / t).tolist())


if __name__ == '__main__':
    trial1()
    trial2()
