import random
from termcolor import colored

NUM_DOORS = 3
CAR = True
ZONK = False
OPEN = True
CLOSED = False


class Hall:

    def __init__(self):
        self.contents = [ZONK] * NUM_DOORS
        self.car_position = self.random_door()
        self.contents[self.car_position] = CAR
        self.statuses = [CLOSED] * NUM_DOORS

    def random_door(self) -> int:
        return random.randint(0, NUM_DOORS - 1)

    def choose_random(self) -> bool:
        self.guess = self.random_door()

    def open_zonk(self):
        for door in range(NUM_DOORS):
            if door != self.guess and self.contents[door] != CAR:
                self.statuses[door] = OPEN
                break

    def is_swap_correct(self):
        return self.car_position != self.guess


successes = 0
tries = 0

while True:
    hall = Hall()
    hall.choose_random()
    hall.open_zonk()
    if hall.is_swap_correct():
        successes += 1
    tries += 1
    print("\r%s/%s: %.5f%%" % (colored(successes, 'green'), colored(tries, 'cyan'), 100 * successes / tries), end="")
