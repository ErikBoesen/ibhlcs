max_length = 0
longest_number = None

def collatz(number: int) -> int:
    if number == 1:
        return 1
    elif number % 2 == 0:
        return 1 + collatz(number / 2)
    else:
        return 1 + collatz(3 * number + 1)

for i in range(1, 1_000_000):
    length = collatz(i)
    if length > max_length:
        max_length = length
        longest_number = i
        print(f"{i} -> {length}")

print(f"{longest_number} has the longest chain, with a length of {max_length}.")

