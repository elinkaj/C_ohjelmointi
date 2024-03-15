#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 40
#define MAX_NAME_LENGTH 50

typedef struct menu_item_ {
    char name[MAX_NAME_LENGTH];
    double price;
} menu_item;

int main() {
    menu_item items[MAX_ITEMS];
    char filename[100];
    FILE *file;
    int item_count = 0;

    printf("Enter the filename: ");
    scanf("%99s", filename);

    file = fopen("Cteht.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening a file %s\n", filename);
        exit(1);
    }
    while (item_count < MAX_ITEMS && fscanf(file, " %49[^;]; %lf\n", items[item_count].name, &items[item_count].price) == 2) {
        item_count++;
    }
    fclose(file);

    printf("%-8s%-50s\n", "Price", "Name");
    for (int i = 0; i < item_count; i++) {
        printf("%-8.2lf%-50s\n", items[i].price, items[i].name);
    }

    return 0;
}
