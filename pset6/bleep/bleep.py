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

    # Prompt user to provide a message
    message = get_string("What message would you like to censor? ")



if __name__ == "__main__":
    main()
