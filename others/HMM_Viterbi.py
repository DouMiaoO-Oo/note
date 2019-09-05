#!/usr/bin/env python3
# _*_coding:utf-8_*_
# ref: 《统计学习方法》

import numpy as np


def viterbi(A, B, pi, O):
    """
    :param A: state to state transition matrix, A[i][j] is p(j|i)
    :param B: state to observation transition matrix, B[i][j] is p(O_j|i)
    :param pi: initial state distribution matrix
    :param O: Observation sequence.
    :return:
    """
    state_seq = []
    A = np.array(A)
    B = np.array(B)
    pi = np.array(pi)
    O = np.array(O)
    N, M = B.shape  # N: #state, M: #observation
    T = len(O)  # length of observation sequence
    delta = np.zeros(shape=(N, T))  # δ
    psi = np.zeros(shape=(N, T), dtype=int)  # ψ, ψ[i][t] = argmax_{j} = {δ[j][t-1]*A[j][i]}
    # first step:
    delta[:, 0] = pi*B[:, O[0]]  # (pi*B[:, O[0]]).shape = (N, )
    # print(delta)

    # second step
    for t in range(1, T):
        pass
        obsrv = O[t]  # observation of time t
        for i in range(N):  # 这里还能向量化么？
            tmp = delta[:, t-1]*A[:, i]
            psi[i, t] = np.argmax(tmp)
            delta[i, t] = tmp[psi[i, t]]  # max(delta[:, t-1]*A[:, obsrv])
        delta[:, t] = delta[:, t] * B[:, obsrv]  # generate observation from current state
    state_seq.append(np.argmax(delta[:, -1]))  # np.argmax(delta[:, T-1])
    for t in range(T-1, 0, -1):
        best_state = state_seq[-1]
        state_seq.append(psi[best_state, t])
    state_seq.reverse()
    print(delta)
    return state_seq


def main():
    A = [[0.5, 0.2, 0.3],
         [0.3, 0.5, 0.2],
         [0.2, 0.3, 0.5]]
    B = [[0.5, 0.5],
         [0.4, 0.6],
         [0.7, 0.3],
         ]
    pi = [0.2, 0.4, 0.4]
    O = [0, 1, 0]  # 红白红
    state_seq = viterbi(A, B, pi, O)
    print(state_seq)


if __name__ == '__main__':
    main()
