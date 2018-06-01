answers = []
questions = ['Female Celebrity', 'Male Celebrity', 'Profession', 'Plural Noun', 'Adjective', 'Plural Noun', 'Adjective', 'Field of Study', 'Person', 'Country', 'Field of Study', 'Noun', 'Plural Profession']
story = """Albert Einstein, the son of %s and %s,
was born in Ulm, Germany, in 1879. In 1902, he had a job
as assistant %s in the Swiss patent office and attended
the University of Zurich. There he began studying atoms, molecules,
and %s. He developed the theory of
%s relativity, which expanded the phenomena of sub-atomic
%s and %s magnetism. In 1921,
he won the Nobel prize for %s and was director of
theoretical physics at the %s University in Berlin.
In 1933, when Hitler became Chancellor of %s,
Einstein came to America to take a post at Princeton Institute for
%s, where his theories helped America devise the first
atomic %s. There is no question about it: Einstein was
one of the most brilliant %s of our time."""

for q in questions:
    answers.append(str(input(q + ': ')))
print('-' * 20)
print(story % tuple(answers))
