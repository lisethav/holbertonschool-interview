#!/usr/bin/python3
""" 0. Minimum Operations"""


from copy import copy
from itertools import count


def minOperations(n):
    if not isinstance(n, int) or n <= 1:
        return 0
    init = 1  # characters in the text file start always in 1
    count = 0
    while (init < n):
        rest = n - init

        if (rest % init == 0):
            clipBoard = init
            init += clipBoard
            count += 2
        else:
            init += clipBoard
            count = count + 1

    return (count)


def minimumSpanning(n, init, clipBoard, action, opt):
    """
   find the shortest
    """

    if init == n:
        return opt
    elif init > n:
        return 0

    if action == "CopyPaste":
        clipBoard = init
        init += clipBoard
        opt += 2
    elif action == "Paste":
        init += clipBoard
        opt += 1

    copy = minimumSpanning(n, init, clipBoard, "CopyPaste", opt)
    page = minimumSpanning(n, init, clipBoard, "Paste", opt)

    if (copy != 0 and page != 0 and copy <= page) or (
         copy != 0 and page == 0):
        return copy
    elif (copy != 0 and page != 0 and page <= copy) or (
         copy == 0 and page != 0):
        return page
    else:
        return 0
