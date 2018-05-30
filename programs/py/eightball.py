ANSWERS = ['Yes', 'No', 'It is unlikely', 'Long shot']
while True:
    q = input('Enter your question: ')
    total = sum([ord(c) for c in q])
    print(ANSWERS[total % len(ANSWERS)])
