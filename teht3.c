#include <stdio.h>

int main() {
    int student_amount, student_num, grade;

    printf("How many students: ");
    scanf("%d", &student_amount);

    int grades[student_amount];
    for (int i = 0; i < student_amount; i++) {
        grades[i] = -1;
    }

    do {
        printf("Enter student number (1 – %d) or 0 to stop: ", student_amount);
        scanf("%d", &student_num);

        if (student_num >= 1 && student_num <= student_amount) {
            printf("Enter grade (0 – 5) for student %d or -1 to cancel: ", student_num);
            scanf("%d", &grade);

            if (grade >= -1 && grade <= 5) {
                grades[student_num - 1] = grade;
            } else {
                if (grade != -1) {
                    printf("Invalid grade!\n");
                }
            }
        } else if (student_num != 0) {
            printf("Invalid student number!\n");
        }
    } while (student_num != 0);

    printf("Student numbers and grades:\n");
    for (int i = 0; i < student_amount; i++) {
        printf("Student %d: %s%d\n", i + 1, (grades[i] == -1) ? "N/A" : "", (grades[i] == -1) ? 0 : grades[i]);
    }

    return 0;
}