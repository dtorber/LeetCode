#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'plusMinus' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def plusMinus(arr):
    # Write your code here
    pos, neg, ze = 0, 0, 0
    for val in arr:
        if val < 0: 
            neg += 1
        elif val > 0:
            pos += 1
        else:
            ze += 1
    print("{:.6f}".format(pos / len(arr)))
    print("{:.6f}".format(neg / len(arr)))
    print("{:.6f}".format(ze / len(arr)))

if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
