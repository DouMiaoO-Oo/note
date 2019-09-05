#!/usr/bin/env python3
# _*_coding:utf-8_*_
from collections import Counter
import numpy as np


class Dice:
    def __init__(self, p):
        self.__p = p

    def __toss(self):
        """
        使用Dice抛掷一次
        :return:
        """
        return np.random.choice([1, 0], p=[self.__p, 1-self.__p])  # sample 1 with probability p

    def toss(self):
        """
        使用合理的两次抛掷作为正反面的结果
        :return:
        """
        first, second = self.__toss(), self.__toss()
        while first == second:  # 拒绝采样
            first, second = self.__toss(), self.__toss()
        if first == 0:
            return 1
        return 0


def trial():
    t = 100000  # times of trials
    p_of_head = 0.3
    cnt = np.zeros(2)
    dice = Dice(p_of_head)
    for _ in range(t):
        res = dice.toss()
        cnt[res] += 1
    print(cnt)


if __name__ == '__main__':
    trial()
