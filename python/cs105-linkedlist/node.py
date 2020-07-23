import math

class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next

    def print(self):
        print(self.data)

class LinkedList:
    def __init__(self, node=None):
        self.head = node

    def print(self):
        curr = self.head

        print("List: ", end='')
        while curr:
            print(curr.data, " ", end='')
            curr = curr.next
        print("\n")

    def length(self):
        count = 0
        curr = self.head
        while curr:
            count += 1
            curr = curr.next
        print("Length = %d" % count)

    def insertFront(self, data):
        newNode = Node(data)
        newNode.next = self.head
        self.head = newNode

    # prob 1: count node with self.data is 'data'
    def count(self, data):
        curr = self.head

        count = 0
        while curr:
            if curr.data == data:
                count += 1
            curr = curr.next

        return count

    # prob 2: get Nth node start from 0th
    def getNth(self, n):
        i = 0

        curr = self.head
        while curr and i<n:
            i += 1
            curr = curr.next

        if curr:
            return i
        else:
            return "not found"

    # prob 3: delete list
    def deleteList(self):
        curr = self.head

        while curr:
            next_node = curr.next
            curr.data = None
            curr.next = None
            curr = next_node

    # prob 4: pop - delete front
    def deleteFront(self):
        curr = self.head

        self.head.data = None
        self.head.next = curr.next

    # prob 5: insert Nth
    def insertNth(self, n, data): # position Nth from 0th with node.data = data
        newNode = Node(data)

        prev = Node()
        curr = self.head
        count = 0

        if n == 0:
            newNode.next = self.head
            self.head = newNode
            return 

        while count < n and curr:
            prev = curr
            curr = curr.next
            count += 1

        if count == n:
            prev.next = newNode
            newNode.next = curr

