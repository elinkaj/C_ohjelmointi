#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int read_range(int low, int high) {
    int num;

    while (1) {
        printf("Enter a number between %d and %d: ", low, high);
        if (scanf("%d", &num) != 1 || num < low || num > high) {
            printf("Invalid input. Please enter a number between %d and %d.\n", low, high);
            while (getchar() != '\n');
        } else {
            return num;
        }
    }
}

int roll_die() {
    return rand() % 6 + 1;
}

int main() {
    srand(time(NULL));

    printf("Let's play!\n");

    int playerWins = 0;
    int programWins = 0;

    for (int round = 1; round <= 3; round++) {
        printf("Roll a die and enter your result.\n");
        int userRoll = read_range(1, 6);

        int programRoll = (userRoll == 6) ? 6 : userRoll + 1;

        printf("I got %d. ", programRoll);

        if (userRoll == 6 && programRoll == 6) {
            printf("It's a tie!\n");
        } else if (programRoll > userRoll) {
            printf("I win!\n");
            programWins++;
        } else {
            printf("You win!\n");
            playerWins++;
        }
    }

    printf("Better luck next time!\n");

    return 0;
}