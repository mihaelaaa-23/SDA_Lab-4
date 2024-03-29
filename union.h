#ifndef UNION_H
#define UNION_H

typedef union Grade {
    float grade;
} Grade;

typedef struct BirthDate {
    unsigned int day;
    unsigned int month;
    unsigned int year;
} BirthDate;

typedef struct Student1 {
    char name[50];
    char surname[50];
    BirthDate birthDate; //bitfield
    char gender;
    char address[100];
    char specialty[50];
    int group_no;
    Grade grades[3]; // 0: PC Programming, 1: Philosophy, 2: English
} Student1;

void input(struct Student1 *s);
void output(const struct Student1 *s);
void quick_sort(struct Student1 *arr, int low, int high, int (*compare)(const struct Student1 *, const struct Student1 *));
int partition1(struct Student1 *arr, int low, int high, int (*compare)(const struct Student1 *, const struct Student1 *));
void comb_sort(struct Student1 *arr, int n, int (*compare)(const struct Student1 *, const struct Student1 *));
int compare_by_name(const struct Student1 *a, const struct Student1 *b);
int compare_by_surname(const struct Student1 *a, const struct Student1 *b);
int compare_by_birthdate(const struct Student1 *a, const struct Student1 *b);
int compare_by_address(const struct Student1 *a, const struct Student1 *b);
int compare_by_speciality(const struct Student1 *a, const struct Student1 *b);
int compare_by_group(const struct Student1 *a, const struct Student1 *b);
int compare_by_pc_grade(const struct Student1 *a, const struct Student1 *b);
int compare_by_philosophy_grade(const struct Student1 *a, const struct Student1 *b);
int compare_by_english_grade(const struct Student1 *a, const struct Student1 *b);
void change(struct Student1 *s);
void print_menu();
void union_main();

#endif //UNION_H
