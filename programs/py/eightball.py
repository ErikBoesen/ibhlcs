import random
while True:
    q = input('Enter your question: ')
    total = sum([ord(c) for c in q])
    random.choice(['Yes', 'No', 'It is unlikely', 'Long shot'])
