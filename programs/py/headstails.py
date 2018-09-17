import random

HEADS, TAILS = True, False

RED  = (HEADS, TAILS)
BLUE = (TAILS, HEADS)

red_wins = 0
blue_wins = 0

red = None
blue = None
while True:
    red_win = False
    blue_win = False
    p_red = red
    p_blue = blue
    red = random.choice((HEADS, TAILS))
    blue = random.choice((HEADS, TAILS))

    if RED == (p_red, red):
        red_win = True
    if BLUE == (p_blue, blue):
        blue_win = True

    if red_win and not blue_win:
        if red_win:
            print('Red')
    elif blue_win and not red_win:

    else:
        print('None')
    red_win, blue_win = False, False

