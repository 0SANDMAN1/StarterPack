#include <stdio.h>
#include "SDB.h"

static student database[MAX_STUDENTS];
static uint8 num_students = 0; // I used uint8 for the memory efficient

Bool SDB_IsFull() { // this function returns true if the database is full and false if not.
    return num_students >= MAX_STUDENTS;
}

uint8 SDB_GetUsedSize() { // this function returns the size of the database.
    return num_students;
}

Bool SDB_AddEntry() { // this function adds an entry to the database and returns true if it succeeded and increment the num_stduents otherwise returns false.
    if (SDB_IsFull()) {
        return FALSE;
    }

    student newStudent;

    printf("Enter Student ID: ");
    scanf("%u", &newStudent.Student_ID);

    printf("Enter Student Year: ");
    scanf("%u", &newStudent.Student_year);

    printf("Enter Course 1 ID: ");
    scanf("%u", &newStudent.Course1_ID);

    printf("Enter Course 1 Grade: ");
    scanf("%u", &newStudent.Course1_grade);

    printf("Enter Course 2 ID: ");
    scanf("%u", &newStudent.Course2_ID);

    printf("Enter Course 2 Grade: ");
    scanf("%u", &newStudent.Course2_grade);

    printf("Enter Course 3 ID: ");
    scanf("%u", &newStudent.Course3_ID);

    printf("Enter Course 3 Grade: ");
    scanf("%u", &newStudent.Course3_grade);

    database[num_students++] = newStudent;

    return TRUE;
}

void SDB_DeleteEntry(uint32 id) { // delete entry from database and decrement the counter for the next entry in the database table (if exists in the database table)
    for (uint8 i = 0; i < num_students; ++i) {
        if (database[i].Student_ID == id) {
            // Shift elements to fill the gap
            for (uint8 j = i; j < num_students - 1; ++j) {
                database[j] = database[j + 1];
            }
            num_students--;
            printf("Student with ID %u deleted.\n", id);
            return;
        }
    }
    printf("Student with ID %u not found.\n", id);
} 

Bool SDB_ReadEntry(uint32 id) { // this function should return true if the entry was found in the database and print the information
    for (uint8 i = 0; i < num_students; ++i) {
        if (database[i].Student_ID == id) {
            printf("Student ID: %u\n", database[i].Student_ID);
            printf("Student Year: %u\n", database[i].Student_year);
            printf("Course 1 ID: %u, Grade: %u\n", database[i].Course1_ID, database[i].Course1_grade);
            printf("Course 2 ID: %u, Grade: %u\n", database[i].Course2_ID, database[i].Course2_grade);
            printf("Course 3 ID: %u, Grade: %u\n", database[i].Course3_ID, database[i].Course3_grade);
            return TRUE;
        }
    }
    printf("Student with ID %u not found.\n", id);
    return FALSE;
}

void SDB_GetList(uint8 *count, uint32 *list) { // this function is called from the main thread only when the database has been initialized properly
    *count = num_students;
    for (uint8 i = 0; i < num_students; ++i) {
        list[i] = database[i].Student_ID;
    }
    printf( "Number of IDs: %u\n", *count);
    printf( "list of IDs:\n");
    for (uint8 i = 0; i < *count; ++i) {
        printf( "%u\n", list[i]);
    }

}

Bool SDB_IsIdExist(uint32 id) { // this function runs throught the database looking if ID exists or not otherwise returns false
    for (uint8 i = 0; i < num_students; ++i) {
        if (database[i].Student_ID == id) {
            return TRUE;
        }
    }
    return FALSE;
}
