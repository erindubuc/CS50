# Program that encrypts messages using Vigenère’s cipher
from cs50 import get_string
from sys import argv
import string


def main():

    if len(argv) != 2:
        print("Usage: python vigenere.py key")
        exit(1)

    if argv[1].isalpha() == False:
        print("Key may only contain alphabetic characters.")
        exit(1)

    # prompt the user for a string of plaintext, p
    plain_text = get_string("plaintext: ")

    print("ciphertext: ", end="")

    key = argv[1]
    key = list(key)
    plain_text = list(plain_text)

    # loop through the key
    j = 0

    # for i in range(len(p)):
    for c in plain_text:

        # If char is not alpha - just print it
        if not c.isalpha():
            print(c, end="")
            continue

         # If char is uppercase, offset ascii by 65
        if c.isupper():

            # to get int index between 0-25 of plaintext character
            p = ord(c) - 65

            # to hold current alpha character of key as an integer
            k = (ord(key[j % len(key)].upper()) - 65)

            # get cipher's uppercase letter ascii integer
            # c = (((ord(p[i]) - ord('A')) + k) % 26) + 65
            c = (p + k) % 26

            # increment loop by 1
            j += 1
            if j == len(key):
                j = 0

             # print character
            print(chr(c + 65), end="")
            continue

         # If char is uppercase, offset ascii by 65
        if c.islower():

            # to get int index between 0-25 of plaintext character
            p = ord(c) - 97

            # to get int index between 0-25 of key character -> in uppercase
            k = (ord(key[j % len(key)].lower()) - 97)

            # get cipher's uppercase letter ascii integer
            # c = (((ord(p[i]) - ord('A')) + k) % 26) + 65
            c = (p + k) % 26

            # increment loop by 1
            j += 1
            if j == len(key):
                j = 0

            # print character -> need to add 97 to get it in the lowercase
            print(chr(c + 97), end="")

    # print the result (ciphertext: and ending with a newline) and exit
    print()


if __name__ == "__main__":
    main()