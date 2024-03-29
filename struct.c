#include "main.h"
#include <stdio.h>
#include <string.h>

void struct_main() {
    Student students[100];
    int num_students, choice, sort_field_choice, sort_order_choice;
    printf("\n---This is the standard version---\n");
    printf("\nEnter the number of students: ");
    scanf("%d", &num_students);

    for (int i = 0; i < num_students; ++i) {
        printf("\nEnter details for student %d:\n", i + 1);
        introduce(&students[i]);
    }

    while (1) {
        printMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (int i = 0; i < num_students; ++i) {
                    printf("\nDetails of student %d:\n", i + 1);
                    display(&students[i]);
                }
                break;
            case 2:
                printf("Choose field to sort by:\n");
                printf("1. Name\n");
                printf("2. Surname\n");
                printf("3. Birth Date\n");
                printf("4. Address\n");
                printf("5. Specialty\n");
                printf("6. Group Number\n");
                printf("7. PC Programming Grade\n");
                printf("8. Philosophy Grade\n");
                printf("9. English Grade\n");
                printf("Enter your choice: ");
                scanf("%d", &sort_field_choice);

                if (sort_field_choice < 1 || sort_field_choice > 9) {
                    printf("Invalid choice.\n");
                    break;
                }

                printf("Choose sorting order:\n");
                printf("1. Ascending (Quick Sort)\n");
                printf("2. Descending (Comb Sort)\n");
                printf("Enter your choice: ");
                scanf("%d", &sort_order_choice);

                if (sort_order_choice != 1 && sort_order_choice != 2) {
                    printf("Invalid choice.\n");
                    break;
                }

                if (sort_order_choice == 1) {
                    switch (sort_field_choice) {
                        case 1:
                            quickSort(students, 0, num_students - 1, compare_name);
                            break;
                        case 2:
                            quickSort(students, 0, num_students - 1, compare_surname);
                            break;
                        case 3:
                            quickSort(students, 0, num_students - 1, compare_birthdate);
                            break;
                        case 4:
                            quickSort(students, 0, num_students - 1, compare_address);
                            break;
                        case 5:
                            quickSort(students, 0, num_students - 1, compare_specialty);
                            break;
                        case 6:
                            quickSort(students, 0, num_students - 1, compare_group);
                            break;
                        case 7:
                            quickSort(students, 0, num_students - 1, compare_pc_grade);
                            break;
                        case 8:
                            quickSort(students, 0, num_students - 1, compare_philosophy_grade);
                            break;
                        case 9:
                            quickSort(students, 0, num_students - 1, compare_english_grade);
                            break;
                    }
                } else if (sort_order_choice == 2) {
                    switch (sort_field_choice) {
                        case 1:
                            combSort(students, num_students, compare_name);
                            break;
                        case 2:
                            combSort(students, num_students, compare_surname);
                            break;
                        case 3:
                            combSort(students, num_students, compare_birthdate);
                            break;
                        case 4:
                            combSort(students, num_students, compare_address);
                            break;
                        case 5:
                            combSort(students, num_students, compare_specialty);
                            break;
                        case 6:
                            combSort(students, num_students, compare_group);
                            break;
                        case 7:
                            combSort(students, num_students, compare_pc_grade);
                            break;
                        case 8:
                            combSort(students, num_students, compare_philosophy_grade);
                            break;
                        case 9:
                            combSort(students, num_students, compare_english_grade);
                            break;
                    }
                }
                printf("\nStudents sorted successfully.\n");
                break;
            case 3:
                modify(students);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
}

void introduce(Student *s) {
    printf("Enter name: ");
    scanf("%s", s->name);
    printf("Enter surname: ");
    scanf("%s", s->surname);
    printf("Enter birth date (DD MM YYYY): ");
    scanf("%d %d %d", &s->birth_date, &s->birth_month, &s->birth_year);
    printf("Enter gender (M/F): ");
    scanf(" %c", &s->gender);

    // clear buffer input
    while (getchar() != '\n');

    printf("Enter address: ");
    fgets(s->address, sizeof(s->address), stdin);
    s->address[strcspn(s->address, "\n")] = '\0'; // remove newlines

    printf("Enter specialty: ");
    fgets(s->specialty, sizeof(s->specialty), stdin);
    s->specialty[strcspn(s->specialty, "\n")] = '\0';
    printf("Enter group number: ");
    scanf("%d", &s->group_no);
    printf("Enter PC Programming grade: ");
    scanf("%f", &s->pc_prog_grade);
    printf("Enter Philosophy grade: ");
    scanf("%f", &s->philosophy_grade);
    printf("Enter English grade: ");
    scanf("%f", &s->english_grade);
}

void display(const Student *s) {
    printf("Name: %s\n", s->name);
    printf("Surname: %s\n", s->surname);
    printf("Birth Date: %d-%d-%d\n", s->birth_date, s->birth_month, s->birth_year);
    printf("Gender: %c\n", s->gender);
    printf("Address: %s\n", s->address);
    printf("Specialty: %s\n", s->specialty);
    printf("Group No.: %d\n", s->group_no);
    printf("PC Programming Grade: %.2f\n", s->pc_prog_grade);
    printf("Philosophy Grade: %.2f\n", s->philosophy_grade);
    printf("English Grade: %.2f\n", s->english_grade);
}

void quickSort(Student *arr, int low, int high, int (*compare)(const Student *, const Student *)) {
    if (low < high) {
        int pi = partition(arr, low, high, compare);
        quickSort(arr, low, pi - 1, compare);
        quickSort(arr, pi + 1, high, compare);
    }
}

int partition(Student *arr, int low, int high, int (*compare)(const Student *, const Student *)) {
    Student pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (compare(&arr[j], &pivot) < 0) {
            i++;
            Student temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    Student temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void combSort(Student *arr, int n, int (*compare)(const Student *, const Student *)) {
    int gap = n;
    float shrink = 1.3;
    int swapped = 1;
    while (gap > 1 || swapped) {
        if (gap > 1)
            gap = (int)(gap / shrink);
        swapped = 0;
        for (int i = 0; i + gap < n; i++) {
            if (compare(&arr[i], &arr[i + gap]) < 0) {
                Student temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = 1;
            }
        }
    }
}

void modify(Student *s) {
    char search_name[50], search_surname[50];
    int search_year;
    int modify_choice;
    printf("\nEnter the name of the student you want to modify: ");
    scanf("%s", search_name);
    printf("Enter the surname of the student: ");
    scanf("%s", search_surname);
    printf("Enter the birth year of the student: ");
    scanf("%d", &search_year);

    for (int i = 0; i < 100; ++i) {
        if (strcmp(s[i].name, search_name) == 0 && strcmp(s[i].surname, search_surname) == 0 && s[i].birth_year == search_year) {
            printf("\nStudent found. Please select what you want to modify:\n");
            printf("1. Name\n");
            printf("2. Surname\n");
            printf("3. Birth Date\n");
            printf("4. Address\n");
            printf("5. Specialty\n");
            printf("6. Group Number\n");
            printf("7. PC Programming Grade\n");
            printf("8. Philosophy Grade\n");
            printf("9. English Grade\n");
            printf("Enter your choice: ");
            scanf("%d", &modify_choice);

            switch (modify_choice) {
                case 1:
                    printf("Enter new name: ");
                    scanf("%s", s[i].name);
                    printf("Name updated successfully.\n");
                    break;
                case 2:
                    printf("Enter new surname: ");
                    scanf("%s", s[i].surname);
                    printf("Surname updated successfully.\n");
                    break;
                case 3:
                    printf("Enter new birth date (DD MM YYYY): ");
                    scanf("%d %d %d", &s[i].birth_date, &s[i].birth_month, &s[i].birth_year);
                    printf("Birth date updated successfully.\n");
                    break;
                case 4:
                    printf("Enter new address: ");
                    getchar();
                    fgets(s[i].address, sizeof(s[i].address), stdin);
                    s[i].address[strcspn(s[i].address, "\n")] = '\0';
                    printf("Address updated successfully.\n");
                    break;
                case 5:
                    printf("Enter new specialty: ");
                    getchar();
                    fgets(s[i].specialty, sizeof(s[i].specialty), stdin);
                    s[i].specialty[strcspn(s[i].specialty, "\n")] = '\0';
                    printf("Specialty updated successfully.\n");
                    break;
                case 6:
                    printf("Enter new group number: ");
                    scanf("%d", &s[i].group_no);
                    printf("Group number updated successfully.\n");
                    break;
                case 7:
                    printf("Enter new PC Programming grade: ");
                    scanf("%f", &s[i].pc_prog_grade);
                    printf("PC Programming grade updated successfully.\n");
                    break;
                case 8:
                    printf("Enter new Philosophy grade: ");
                    scanf("%f", &s[i].philosophy_grade);
                    printf("Philosophy grade updated successfully.\n");
                    break;
                case 9:
                    printf("Enter new English grade: ");
                    scanf("%f", &s[i].english_grade);
                    printf("English grade updated successfully.\n");
                    break;
                default:
                    printf("Invalid choice.\n");
            }
            return;
        }
    }
    printf("Student not found.\n");
}

void printMenu() {
    printf("---------------------------------");
    printf("\nMain Menu\n");
    printf("1. Display all students\n");
    printf("2. Sort students\n");
    printf("3. Modify student details\n");
    printf("4. Exit\n");
    printf("---------------------------------");
}

int compare_name(const Student *a, const Student *b) {
    return strcmp(a->name, b->name);
}

int compare_surname(const  Student *a, const Student *b) {
    return strcmp(a->surname, b->surname);
}

int compare_birthdate(const Student *a, const Student *b) {
    if (a->birth_year != b->birth_year)
        return a->birth_year - b->birth_year;
    if (a->birth_month != b->birth_month)
        return a->birth_month - b->birth_month;
    return a->birth_date - b->birth_date;
}

int compare_address(const Student *a, const Student *b) {
    return strcmp(a->address, b->address);
}

int compare_specialty(const Student *a, const Student *b) {
    return strcmp(a->specialty, b->specialty);
}

int compare_group(const Student *a, const Student *b) {
    return a->group_no - b->group_no;
}

int compare_pc_grade(const Student *a, const Student *b) {
    return (a->pc_prog_grade > b->pc_prog_grade) - (a->pc_prog_grade < b->pc_prog_grade);
}

int compare_philosophy_grade(const Student *a, const Student *b) {
    return (a->philosophy_grade > b->philosophy_grade) - (a->philosophy_grade < b->philosophy_grade);
}

int compare_english_grade(const Student *a, const Student *b) {
    return (a->english_grade > b->english_grade) - (a->english_grade < b->english_grade);
}
