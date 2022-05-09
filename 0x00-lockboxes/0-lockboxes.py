#!/usr/bin/python3
"""0. Lockboxes"""


def canUnlockAll(boxes):
    """method that determines if all the boxes can be opened."""
    key_list = boxes[0].copy()
    true_keys = [0]
    len_box = len(boxes) - 1

    for id, key in enumerate(key_list):
        if key > len_box:
            continue
        else:
            for x in boxes[key]:
                if x not in key_list:
                    if x <= len_box:
                        key_list.append(x)
            if key not in true_keys:
                true_keys.append(key)

    return len(true_keys) == len(boxes)
