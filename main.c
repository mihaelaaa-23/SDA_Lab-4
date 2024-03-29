#include <stdio.h>
#include "struct.h"
#include "union.h"

int main() {
    int choice;

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Run standard version (using Struct)\n");
        printf("2. Run optimized version (using Union, and others)\n");
        printf("3. Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                struct_main();
                break;
            case 2:
                union_main();
                break;
            case 3:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}
