#include <stdio.h>

int read_integer(void);

int main() {
    int num = 0;
    int count = 0;
    float sum = 0.0f;

    while (1) {
        num = read_integer();

        if (num < 0) {
            break;
        }

        sum += num;
        count++;
    }
    if (count > 0) {
        float average = sum / count;
        printf("You entered %d positive numbers. The average is: %.3f\n", count, average);
    }
    return 0;
}

    int read_integer(void) {
        int num;

        while (1) {
            printf("Enter positive numbers or negative to stop: ");
            if (scanf("%d", &num) != 1) {
                printf("Invalid input.");
                while(getchar() != "\n");
            } else {
                return num;
            }
        }
    }