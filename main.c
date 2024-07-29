#include <stdio.h>
#include "student_management.h"
#include "file_operations.h"

void displayMenu() {
    int choice;
    do {
        printf("\nStudent Fee Management System\n");
        printf("1. Add Student\n");
        printf("2. Update Student Fees\n");
        printf("3. Record Payment\n");
        printf("4. Search Student\n");
        printf("5. Delete Student\n");
        printf("6. Generate Fee Report\n");
        printf("7. Save Data to File\n");
        printf("8. Load Data from File\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                updateStudentFees();
                break;
            case 3:
                recordPayment();
                break;
            case 4:
                searchStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                generateReport();
                break;
            case 7:
                saveToFile();
                break;
            case 8:
                loadFromFile();
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 9);
}

int main() {
    loadFromFile();  
    displayMenu();   
    saveToFile();   
    return 0;
}
