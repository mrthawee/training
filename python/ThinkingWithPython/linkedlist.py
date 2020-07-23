class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next

class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data):
        newNode = Node(data)

        if self.head is None:
            self.head = newNode
        else:
            curr = self.head
            while curr.next is not None:
                curr = curr.next
            curr.next = newNode

    def print(self):
        curr = self.head
        while curr:
            print(curr.data, " ", end='')
            curr = curr.next

        print("\n")


LL = LinkedList()
for i in range(5):
    LL.insert(i)

LL.print()
