class LinkedList(object):
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def append(self, data):

        node = Node(data, None, None)
        if self.head is None:
            self.head = self.tail = node
        else:
            node.setPrev(self.tail)
            node.setNext(None)
            self.tail.next = node
            self.tail = node
        self.size = self.size + 1

    def remove(self, val):
        cur = self.head
        while cur is not None:
            if cur.getVal() == val:
                if cur.getPrev() is not None:
                    cur.getPrev().setNext(cure.getNext())
                    cur.getNext().setPrev(cur.getPrev())
                    self.size = self.size - 1
                elif cur.getPrev() is None  and cur.getNext() is None:
                    self.head = self.tail = None
                else:
                    self.head = cur.getNext()
                    cur.getNext().setPrev(None)

            cur = cur.next
            

    def show(self):
        print("Show list data: ")
        current = self.head

        while current is not None:
            print(current.getVal())
            current = current.next

    def getSize(self):
        return print("Size is: ", self.size)


class Node(object):
    def __init__(self, data, prev, next):
        self.data = data
        self.prev = prev
        self.next = next

    def getVal(self):
        return self.data

    def getNext(self):
        return self.next

    def getPrev(self):
        return self.prev

    def setPrev(self, newPrev):
        self.prev = newPrev

    def setVal(self, newVal):
        self.val = newVal

    def setNext(self, newNext):
        self.next = newNext

d = LinkedList()

d.append(1)
d.append(2)
d.append(6)
d.getSize()
d.show()

d.remove(1)
d.remove(2)
d.remove(6)
d.getSize()
d.remove(50)

d.show()
