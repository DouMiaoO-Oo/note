#!/usr/bin/env python3
# _*_coding:utf-8_*_
import random


def get_array(m, n):
    return [[0 for i in range(n)] for j in range(m)]


""" 《统计学习方法》 HMM """
A = [[0.5, 0.2, 0.3],
     [0.3, 0.5, 0.2],
     [0.2, 0.3, 0.5],
     ]
B = [[0.5, 0.5],
     [0.4, 0.6],
     [0.7, 0.3],
     ]
pi = [0.2, 0.4, 0.4]
# lambda = (A, B, pi)
N = 3  # 状态个数
M = 2  # 可能的观测数
O = [0, 1, 0]  # 红白红
T = len(O)
beta = get_array(T, N)  # beta[t][i]: 在时刻t的状态为i,并且 O_{t+1},O_{t+2}, ..., O_{T} 于 O 中的观测一致
# step 1: 初始化 规定β[T-1][:] = 1
for i in range(N):
    beta[T-1][i] = 1
# step 2: 递推
for t in range(T-2, -1, -1):  # [T-1, 0]
    for i in range(N):
        for j in range(N):
            beta[t][i] += A[i][j]*B[j][O[t+1]]*beta[t+1][j]
# step 3:
res = 0  # P(O|lambda)
for i in range(N):
    res += pi[i]* B[i][O[0]] * beta[0][i]

print("P(O|λ) = %.5f" % res)
