#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_menu() {
    printf("\n MENU: \n");
    printf("(1) Roll D6\n");
    printf("(2) Roll D10\n");
    printf("(3) Quit \n");
}

int userChoice() {
    int choice;
    printf("Select a choice: ");
    if (scanf("%d", &choice) != 1 || choice > 3 || choice < 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return -1;
    } else {
        return choice;
    }
}

int roll_die(int sides) {
    return rand() % sides + 1;
}

int main() {
    srand(time(NULL));

    int choice;

    do {
        print_menu();
        choice = userChoice();

        switch (choice) {
            case 1:
                printf("You rolled D6 and got: %d\n", roll_die(6));
                break;
            case 2:
                printf("You rolled D10 and got: %d\n", roll_die(10));
                break;
            case 3:
                printf("You chose to quit.\n");
                break;
            default:
                printf("Please choose number between 1-3.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
