# program that calculates the minimum number of coins required to give a user change

from cs50 import get_float


def main():

    # prompt and validate user input
    while True:
        change = get_float("How much change are you owed? ")
        if (change > 0):
            break

    # Convert change amount to coins by multiplying by 100 since $1 = 100 cents
    cents = int(round(change * 100))
    # print(f"You will need {cents} cents back.")

    # Find out what the minimum number of coins to return as change are
    # Initialize coins to keep track of count
    coinsCount = 0

    # Start with largest coin first - Quarters
    # Keep track of how many coins to be returned
    coinsCount += cents // 25

    # Keep track of amount to still be returned
    cents %= 25
    # print(f"cents left to return after quarters: {cents}")
    # print(f"coins count so far: {coinsCount}")

    # Dimes
    coinsCount += cents // 10
    cents %= 10
    # print(f"cents left to return after dimes: {cents}")
    # print(f"coins count so far: {coinsCount}")

    # Nickels
    coinsCount += cents // 5
    cents %= 5
    # print(f"cents left to return after nickels: {cents}")
    # print(f"coins count so far: {coinsCount}")

    # Pennies
    coinsCount += cents // 1
    cents %= 1
    # print(f"cents left to return after pennies: {cents}")
    # print(f"final coins count: {coinsCount}")

    # Return minimum number of coins possible
    print(coinsCount)


if __name__ == "__main__":
    main()