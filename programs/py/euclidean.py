import sys

def euclid(a, b):
    multiplier = 0
    while (multiplier + 1) * b <= a:
        multiplier += 1
    r = a - multiplier * b
    print(f'{a} = {b} * {multiplier} + {r}')
    if r != 0:
        euclid(b, r)

a = int(input("a: "))
b = int(input("b: "))
if b > a:
    a, b = b, a

euclid(a, b)
