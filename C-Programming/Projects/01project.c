/*
Random Number Guessing Game

The program generates a random number between 1 and 100.
The player has 10 chances to guess it.

If the guess is too high, the program asks for a lower number.
If the guess is too low, the program asks for a higher number.
When the guess is correct, the program displays the number of attempts used.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int random_number = (rand() % 100) + 1;
    int guessed_number;

    for (int attempt = 1; attempt <= 10; attempt++) {
        printf("Enter your guessed number (1 to 100): ");
        scanf("%d", &guessed_number);

        if (guessed_number > 100 || guessed_number < 1) {
            printf("You are getting out of range! It is 1-100, my friend.\n");
        } else if (guessed_number == random_number) {
            printf("Congrats! You guessed the number on attempt %d: %d\n", attempt, random_number);
            return 0;
        } else if (guessed_number < random_number) {
            printf("Try higher!\n");
        } else {
            printf("Try lower!\n");
        }
    }

    printf("No more guesses. The number was %d. Better luck next round.\n", random_number);

    return 0;
}
