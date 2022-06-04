#!/usr/bin/python3
""" script that reads stdin line by line and computes metrics """
import sys

count = 0
all_file_size = 0
all_status = {}

for line in sys.stdin:

    """breaking up the input to check format"""

    details = line.split(" ", 2)
    more_details = details[2].split("]", 1)
    details.insert(2, more_details[0])
    more_details = more_details[1].split('"', 2)
    details.insert(3, more_details[1])
    more_details = more_details[2].split(" ", 2)
    details.insert(4, more_details[1])
    more_details = more_details[2].split("\n")
    details[-1] = more_details[0]

    """ check if the input is correct """ 
    if len(details) == 6:
        posible_status = [200, 301, 400, 401, 403, 404, 405, 500]
        file_size = int(details[-1])
        all_file_size += file_size
        status = int(details[-2])
        if (status in posible_status):
            if (status in all_status.keys()):
                all_status[status] += 1
            else:
                all_status[status] = 1

        count += 1
        if (count == 10):
            print("File size: {:d}".format(all_file_size))
            status_items = all_status.items()
            sorted_status = sorted(status_items)
            for item in sorted_status:
                print("{}: {}".format(item[0], item[1]))
            count = 0

