# ADT: insert and delete
class Node:
    # constructor
    def __init__(self):
        self.data = None
        self.next = None

    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next

    def setData(self, data):
        self.data = data

    def getData(self):
        return self.data

    def setNext(self, nextNode):
        self.next = nextNode

    def getNext(self):
        return self.next

    def hasNext(self):
        return self.next != None 

class LinkedList:
    def __init__(self):
        self.head = None

    def getHead(self):
        return self.head

    def printList(self):
        curr = self.head

        while curr is not None:
            print(curr.getData(), " ", end='')
            curr = curr.getNext()
        print("  Length=%d"% self.getLength())

    def getLength(self):
        # Time: O(n)
        # Space: O(1) : count and curr
        curr = self.head
        count = 0

        while curr:
            count += 1
            curr = curr.getNext()

        return count

    def insertFront(self, data):
        newNode = Node(data)
        #newNode.setData(data)

        if self.head is None:
            self.head = newNode
        else:
            newNode.setNext(self.head)
            self.head = newNode

    def insertBack(self, data):
        newNode = Node(data)
        #newNode.setData(data)

        if self.head is None:
            self.head = newNode
        else:
            curr = self.head
            while curr.getNext() is not None:
                curr = curr.getNext()

            curr.setNext(newNode)

def buildList():
    myList = LinkedList()
    for i in range (1, 5):
        myList.insertBack(i)
        myList.printList()
        

buildList()
