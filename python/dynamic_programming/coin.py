#!/bin/python3

import math
import os
import random
import re
import sys

def min_coins(coins, val):
    print("coins = ", coins)
    print("val = ", val)
    dp = [0] * (val + 1)
    dp[0] = 0
    print(dp)
    for  i in range (1,val+1):
        minV = math.inf
        for c in coins:
            if i >= c:
                #print("i=%d c=%d " % (i,c))
                ##print("dpi=",dp[i]," dpi-c=",dp[i-c])
                minV = min(minV, dp[i-c])
                print('i=%d c=%d minV=%d'%(i,c,minV))
        dp[i] = 1 + minV
        #print('i=%d dp[i]=%d'%(i,dp[i]))
        print('i=',i,' dp=', dp)
    return dp[val]

if __name__ == '__main__':
    n = int(input().strip())
    coins = []
    
    for _ in range(n):
        coins.append(int(input().strip()))

    val = int(input().strip())

    fptr = sys.stdout

    result = min_coins(coins, val)

    fptr.write(str(result))
    print('')
    fptr.close()
