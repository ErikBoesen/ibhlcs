def col(x):
    if x == 1:
        print(int(x))
        return
    else:
        print('%d, ' % x, end='')
    if x % 2 == 0:
        col(x / 2)
    else:
        col(3 * x + 1)

col(100)
