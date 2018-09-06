import random

cards = list(range(2, 10+1))
print(cards)
choice = random.choice(cards)
while cards:
    new = random.choice(cards)
    print(f'Card: {choice}')
    print(f'New card: {new}')  # debug
    print(cards)
    response = input(f'Is the next card less (<) or greater (>) than {choice}? ')
    if response == '>' and new > choice or response == '<' and new < choice:
        print('Correct.')
        choice = new
        cards.remove(choice)
    else:
        print('Incorrect.')
        break
if not cards:
    print('You win!')
