string = input('Input sentence: ').lower()
frequencies = {}
for c in string:
    if frequencies.get(c):
        frequencies[c] += 1
    else:
        frequencies[c] = 1
print(frequencies)

##########################################

class Leaf:
    left: Leaf = None
    right: Leaf = None
    value = None
    frequency = None
    def __init__(self, value, frequency):
        self.value = value
        self.frequency = frequency

##########################################

def get_minimum(dictionary):
    return min(dictionary, key=dictionary.get)

left = get_minimum(frequencies)
right = get_minimum(frequencies)
root = Leaf(None, )
while len(frequencies) > 0:

    get_minimum(frequencies)
