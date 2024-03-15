#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num;

    while (1) {
        printf("Enter a number (0-15) or a negative number to stop: ");
        scanf("%d", &num);

        if (num < 0)
            break;
        else if (num >= 0 && num <= 15) {
            srand(time(NULL));
            int randomNum = rand() % 256;
            printf("Random number in hexadecimal: 0x%02X\n", randomNum);
            int shiftedNum = randomNum >> num;
            int result = shiftedNum & 0x3F;
            printf("Result after shifting and clearing: 0x%02X\n", result);
        } else {
            printf("Invalid input. Please enter a number between 0 and 15.\n");
        }
    }

    return 0;
}
