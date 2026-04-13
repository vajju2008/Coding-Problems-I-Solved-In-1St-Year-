import random

def guess_number():
    number = random.randint(1, 100)
    print("Welcome to the number guessing game!")
    print("I have chosen a number between 1 and 100. Try to guess it!")
    
    while True:
        guess = int(input("Enter your guess: "))
        if guess < number:
            print("Too low! Try again.")
        elif guess > number:
            print("Too high! Try again.")
        else:
            print(f"Congratulations! You guessed the number {number}.")
            break

guess_number()
