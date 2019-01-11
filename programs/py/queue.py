class Queue:
    items = []
    def __len__(self):
        return len(self.items)
    def enqueue(self, item):
        self.items.append(item)
    def dequeue(self):
        return self.items.pop(0)

q = Queue()
q.enqueue(3)
q.enqueue(4)
q.enqueue(5)

print(q.dequeue())
print(len(q))
