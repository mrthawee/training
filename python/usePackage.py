# How to create a Python package and use it
# http://www.blog.pythonlibrary.org/2012/07/08/python-201-creating-modules-and-packages/
import sys

sys.path.append('.')

import myMath

print myMath.add(4,5)
print myMath.div(4,2)
print myMath.mul(10,5)
print myMath.fibonacci(8)
print myMath.squareroot(48)
