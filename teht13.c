#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];
    FILE *file;
    int num, count = 0, lowest, highest;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: File '%s' is not found.\n", filename);
        return 1;
    }
    if (fscanf(file, "%d", &num) == 1) {
        lowest = highest = num;
        count++;
        while (fscanf(file, "%d", &num) == 1) {
            count++;
            if (num < lowest)
                lowest = num;
            if (num > highest)
                highest = num;
        }
    } else {
        printf("No numbers found in the file.\n");
        fclose(file);
        return 0;
    }

    printf("Count of numbers: %d\n", count);
    printf("Lowest number: %d\n", lowest);
    printf("Highest number: %d\n", highest);

    fclose(file);

    return 0;
}
