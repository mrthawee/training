from node import Node
from node import LinkedList

n = Node(3)
n.print()

l =LinkedList(n)  # LinkedList(node) NOT LinkedList(data)
l.print()
'''
l.length()
l.insertFront(2)
l.print()
print("NumNodes with data=%d is %d" % (5, l.count(5)))
print("GetNth for n=%d got %d" % (1, l.getNth(1)))
print("GetNth for n=10 got", l.getNth(10))
l.print()
l.deleteFront()
l.print()
l.deleteList()
l.print()
'''

l.insertFront(2)
l.insertFront(1)
print("before insertNth()")
l.print()
l.insertNth(0, 10)
print("after insertNth(0,10)")
l.print()

