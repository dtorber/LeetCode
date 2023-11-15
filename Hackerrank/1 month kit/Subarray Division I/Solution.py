#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'birthday' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY s
#  2. INTEGER d
#  3. INTEGER m
#

def birthday(s, d, m):
    # Write your code here
    if len(s) < m: return 0
    cont = 0
    acc = 0
    for i in range(m):
        acc += s[i]
    if acc == d:
        cont += 1
    i += 1
    while i < len(s):
        acc = acc - s[i - m] + s[i]
        if acc == d:
            cont += 1
        i += 1
    return cont

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    s = list(map(int, input().rstrip().split()))

    first_multiple_input = input().rstrip().split()

    d = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    result = birthday(s, d, m)

    fptr.write(str(result) + '\n')

    fptr.close()
