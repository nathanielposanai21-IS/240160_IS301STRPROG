/*
Name: Nathaniel Posanai
Student ID: 240160
Date: 22 March 2025

Algorithm:
1. Generate random number between 1 and 20
2. Ask user to guess up to 5 times
3. Compare guess with random number
4. Display hints (low/high)
5. Stop if correct
6. If not guessed after 5 tries, display answer
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
int getGuess();
void printSuccess();
void printSorry(int number);
void printHint(int guess, int number);

int main() {
    int randomNumber, guess;
    int i;

    // Seed random generator
    srand(time(0));

    // Generate number between 1 and 20
    randomNumber = rand() % 20 + 1;

    printf("I am thinking of a number between 1 and 20.\n");

    // Loop for 5 attempts
    for (i = 1; i <= 5; i++) {

        guess = getGuess();

        if (guess == randomNumber) {
            printSuccess();
            return 0; // terminate immediately
        } else {
            printHint(guess, randomNumber);
        }
    }

    // After 5 failed attempts
    printSorry(randomNumber);

    return 0;
}

// Function to get user guess
int getGuess() {
    int guess;
    printf("Enter your guess: ");
    scanf("%d", &guess);
    return guess;
}

// Function to print success message
void printSuccess() {
    printf("Congratulations! You did it.\n");
}

// Function to print hint
void printHint(int guess, int number) {
    if (guess < number) {
        printf("Your guess is low. Try again.\n");
    } else {
        printf("Your guess is high. Try again.\n");
    }
}

// Function to print sorry message
void printSorry(int number) {
    printf("Sorry. The number was %d.\n", number);
    printf("You should have gotten it by now.\n");
    printf("Better luck next time.\n");
}