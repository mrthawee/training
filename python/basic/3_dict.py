import random
import sys
import os

D = {'Ford': 'AAAA BBB',
     'John': 'XYZ 123',
     'Bill': 'Sam Scudder' }

print(D)
print(D['Ford'])

del D['John']
print(D)
D['Bill'] = 'Robert Gates'
print(D)
print(D.keys())
print(D.values())
