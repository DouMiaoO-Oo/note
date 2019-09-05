#!/usr/bin/env python3
# _*_coding:utf-8_*_
import random


def get_array(m, n):
    return [[0 for i in range(n)] for j in range(m)]


""" 《统计学习方法》 HMM """
A = [[0, 1, 0, 0],
     [0.4, 0, 0.6, 0],
     [0, 0.4, 0, 0.6],
     [0, 0, 0.5, 0.5]
     ]
B = [[0.5, 0.5],
     [0.3, 0.7],
     [0.6, 0.4],
     [0.8, 0.2]
     ]
pi = [0.25, 0.25, 0.25, 0.25]
# lambda = (A, B, pi)
N = 4  # 状态个数

#"""  # P177页
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

#"""

M = 2  # 可能的观测数
O = [0, 1, 0]  # 红白红
T = len(O)
alpha = get_array(T, N)  # alpha[t][i]: 在时刻t的状态为i,并且 O_{1}, ..., O_{t} 于 O 中的观测一致
# step 1: 初始化
for i in range(N):
    alpha[0][i] = pi[i] * B[i][O[0]]
print(alpha[0][0], alpha[0][1], alpha[0][2])
# step 2: 递推
for t in range(1, T):
    for i in range(N):
        for j in range(N):
            alpha[t][i] += alpha[t-1][j]*A[j][i]*B[i][O[t]]
# step 3:
res = 0  # P(O|lambda)
for i in range(N):
    res += alpha[T-1][i]

print("P(O|λ) = %.5f" % res)
