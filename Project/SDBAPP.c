#include <stdio.h>
#include "SDB.h"

void SDB_APP() {
    uint8 choice;

    do {
        printf("       d8888888b     d888888888888888888888 \n");
        printf("      d888888888b   d8888  888      888     \n");
        printf("     d88P88888888b.d88888  888      888     \n");
        printf("    d88P 888888Y88888P888  888      888     \n");
        printf("   d88P  888888 Y888P 888  888      888     \n");
        printf("  d88P   888888  Y8P  888  888      888     \n");
        printf(" d8888888888888   \"   888  888      888     \n");
        printf("\nStudent Database Menu:\n");
        printf("1. Add Entry\n");
        printf("2. Get Used Size\n");
        printf("3. Read Student Data\n");
        printf("4. Get List of Student IDs\n");
        printf("5. Check if ID Exists\n");
        printf("6. Delete Student Data\n");
        printf("7. Check if Database is Full\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%hhu", &choice);

        if (choice != 0) {
            SDB_action(choice);
        }
    } while (choice != 0);
}

void SDB_action(uint8 choice) { // I created some variables in which they will be inputs to get passed to my action functions
    uint32 id;
    uint8 count;
    uint32 list[Students];

    switch (choice) {
        case 1:
            if (SDB_AddEntry()) {
                printf("Student added successfully.\n");
            } else {
                printf("Unable to add student. Database is full.\n");
            }
            break;
        case 2:
            printf("Used size in database: %u\n", SDB_GetUsedSize());
            break;
        case 3:
            printf("Enter Student ID to read: ");
            scanf("%u", &id);
            if (SDB_ReadEntry(id)) { // the ReadEntry() function returns true if the entry was read successfully
                printf("Student data read successfully.\n");
            } else {
                printf("Student data not found.\n");
            }
            break;
        case 4:
            SDB_GetList(&count, list);
            printf("List of Student IDs:\n");
            for (uint8 i = 0; i < count; ++i) {
                printf("%u ", list[i]);
            }
            printf("\n");
            break;
        case 5:
            printf("Enter Student ID to check: ");
            scanf("%u", &id);
            if (SDB_IsIdExist(id)) { // the IsIdExist() function returns true if the student is already in the list of students otherwise it returns false
                printf("Student ID exists in the database.\n");
            } else {
                printf("Student ID does not exist in the database.\n");
            }
            break;
        case 6:
            printf("Enter Student ID to delete: ");
            scanf("%u", &id);
            SDB_DeleteEntry(id);
            break;
        case 7:
            if (SDB_IsFull()) { // the IsFull() function returns true if the database is full and the user has permission to delete the student from the database otherwise it returns false
                printf("Database is full.\n");
            } else {
                printf("Database is not full.\n");
            }
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
    }
}

int main() {
    SDB_APP();
    return 0;
}
