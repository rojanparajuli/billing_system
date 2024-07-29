#include "file_operations.h"
#include <stdio.h>

void saveToFile() {
    FILE *file = fopen("students.dat", "wb");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(&studentCount, sizeof(int), 1, file);
    fwrite(students, sizeof(Student), studentCount, file);
    fclose(file);
    printf("Data saved successfully!\n");
}

void loadFromFile() {
    FILE *file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    fread(&studentCount, sizeof(int), 1, file);
    fread(students, sizeof(Student), studentCount, file);
    fclose(file);
    printf("Data loaded successfully!\n");
}
