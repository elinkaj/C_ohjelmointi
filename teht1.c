#include <stdio.h>

int main() {
    float bus_price, taxi_price, money_amount;

    printf("Enter price of bus ticket: ");
    scanf("%f", &bus_price);

    printf("Enter price of taxi: ");
    scanf("%f", &taxi_price);

    printf("How much money you have: ");
    scanf("%f", &money_amount);

    while (1) {
        printf("Do you want to take\n 1) Bus(%.2f euros)\n 2) Taxi(%.2f euros)\n Enter your selection:", bus_price, taxi_price);

        int choice;
        scanf("%d", &choice);

        if (money_amount < bus_price && money_amount < taxi_price) {
            printf("You need to walk. Bye. \n");
            break;
        }

        if (choice == 1) {
            if (money_amount >= bus_price) {
                printf("You chose bus. ");
                money_amount -= bus_price;
            } else {
                printf("You don't have enough money for the bus. ");
            }
        } else if (choice == 2) {
            if (money_amount >= taxi_price) {
                printf("You chose taxi. ");
                money_amount -= taxi_price;
            } else {
                printf("You don't have enough money for the taxi. ");
            }
        } else {
            printf("Invalid selection. Enter 1 for bus or 2 for taxi.\n");
            continue;
        }

        printf("You have %.2f euros left.\n", money_amount);
    }

    return 0;
}