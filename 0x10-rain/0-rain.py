#!/usr/bin/python3
"""
Rain
"""


def rain(walls):
    """calculate how much water will be
       retained after it rains
    """
    if len(walls) == 0:
        return 0

    max_water = 0

    for n in range(len(walls)):
        max_left = walls[n]
        for num in range(n):
            max_left = max(max_left, walls[num])
        max_right = walls[n]
        for num in range(n + 1, len(walls)):
            max_right = max(max_right, walls[num])

        max_water = max_water + (min(max_left, max_right) - walls[n])

    return max_water