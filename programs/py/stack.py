import math

class Stack:
    items = []
    def __len__(self):
        return len(self.items)
    def push(self, item):
        self.items.append(item)
    def pop(self):
        return self.items.pop()

s = Stack()
s.push(3)
s.push(4)
s.push(5)

print(s.pop())
print(len(s))

