import random
import sys
import os

def addNumber(fNum, lNum):
    sumNum = fNum + lNum
    return sumNum

print(addNumber(1, 4))

s = addNumber(3, 10)
print(s)

print('What is your name?')
name = sys.stdin.readline()
print('Hello', name)
        
