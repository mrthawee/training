# Create nodes
# Create linked list
# Add nodes to linked list
# Print linked list

import pdb

class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insertHead(self, newNode):
        newNode.next = self.head
        self.head = newNode

    def insertTail(self, newNode):
        if self.head is None:
            self.head = newNode
        else:
            curr = self.head
            while curr.next is not None:
                curr = curr.next
            curr.next = newNode

    def insertAt(self, newNode, pos):
        if pos == 0:
            self.insertHead(newNode)
        else:
            curr = self.head
            cnt = 0
            while curr is not None:
                if pos == cnt+1:
                    newNode.next = curr.next
                    curr.next = newNode
                    return
                else:
                    curr = curr.next
                    cnt += 1

        print("pos=",pos, "is out of range; length=",cnt)

    # Doesn't work yet
    def insertSort(self, newNode):
        # insert head
        if self.head is None or self.head.data > newNode.data:
            newNode.next = self.head
            self.head = newNode
            return

        # insert middle
        curr = self.head
        while curr.next is not None:
            if curr.next.data >= newNode.data:
                newNode.next = curr.next
                curr.next = newNode
                return
            else:
                curr = curr.next

        # insert tail
        curr.next = newNode


    def printList(self):
        curr = self.head
        elems = []
        while curr is not None:
            elems.append(curr.data)
            # print(curr.data, ' ')
            curr = curr.next
        print(elems)


# Node => data, next

# firsstNode.data => John, firstNode.next => None
firstNode = Node(5)
linkedList = LinkedList()
linkedList.insertTail(firstNode)

secondNode = Node(9)
linkedList.insertTail(secondNode)

thirdNode = Node(15)
linkedList.insertTail(thirdNode)

linkedList.printList()

forthNode = Node(1)
linkedList.insertHead(forthNode)
linkedList.printList()

fifthNode = Node(3)
linkedList.insertAt(fifthNode, 1)
linkedList.printList()

sixthNode = Node(7)
#pdb.set_trace()
linkedList.insertSort(sixthNode)
linkedList.printList()

sevenththNode = Node(99)
#pdb.set_trace()
linkedList.insertSort(sevenththNode)
linkedList.printList()
