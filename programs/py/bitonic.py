def compare(x, up):
    d = len(x) // 2
    for i in range(d):
        if (x[i] > x[i + d]) == up:
            x[i], x[i + d] = x[i + d], x[i]


def merge(x, up):
    if len(x) == 1:
        return x
    else:
        compare(x, up)
        left = merge(x[:len(x) // 2], up)
        right = merge(x[len(x) // 2:], up)
        return left + right


def sort(x, up=True):
    """
    Put list in order using Bitonic sort.

    :param x: List to sort.
    :param up: Put list in ascending order?
    """
    if len(x) <= 1:
        return x
    else:
        left = sort(x[:len(x) // 2], True)
        right = sort(x[len(x) // 2:], False)
        return merge(left + right, up)


print(sort([58, 3, 2000, 20, 24, 3]))
