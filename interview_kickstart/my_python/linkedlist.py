class node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class linkedlist:
    def __init__(self):
        self.head = node()

    def append(self, data):
        new_node = node(data)
        curr = self.head

        while curr.next != None:
            curr = curr.next

        curr.next = new_node

    def length(self):
        curr = self.head
        cnt = 0

        while curr.next != None:
            cnt += 1
            curr = curr.next

        return cnt

    def display(self):
        elems = []
        curr = self.head

        while curr.next != None:
            curr = curr.next
            elems.append(curr.data)

        print(elems)

    def get(self, index):
        curr_index = 0
        curr = self.head
        while curr.next != None:
            curr = curr.next
            if curr_index == index:
                return curr.data
            curr_index += 1

        return None

    def erase(self, index):
        curr_index = 0
        curr = self.head
        while curr.next != None:
            tmp = curr
            curr = curr.next
            if curr_index == index:
                tmp.next = curr.next
                return curr.data
            curr_index += 1

        return None



my_list = linkedlist()
my_list.display()
my_list.append(1)
my_list.append(2)
my_list.append(3)
my_list.append(4)
my_list.display()

n = 2
print("Get @ index =",n,"got",my_list.get(2))

val = my_list.erase(n)
print("erase val =",val)
my_list.display()
