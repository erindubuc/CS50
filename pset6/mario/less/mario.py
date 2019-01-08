# program that recreates a half-pyramid using hashes (#) for blocks
from cs50 import get_int


def main():
    # prompt and validate user input
    while True:
        height = get_int("Enter a height from 1 to 8, inclusive: ")
        if (height >= 1 and height <= 8):
            break

    # draw the half-pyramid
    for lines in range(0, height):

        # draw the spaces
        for spaces in range(1, height - lines):
            print(" ", end="")

        # draw the hashes
        for hashes in range(lines + 1):
            print("#", end="")

        # print new line
        print()


if __name__ == "__main__":
    main()
