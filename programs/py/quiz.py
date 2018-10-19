NUM_QUESTIONS = 5

questions = (
    'Are Connor and Brendan the same person, moving between two positions so quickly as to trick the eye into believing there are two Fletchalls',
    'Does James sleep with his 12-inch MacBook under the pillow',
    'Are expletives more than 20% of Chris Deng\'s vocabulary',
    'Is Nikita secretly premier of a Soviet Government-in-exile',
    'Does Chris Kim secretly not know what Soh-Cah-Toa means, but has been hiding it for years because he\'s embarassed to ask about it at this point',
)
answers = [
    True
] * NUM_QUESTIONS

def parse(response: str) -> bool:
    return (response.lower()[0] in ('t', 'y'))

correct = 0
for q, a in zip(questions, answers):
    if (parse(input(q + '? (T/F) ')) == a):
        print('Correct!')
        correct += 1
    else:
        print('Incorrect!')

print(f'Result: {correct}/{NUM_QUESTIONS}')
