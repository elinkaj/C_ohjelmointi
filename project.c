#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSES 100
#define MAX_NAME_LENGTH 100

typedef struct {
    char course[MAX_NAME_LENGTH];
    int credits;
} Course;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int grades[MAX_COURSES];
    int num_courses;
} Student;

void trim(char *str) {
    // Remove leading and trailing whitespace from a string
    int i = 0, j = strlen(str) - 1;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        i++;
    while (str[j] == ' ' || str[j] == '\t' || str[j] == '\n')
        j--;
    str[j + 1] = '\0';
    memmove(str, str + i, strlen(str) + 1);
}

void read_course_info(FILE *file, Course *courses, int *num_courses) {
    char line[MAX_NAME_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        trim(line);
        if (line[0] == '[') {
            // Course information line
            sscanf(line, "[%[^]]]:%d", courses[*num_courses].course, &courses[*num_courses].credits);
            (*num_courses)++;
        }
    }
}

void read_student_grades(FILE *file, Student *students, int *num_students, Course *courses, int num_courses) {
    char line[MAX_NAME_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        trim(line);
        if (line[0] != '[') {
            // Student grade line
            char name[MAX_NAME_LENGTH];
            int grade;
            sscanf(line, "%[^:]:%d", name, &grade);

            // Find the student or create a new one if not found
            int i;
            for (i = 0; i < *num_students; i++) {
                if (strcmp(students[i].name, name) == 0)
                    break;
            }
            if (i == *num_students) {
                strcpy(students[*num_students].name, name);
                students[*num_students].num_courses = 0;
                (*num_students)++;
            }

            // Find the course and add the grade
            for (int j = 0; j < num_courses; j++) {
                if (strcmp(courses[j].course, line) == 0) {
                    students[i].grades[students[i].num_courses++] = grade;
                    break;
                }
            }
        }
    }
}

void print_student_transcript(Student student, Course *courses, int num_courses) {
    printf("Transcript for student: %s\n", student.name);
    printf("%-30s %s\n", "Course", "Grade");
    printf("-----------------------------------------\n");
    float total_grade = 0;
    for (int i = 0; i < student.num_courses; i++) {
        for (int j = 0; j < num_courses; j++) {
            if (strcmp(courses[j].course, student.grades[i]) == 0) {
                printf("%-30s %d\n", courses[j].course, student.grades[i]);
                total_grade += student.grades[i];
                break;
            }
        }
    }
    printf("-----------------------------------------\n");
    printf("Average Grade: %.2f\n\n", total_grade / student.num_courses);
}

int main() {
    FILE *file = fopen("course_info.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file.\n");
        return 1;
    }

    Course courses[MAX_COURSES];
    Student students[MAX_COURSES];
    int num_courses = 0, num_students = 0;

    read_course_info(file, courses, &num_courses);
    rewind(file);
    read_student_grades(file, students, &num_students, courses, num_courses);

    fclose(file);

    char student_name[MAX_NAME_LENGTH];
    while (1) {
        printf("Enter student's name (or 'stop' to quit): ");
        fgets(student_name, sizeof(student_name), stdin);
        trim(student_name);
        if (strcmp(student_name, "stop") == 0)
            break;

        int found = 0;
        for (int i = 0; i < num_students; i++) {
            if (strcmp(students[i].name, student_name) == 0) {
                print_student_transcript(students[i], courses, num_courses);
                found = 1;
                break;
            }
        }
        if (!found)
            printf("Error: Student not found.\n");
    }

    return 0;
}
