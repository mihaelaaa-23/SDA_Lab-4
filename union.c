#include "main.h"
#include <stdio.h>
#include <string.h>

void union_main() {
    Student1 Students1[100];
    int num_Students1, choice, sort_field_choice, sort_order_choice;
    printf("\n---This is the optimized version---\n");
    printf("\nEnter the number of students: ");
    scanf("%d", &num_Students1);

    for (int i = 0; i < num_Students1; ++i) {
        printf("\nEnter details for Student %d:\n", i + 1);
        input(&Students1[i]);
    }

    while (1) {
        print_menu();

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (int i = 0; i < num_Students1; ++i) {
                    printf("\nDetails of Student %d:\n", i + 1);
                    output(&Students1[i]);
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
                            quick_sort(Students1, 0, num_Students1 - 1, compare_by_name);
                            break;
                        case 2:
                            quick_sort(Students1, 0, num_Students1 - 1, compare_by_surname);
                            break;
                        case 3:
                            quick_sort(Students1, 0, num_Students1 - 1, compare_by_birthdate);
                            break;
                        case 4:
                            quick_sort(Students1, 0, num_Students1 - 1, compare_by_address);
                            break;
                        case 5:
                            quick_sort(Students1, 0, num_Students1 - 1, compare_by_speciality);
                            break;
                        case 6:
                            quick_sort(Students1, 0, num_Students1 - 1, compare_by_group);
                            break;
                        case 7:
                            quick_sort(Students1, 0, num_Students1 - 1, compare_by_pc_grade);
                            break;
                        case 8:
                            quick_sort(Students1, 0, num_Students1 - 1, compare_by_philosophy_grade);
                            break;
                        case 9:
                            quick_sort(Students1, 0, num_Students1 - 1, compare_by_english_grade);
                            break;
                    }
                } else if (sort_order_choice == 2) {
                    switch (sort_field_choice) {
                        case 1:
                            comb_sort(Students1, num_Students1, compare_by_name);
                            break;
                        case 2:
                            comb_sort(Students1, num_Students1, compare_by_surname);
                            break;
                        case 3:
                            comb_sort(Students1, num_Students1, compare_by_birthdate);
                            break;
                        case 4:
                            comb_sort(Students1, num_Students1, compare_by_address);
                            break;
                        case 5:
                            comb_sort(Students1, num_Students1, compare_by_speciality);
                            break;
                        case 6:
                            comb_sort(Students1, num_Students1, compare_by_group);
                            break;
                        case 7:
                            comb_sort(Students1, num_Students1, compare_by_pc_grade);
                            break;
                        case 8:
                            comb_sort(Students1, num_Students1, compare_by_philosophy_grade);
                            break;
                        case 9:
                            comb_sort(Students1, num_Students1, compare_by_english_grade);
                            break;
                    }
                }
                printf("\nStudents1 sorted successfully.\n");
                break;
            case 3:
                change(Students1);
                break;
            case 4:
                printf("Exiting the program.");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
}

void input(struct Student1 *s) {
    printf("Enter name: ");
    scanf("%s", s->name);
    printf("Enter surname: ");
    scanf("%s", s->surname);
    printf("Enter birth date (DD MM YYYY): ");
    scanf("%u %u %u", &s->birthDate.day, &s->birthDate.month, &s->birthDate.year);
    printf("Enter gender (M/F): ");
    scanf(" %c", &s->gender);

    // clear input buffer
    while (getchar() != '\n');

    printf("Enter address: ");
    fgets(s->address, sizeof(s->address), stdin);
    s->address[strcspn(s->address, "\n")] = '\0';

    printf("Enter specialty: ");
    fgets(s->specialty, sizeof(s->specialty), stdin);
    s->specialty[strcspn(s->specialty, "\n")] = '\0';

    printf("Enter group number: ");
    scanf("%d", &s->group_no);
    printf("Enter PC Programming grade: ");
    scanf("%f", &s->grades[0].grade);
    printf("Enter Philosophy grade: ");
    scanf("%f", &s->grades[1].grade);
    printf("Enter English grade: ");
    scanf("%f", &s->grades[2].grade);
}


