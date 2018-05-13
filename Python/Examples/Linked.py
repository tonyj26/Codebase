class Linked(object):
    # init
    def __init__(self):
        self.head = None
        self.tail = None

    def add(self, data):
        temp = Node(data, None, None)
        if (self.head is None):
            self.head = temp
            self.tail = temp
        else:
            self.tail.setAfter(temp)
            temp.setBefore(self.tail)
            self.tail = temp

    def find(self, data):
        if (self.head is None):
            return "Empty List"
        else:
            current = self.head
            while (current is not None):
                if (current.element() is data):
                    return current
                current = current.next()
        return "Element not in List"

    def remove(self, data):
        if (self.head is None):
            return "Empty List"
        elif(self.find(data).element() is data):
            temp = self.find(data)
            if (temp is self.head and temp is self.tail):
                self.head = None
                self.tail = None
            elif (temp is self.head):
                self.head = temp.next()
                self.head.setBefore(None)
                return
            elif (temp is self.tail):
                temp.before.setAfter(None)
                return
            else:
                temp.before.setAfter(temp.after)
                temp.after.setBefore(temp.before)

    def iterator(self):
        if (self.head is None):
            return "Empty List"
        else:
            current = self.head
            while (current is not None):
                print(current.element())
                current = current.next()


class Node(object):
    # init
    def __init__(self, data=None, before=None, after=None):
        self.data = data
        self.before = before
        self.after = after

    def element(self):
        return self.data

    def setBefore(self, before):
        self.before = before

    def setAfter(self, after):
        self.after = after

    def next(self):
        return self.after
