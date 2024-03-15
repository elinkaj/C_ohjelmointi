#include <stdio.h>
#include <stdlib.h>

int find_first(const unsigned int *array, unsigned int what) {
    int i = 0;
    while (array[i] != 0) {
        if (array[i] == what) {
            return i;
        }
        i++;
    }
    return -1;
}

int main() {
    int numbers[20];
    for (int i = 0; i < 19; i++) {
        numbers[i] = rand() % 20 + 1;
    }
    numbers[19] = 0;

    printf("Array:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d\n", numbers[i]);
    }
    unsigned int number;
    while (1) {
        printf("Enter a number to search for (or 0 to stop): ");
        scanf("%u", &number);

        if (number == 0) {
            printf("Program terminated.\n");
            break;
        }

        int result = find_first(numbers, number);
        if (result != -1) {
            printf("Number %u found at index %d.\n", number, result);
        } else {
            printf("Number not found.\n");
        }
    }

    return 0;
}
