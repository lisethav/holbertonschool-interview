#!/usr/bin/python3
"""valid UTF-8"""


def validUTF8(data):
    """
    module doc
    """

    b1 = 1 << 7
    b2 = 1 << 6
    nb = 0

    if not data or len(data) == 0:
        return True

    for numero in data:
        bite = 1 << 7
        if nb == 0:
            while (bite & numero):
                nb += 1
                bite = bite >> 1

            if nb == 0:
                continue
            if nb == 1 or nb > 4:
                return False
        else:

            if not (numero & b1 and not (numero & b2)):
                return False
        nb -= 1

    if nb:
        return False
    else:
        return True
