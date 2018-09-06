import random

cards = list(range(2, 10+1))
random.shuffle(cards)
print(cards)
old = random.choice(cards)
while len(cards) > 1:
    cards.remove(old)
    new = random.choice(cards)
    print(f'Card: {old}')
    print(cards)
    guess = input(f'Is the next card less (<) or greater (>) than {old}? ')
    if guess == '>' and new > old or guess == '<' and new < old:
        print('Correct.')
        old = new
    else:
        print('Incorrect.')
        break
if not cards:
    print('You win!')
