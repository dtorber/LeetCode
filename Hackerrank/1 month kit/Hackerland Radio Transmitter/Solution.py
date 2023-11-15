#!/bin/python3

import math
import os
import random
import re
import sys
import heapq

#
# Complete the 'hackerlandRadioTransmitters' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY x
#  2. INTEGER k
#

def hackerlandRadioTransmitters(x, k):
    # Write your code here
    existent_houses = set()
    coverage = list()
    heapq.heapify(coverage)

    max_house = 0
    for house in x:
        existent_houses.add(house)
        if house > max_house:
            max_house = house

    for house in x:
        actual_coverage = list()
        for i in range(max(0, house - k), min(house + k, max_house) + 1):
            if i in existent_houses and house != i:
                actual_coverage.append(i)
        if len(actual_coverage) > 0: heapq.heappush(coverage, (-len(actual_coverage), house, actual_coverage))

    cobertes = set()
    contador = 0
    
    while len(cobertes) < len(x) and len(coverage) > 0:
        _, house, actual_cobertes = heapq.heappop(coverage)
        if house in cobertes: continue
        alguna_coberta = False
        for coberta in actual_cobertes:
            if coberta not in cobertes:
                cobertes.add(coberta)
                alguna_coberta = True
        if alguna_coberta:
            cobertes.add(house)
            contador += 1
            nou_coverage = list()
            for i in range(len(coverage)):
                nova_cobertura = list()
                _, idx, cobertura = coverage[i]
                for cobert in cobertura:
                    if cobert not in cobertes:
                        nova_cobertura.append(cobert)

                if len(nova_cobertura) > 0: nou_coverage.append((-len(nova_cobertura), idx, nova_cobertura))

            coverage = nou_coverage
            heapq.heapify(coverage)


    if len(cobertes) < len(x):
        #si faltava alguna per estar coberta directament li posem una antena en eixa casa
        contador += len(x) - len(cobertes)

    return contador


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    k = int(first_multiple_input[1])

    x = list(map(int, input().rstrip().split()))

    result = hackerlandRadioTransmitters(x, k)

    fptr.write(str(result) + '\n')

    fptr.close()
