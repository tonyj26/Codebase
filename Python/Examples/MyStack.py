

class MyStack:
    def __init__(self):
        self.stack = []

    def push(self, item):
        self.stack.append(item)

    def pop(self):
        return self.stack.pop()

    def isEmpty(self):
        return self.stack == []

    def peek(self):
        return self.stack[len(self.stack)-1]

    def size(self):
        return len(self.stack)
