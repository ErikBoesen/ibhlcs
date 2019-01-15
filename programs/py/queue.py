import math

class Queue:
    items = []
    def __len__(self):
        return len(self.items)
    def is_prime(self, x: int):
        for i in range(2, int(math.sqrt(x)) + 1):
            if x % i == 0:
                return False
        return True
    def enqueue(self, item):
        if self.is_prime(item):
            self.items.append(item)
            return True
        return False
    def dequeue(self):
        return self.items.pop(0)

q = Queue()
print(q.enqueue(3))
print(q.enqueue(4))
print(q.enqueue(5))

print(q.dequeue())
print(len(q))
