#!/bin/python3

import math
import os
import random
import re
import sys
from collections import deque

#
# Complete the 'minimumMoves' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. STRING_ARRAY grid
#  2. INTEGER startX
#  3. INTEGER startY
#  4. INTEGER goalX
#  5. INTEGER goalY
#

def adjacents(grid, x, y):
    adj = list()
    i = x - 1
    j = y
    while i >= 0 and grid[i][j] != 'X':
        adj.append((i, j))
        i -= 1

    i = x
    j = y - 1  
    while j >= 0 and grid[i][j] != 'X':
        adj.append((i, j))
        j -= 1

    i = x + 1
    j = y
    while i < len(grid) and grid[i][j] != 'X':
        adj.append((i, j))
        i += 1
    
    i = x
    j = y + 1
    while j < len(grid[0]) and grid[i][j] != 'X':
        adj.append((i, j))
        j += 1
        
    return adj

def minimumMoves(grid, startX, startY, goalX, goalY):
    # Write your code here
    q = deque(list())
    x,y = startX, startY
    distTo = list()
    visited = list()
    for _ in range(len(grid)):
        distTo.append([float('inf')] * len(grid[0]))
        visited.append([False] * len(grid[0]))
    
    distTo[startX][startY] = 0
    visited[startX][startY] = True
    q.append((startX, startY)) 
    while (x,y) != (goalX, goalY) and len(q) > 0:
        x, y = q.popleft()
        for w_x, w_y in adjacents(grid, x, y):
            if not visited[w_x][w_y]:
                if distTo[w_x][w_y] > distTo[x][y] + 1:
                    distTo[w_x][w_y] = distTo[x][y] + 1
                q.append((w_x, w_y))
                visited[w_x][w_y] = True        
    return distTo[goalX][goalY]
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    grid = []

    for _ in range(n):
        grid_item = input()
        grid.append(grid_item)

    first_multiple_input = input().rstrip().split()

    startX = int(first_multiple_input[0])

    startY = int(first_multiple_input[1])

    goalX = int(first_multiple_input[2])

    goalY = int(first_multiple_input[3])

    result = minimumMoves(grid, startX, startY, goalX, goalY)

    fptr.write(str(result) + '\n')

    fptr.close()
