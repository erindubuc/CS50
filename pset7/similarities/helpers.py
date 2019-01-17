from nltk.tokenize import sent_tokenize

# sets are unordered collections with no duplicate elements

def lines(a, b):
    """Return lines in both a and b"""

    # split each string into lines
    lines_a = set(a.splitlines())
    print(lines_a)
    lines_b = set(b.splitlines())
    print(lines_b)

    # return the list
    return lines_a & lines_b


def sentences(a, b):
    """Return sentences in both a and b"""

    sentences_a = set(sent_tokenize(a, language='english'))
    sentences_b = set(sent_tokenize(b, language='english'))
    print(sentences_a)
    print(sentences_b)

    return sentences_a & sentences_b


# Extract substrings from string in a and b
def get_substrings(str, n):
    substrings = []

    # str[i:j] returns substring of s from index i to (not including) index j
    for i in range(len(str)):
        for j in range(n - i):
            substrings.append((str[i:n + 1]))
            return substrings
            print(substrings)


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    # split each string into all substrings of len n
    substrings_a = set(get_substrings(a,n))
    substrings_b = set(get_substrings(b,n))
    print(substrings_a)
    print(substrings_b)

    return substrings_a & substrings_b
