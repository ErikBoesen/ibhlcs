def euclid(a, b):
    r = a % b
    multiplier = (a - r) // b
    print(f'{a} = {b} * {multiplier} + {r}')
    if r != 0:
        euclid(b, r)

a = int(input("a: "))
b = int(input("b: "))
if b > a:
    a, b = b, a

euclid(a, b)
