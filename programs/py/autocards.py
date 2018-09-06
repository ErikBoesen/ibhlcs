import random

wins   = 0
losses = 0

game = 0
while True:
    print('-' * 2 + f' Game {game} ' + '-' * 15)
    cards = list(range(2, 10+1))
    old = random.choice(cards)
    while len(cards) > 1:
        new = random.choice(cards)
        print(cards)
        print(f'Card: {old}')
        print(f'Next: {new}')
        print(f'Position in list: {cards.index(old) + 1}/{len(cards)}')
        guess = (cards.index(old) + 1 < len(cards) / 2)
        print('Guess: ' + ('higher' if guess else 'lower'))
        cards.remove(old)
        if guess and new > old or (not guess) and new < old:
            print('Correct.')
            old = new
        else:
            print('Incorrect.')
            losses += 1
            break
    if not cards:
        print('You win!')
        wins += 1

    game += 1
    print(f'Wins:   {wins}')
    print(f'Losses: {losses}')
    print(f'Record: {100 * (wins / (wins+losses))}')
    print()
