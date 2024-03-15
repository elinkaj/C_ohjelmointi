#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 40
#define MAX_NAME_LENGTH 50

typedef struct menu_item_ {
    char name[MAX_NAME_LENGTH];
    double price;
} menu_item;

int compareByName(const void *a, const void *b) {
    const menu_item *item1 = (const menu_item *)a;
    const menu_item *item2 = (const menu_item *)b;
    return strcmp(item1->name, item2->name);
}

int compareByPrice(const void *a, const void *b) {
    const menu_item *item1 = (const menu_item *)a;
    const menu_item *item2 = (const menu_item *)b;
    if (item1->price < item2->price) return -1;
    if (item1->price > item2->price) return 1;
    return 0;
}

int main() {
    menu_item items[MAX_ITEMS];
    char filename[100];
    FILE *file;
    int item_count = 0;

    printf("Enter the filename here: ");
    scanf("%99s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening a file %s\n", filename);
        exit(1);
    }
    while (item_count < MAX_ITEMS && fscanf(file, " %49[^;]; %lf\n", items[item_count].name, &items[item_count].price) == 2) {
        item_count++;
    }
    fclose(file);

    printf("Choose sorting order:\n");
    printf("1. Sort by name\n");
    printf("2. Sort by price\n");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            qsort(items, item_count, sizeof(menu_item), compareByName);
            break;
        case 2:
            qsort(items, item_count, sizeof(menu_item), compareByPrice);
            break;
        default:
            printf("Invalid choice.\n");
            exit(1);
    }

    printf("%-8s%-50s\n", "Price", "Name");
    for (int i = 0; i < item_count; i++) {
        printf("%-8.2lf%-50s\n", items[i].price, items[i].name);
    }

    return 0;
}

