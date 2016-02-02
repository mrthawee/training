# Filename arithmetic.py

def add(x, y):
   return x + y

def sub(x, y):
   return x - y

def mul(x, y):
   return x * y

def div(x, y):
   return x / y

if __name__ == "__main__":
   import sys
   print sys.argv
   v = sys.argv[1].lower()
   x = int(sys.argv[2])
   y = int(sys.argv[3])
   if v == "a":
      print add(x, y)
   elif v == 'd':
      print div(x, y)
   elif v == 's':
      print sub(x, y)
   elif v == 'm':
      print mul(x, y)
   else:
      pass