void output(const struct Student1 *s) {
    printf("Name: %s\n", s->name);
    printf("Surname: %s\n", s->surname);
    printf("Birth Date: %d-%d-%d\n", s->birthDate.day, s->birthDate.month, s->birthDate.year);
    printf("Gender: %c\n", s->gender);
    printf("Address: %s\n", s->address);
    printf("Specialty: %s\n", s->specialty);
    printf("Group No.: %d\n", s->group_no);
    printf("PC Programming Grade: %.2f\n", s->grades[0].grade);
    printf("Philosophy Grade: %.2f\n", s->grades[1].grade);
    printf("English Grade: %.2f\n", s->grades[2].grade);
}

void quick_sort(Student1 *arr, int low, int high, int (*compare)(const Student1 *, const Student1 *)) {
    if (low < high) {
        int pi = partition1(arr, low, high, compare);
        quick_sort(arr, low, pi - 1, compare);
        quick_sort(arr, pi + 1, high, compare);
    }
}

int partition1(Student1 *arr, int low, int high, int (*compare)(const Student1 *, const Student1 *)) {
    Student1 pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (compare(&arr[j], &pivot) < 0) {
            i++;
            Student1 temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    Student1 temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void comb_sort(Student1 *arr, int n, int (*compare)(const Student1 *, const Student1 *)) {
    int gap = n;
    float shrink = 1.3;
    int swapped = 1;
    while (gap > 1 || swapped) {
        if (gap > 1)
            gap = (int)(gap / shrink);
        swapped = 0;
        for (int i = 0; i + gap < n; i++) {
            if (compare(&arr[i], &arr[i + gap]) < 0) {
                Student1 temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = 1;
            }
        }
    }
}

void change(Student1 *s) {
    char search_name[50], search_surname[50];
    int search_year;
    int change_choice;
    printf("\nEnter the name of the Student you want to change: ");
    scanf("%s", search_name);
    printf("Enter the surname of the Student: ");
    scanf("%s", search_surname);
    printf("Enter the birth year of the Student: ");
    scanf("%d", &search_year);

    for (int i = 0; i < 100; ++i) {
        if (strcmp(s[i].name, search_name) == 0 && strcmp(s[i].surname, search_surname) == 0 && s[i].birthDate.year == search_year) {
            printf("\nStudent found. Please select what you want to change:\n");
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
            scanf("%d", &change_choice);

            switch (change_choice) {
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
                    scanf("%d %d %d", &s[i].birthDate.day, &s[i].birthDate.month, &s[i].birthDate.year);
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
                    scanf("%f", &s[i].grades[0].grade);
                    printf("PC Programming grade updated successfully.\n");
                    break;
                case 8:
                    printf("Enter new Philosophy grade: ");
                    scanf("%f", &s[i].grades[1].grade);
                    printf("Philosophy grade updated successfully.\n");
                    break;
                case 9:
                    printf("Enter new English grade: ");
                    scanf("%f", &s[i].grades[2].grade);
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

void print_menu() {
    printf("---------------------------------");
    printf("\nMain Menu\n");
    printf("1. Display all students\n");
    printf("2. Sort students\n");
    printf("3. Modify student details\n");
    printf("4. Exit\n");
    printf("---------------------------------");
}

int compare_by_name(const Student1 *a, const Student1 *b) {
    return strcmp(a->name, b->name);
}

int compare_by_surname(const Student1 *a, const Student1 *b) {
    return strcmp(a->surname, b->surname);
}


int compare_by_birthdate(const Student1 *a, const Student1 *b) {
    if (a->birthDate.year != b->birthDate.year)
        return a->birthDate.year - b->birthDate.year;
    if (a->birthDate.month != b->birthDate.month)
        return a->birthDate.month - b->birthDate.month;
    return a->birthDate.day - b->birthDate.day;
}


int compare_by_address(const Student1 *a, const Student1 *b) {
    return strcmp(a->address, b->address);
}

int compare_by_speciality(const Student1 *a, const Student1 *b) {
    return strcmp(a->specialty, b->specialty);
}

int compare_by_group(const Student1 *a, const Student1 *b) {
    return a->group_no - b->group_no;
}

int compare_by_pc_grade(const struct Student1 *a, const struct Student1 *b) {
    return (a->grades[0].grade > b->grades[0].grade) - (a->grades[0].grade < b->grades[0].grade);
}

int compare_by_philosophy_grade(const struct Student1 *a, const struct Student1 *b) {
    return (a->grades[1].grade > b->grades[1].grade) - (a->grades[1].grade < b->grades[1].grade);
}

int compare_by_english_grade(const struct Student1 *a, const struct Student1 *b) {
    return (a->grades[2].grade > b->grades[2].grade) - (a->grades[2].grade < b->grades[2].grade);
}


