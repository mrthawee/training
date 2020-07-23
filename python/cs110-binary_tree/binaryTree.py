from collections import deque

'''
class Node:
    def __init__(self, data=None, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

    def print(self):
        print(self.data)
'''

# since every node is a tree, so we need only class Tree
class Tree:
    def __init__(self, data=None, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

    def insert(self, data):
        if self.data is None:
            self.data = data
        else:
            if data < self.data:
                if self.left:
                    self.left.insert(data)
                else:
                    self.left = Tree(data)
            elif data > self.data:
                if self.right:
                    self.right.insert(data)
                else:
                    self.right = Tree(data)

    def print(self):
        if self.left:
            self.left.print()

        print(self.data)

        if self.right:
            self.right.print()

    '''
    def print(self):
        curr = self.root

        level = 0

        q = []
        q.append(self.root)

        while len(q):
            print("level %d" % level)
            for i in len(q):
                curr = q[0]
                del q[0]
                print("%d " % curr.data, end='') 
                if curr.left:
                    q.append(curr.left)
                if curr.right:
                    q.append(curr.right)
            level += 1
    '''

t = Tree(3)
t.print()

t.insert(1)
t.insert(2)
t.insert(4)
t.print()
