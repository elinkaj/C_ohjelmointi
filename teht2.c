#include <stdio.h>

int main() {
    float monthly_salaries[12];
    float tax_rate, income_limit, higher_taxrate;

    printf("Enter tax rate: ");
    scanf("%f", &tax_rate);

    printf("Enter income limit: ");
    scanf("%f", &income_limit);

    printf("Enter tax rate for income over the limit: ");
    scanf("%f", &higher_taxrate);


    for (int i = 0; i < 12; i++) {
        printf("Enter income for month %d: ", i + 1);
        scanf("%f", &monthly_salaries[i]);
    }


    printf("Month   Income   Tax\n");

    for (int i = 0; i < 12; ++i) {
        float monthly_tax;


        if (monthly_salaries[i] > income_limit) {
            monthly_tax = (income_limit * tax_rate / 100) +
                          ((monthly_salaries[i] - income_limit) * higher_taxrate / 100);
        } else {
            monthly_tax = monthly_salaries[i] * tax_rate / 100;
        }


        printf("%5d%10.2f%8.2f\n", i + 1, monthly_salaries[i], monthly_tax);
    }

    return 0;
}