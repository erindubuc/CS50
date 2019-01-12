# Program that censors messages that contain words appearing on a list of supplied "banned words"

from cs50 import get_string
from sys import argv


def main():

    # Get the text file containing banned words
    if len(argv) != 2:
        print("Usage: python bleep.py dictonary(text)")
        exit(1)

    # Open text file of banned words
    # buffer = 1 to buffer 1 line at a time
    infile = argv[1]
    file_open = open(infile, "r", 1)

    # Store list of banned words in set structure
    banned_words = set(line.strip() for line in open(infile))
    print(f"infile {infile} and this is the set {banned_words}")

    # Prompt user to provide a message
    message = get_string("What message would you like to censor? ")

    tokens = set(message.split(' '))
    print(f"{tokens}")

    # Check to see if message words match any words from banned set
    banned = banned_words.intersection(tokens)
    # print(banned)

    for elem in banned:
        for i in elem:
            print('*', end="")

    print(' '.join(banned))

    new_banned = ' '.join(banned)

    for i in new_banned:
        print('*', end="")

    for i in new_banned:
        print(message.replace(new_banned, '*'))
    # if str(banned in message:
    #     for c in banned:
    #         print("*", end="")
    # new_message = message.replace(for c in banned, "*")
    # for c in banned:
    #     print(c.replace(c, '*')


    print(message.replace(str(banned), '*'))

if __name__ == "__main__":
    main()

