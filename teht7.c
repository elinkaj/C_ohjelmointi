#include <stdio.h>
#include <stdbool.h>

bool read_positive(int *value);

int main() {
    int money = 0;
    int guess;
    int incorrect_answers = 0;

    printf("Guess how much money I have!\n");

    while (true) {
        if (!read_positive(&guess)) {
            incorrect_answers++;
            if (incorrect_answers == 3) {
                printf("I give up! See you later!\n");
                break;
            }
            printf("Incorrect input. Try again!\n");
            continue;
        }

        money = guess * 2 + 20;
        printf("You didn't get it right. I have %d euros. Guess how much money I have!\n", money);
    }

    return 0;
}

bool read_positive(int *value) {
    printf("Enter a positive number: ");
    if (scanf("%d", value) != 1 || *value <= 0) {
        while (getchar() != '\n');
        return false;
    }
    return true;
}
