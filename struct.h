#ifndef STRUCT_H
#define STRUCT_H

typedef struct {
    char name[50];
    char surname[50];
    int birth_date;
    int birth_month;
    int birth_year;
    char gender;
    char address[100];
    char specialty[50];
    int group_no;
    float pc_prog_grade;
    float philosophy_grade;
    float english_grade;
} Student;

void introduce(Student *s);
void display(const Student *s);
void quickSort(Student *arr, int low, int high, int (*compare)(const Student *, const Student *));
int partition(Student *arr, int low, int high, int (*compare)(const Student *, const Student *));
void combSort(Student *arr, int n, int (*compare)(const Student *, const Student *));
int compare_name(const Student *a, const Student *b);
int compare_surname(const Student *a, const Student *b);
int compare_birthdate(const Student *a, const Student *b);
int compare_address(const Student *a, const Student *b);
int compare_specialty(const Student *a, const Student *b);
int compare_group(const Student *a, const Student *b);
int compare_pc_grade(const Student *a, const Student *b);
int compare_philosophy_grade(const Student *a, const Student *b);
int compare_english_grade(const Student *a, const Student *b);
void modify(Student *s);
void printMenu();
void struct_main();

#endif /* STRUCT_H */