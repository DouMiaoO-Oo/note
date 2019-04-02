# -*- coding: utf-8 -*-
# !usr/bin/env python3 
"""
-------------------------------------------------
   File Name:     lab2_PCA
   Description :
   Ref: http://mathreview.uwaterloo.ca/archive/voli/1/panju.pdf
   https://www.physicsforums.com/threads/eigenvalues-eigenvectors-using-householder-and-qr.826016/
   https://www.math.kth.se/na/SF2524/matber15/qrmethod.pdf : QR至少能找到谱半径
   Author :       Yuwei Liu
   date：          2018/5/21
-------------------------------------------------
   Change Activity:
                   2018/5/29:
-------------------------------------------------
"""
import time
import numpy as np
from scipy.io import loadmat
from matplotlib import pyplot
from lab1_QR import qr_algorithm
from scipy.linalg import hessenberg

X = loadmat("yale_face.mat")['X']  # 4096 * 165 读取数据集
n, m = X.shape
# # 可视化一下数据集
# for i in range(m):
#     pyplot.imshow(np.reshape((X[:, i]), newshape=(64, 64), order="F"), cmap='gray')
#     pyplot.pause(5)
#     pyplot.close("all")

# First step: centralized at origin
mu = np.mean(X, axis=1).reshape(-1, 1)
X_tilde = X-mu
sigma = np.dot(X_tilde, np.transpose(X_tilde))/m  # shape=(4,664, 4,664)
# w, v = np.linalg.eig(sigma); np.save("函数找到的特征值w", w); np.save("函数找到的特征vec", v)

# b) Second step: find eigenvalue and eigenvector dot(X^{T}, X)/m
left = np.dot(np.transpose(X_tilde), X_tilde)/m  # shape=(165, 165)
start_time = time.time()  # 计算QR迭代法需要计算的时间
# _, eigenvalue, V = qr_algorithm(left)
# np.save("eigenvalue", eigenvalue);  np.save("V", V)
eigenvalue = np.load("eigenvalue.npy"); V = np.load("V.npy")
D = np.diag(eigenvalue)  # 构造D矩阵， 虽然后面用不到这个矩阵
eigenvector = np.dot(X_tilde, V)  # shape=(4,664, 165) ∑的特征向量

time_span = time.time() - start_time  # 136.11510396003723秒
print("没有转化为 Hessenberg matrix之前, 计算QR迭代需要%s秒" % time_span)
K = 5  # 取出前5个最大的特征值
indices = np.argsort([abs(ev) for ev in eigenvalue])[::-1]
print("找到的前K个最大特征值对应的列下标为: ", indices[:K])
print("找到的前K个最大特征值为: ", eigenvalue[indices[:K]])

for i in indices[:K]:
    x = eigenvector[:, i]
    # 可视化一下数据集
    pyplot.imshow(np.reshape(x, newshape=(64, 64), order="F"), cmap='gray')
    pyplot.pause(5)
    pyplot.savefig("./图片/特征向量可视化_%s.jpg" % i)
    pyplot.close("all")

# c) Convert dot(X^{T}, X)/m to Hessenberg before QR algorithm
H, P = hessenberg(left, calc_q=True)  # A = PHP^T
start_time = time.time()  # 计算QR迭代法需要计算的时间
#_, eigenvalue, V = qr_algorithm(H)  # X^{t}X的特征向量和对应的特征值
time_span = time.time() - start_time  # 33.80924034118652秒
print("转化为 Hessenberg matrix之后, 计算QR迭代需要%s秒" % time_span)
#np.save("eigenvalue_H", eigenvalue); np.save("V_H", V)
eigenvalue = np.load("eigenvalue_H.npy"); V = np.load("V_H.npy")
eigenvector = np.dot(X_tilde, np.dot(P, V))  # shape=(4,664, 165) ∑的特征向量, 通过P映射V矩阵得到
indices = np.argsort([abs(ev) for ev in eigenvalue])[::-1]
print("找到的前K个最大特征值对应的列下标为: ", indices[:K])
print("找到的前K个最大特征值为: ", eigenvalue[indices[:K]])

for i in indices[:K]:
    x = eigenvector[:, i]
    # 可视化一下数据集
    pyplot.imshow(np.reshape(x, newshape=(64, 64), order="F"), cmap='gray')
    pyplot.pause(5)
    pyplot.savefig("./图片/特征向量可视化H_%s.jpg" % i)
    pyplot.close("all")
