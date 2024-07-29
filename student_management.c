#include "student_management.h"
#include <stdio.h>
#include <string.h>

Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Student limit reached.\n");
        return;
    }

    Student newStudent;
    newStudent.studentId = studentCount + 1;
    printf("Enter student name: ");
    scanf("%s", newStudent.name);
    printf("Enter course: ");
    scanf("%s", newStudent.course);
    printf("Enter tuition fee: ");
    scanf("%lf", &newStudent.tuitionFee);
    printf("Enter library fee: ");
    scanf("%lf", &newStudent.libraryFee);
    printf("Enter lab fee: ");
    scanf("%lf", &newStudent.labFee);
    newStudent.totalFee = newStudent.tuitionFee + newStudent.libraryFee + newStudent.labFee;
    newStudent.amountPaid = 0.0;
    newStudent.balance = newStudent.totalFee;

    students[studentCount] = newStudent;
    studentCount++;
    printf("Student added successfully!\n");
}

void updateStudentFees() {
    int studentId;
    printf("Enter student ID: ");
    scanf("%d", &studentId);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentId == studentId) {
            printf("Enter new tuition fee: ");
            scanf("%lf", &students[i].tuitionFee);
            printf("Enter new library fee: ");
            scanf("%lf", &students[i].libraryFee);
            printf("Enter new lab fee: ");
            scanf("%lf", &students[i].labFee);
            students[i].totalFee = students[i].tuitionFee + students[i].libraryFee + students[i].labFee;
            students[i].balance = students[i].totalFee - students[i].amountPaid;
            printf("Student fees updated successfully!\n");
            return;
        }
    }
    printf("Student ID not found.\n");
}

void recordPayment() {
    int studentId;
    double payment;
    printf("Enter student ID: ");
    scanf("%d", &studentId);
    printf("Enter payment amount: ");
    scanf("%lf", &payment);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentId == studentId) {
            students[i].amountPaid += payment;
            students[i].balance = students[i].totalFee - students[i].amountPaid;
            printf("Payment recorded successfully!\n");
            return;
        }
    }
    printf("Student ID not found.\n");
}

void searchStudent() {
    int studentId;
    printf("Enter student ID: ");
    scanf("%d", &studentId);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentId == studentId) {
            printf("Student Found:\n");
            printf("ID: %d\nName: %s\nCourse: %s\nTuition Fee: %.2f\nLibrary Fee: %.2f\nLab Fee: %.2f\nTotal Fee: %.2f\nAmount Paid: %.2f\nBalance: %.2f\n",
                   students[i].studentId, students[i].name, students[i].course, students[i].tuitionFee,
                   students[i].libraryFee, students[i].labFee, students[i].totalFee,
                   students[i].amountPaid, students[i].balance);
            return;
        }
    }
    printf("Student ID not found.\n");
}

void deleteStudent() {
    int studentId;
    printf("Enter student ID: ");
    scanf("%d", &studentId);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentId == studentId) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student deleted successfully!\n");
            return;
        }
    }
    printf("Student ID not found.\n");
}

void generateReport() {
    int reportType;
    printf("Generate Report:\n");
    printf("1. All Students\n");
    printf("2. Paid Students\n");
    printf("3. Unpaid Students\n");
    printf("Enter report type: ");
    scanf("%d", &reportType);

    printf("ID\tName\tCourse\tTuition\tLibrary\tLab\tTotal\tPaid\tBalance\n");
    printf("---------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < studentCount; i++) {
        if ((reportType == 1) ||
            (reportType == 2 && students[i].balance == 0) ||
            (reportType == 3 && students[i].balance > 0)) {
            printf("%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",
                   students[i].studentId, students[i].name, students[i].course, students[i].tuitionFee,
                   students[i].libraryFee, students[i].labFee, students[i].totalFee,
                   students[i].amountPaid, students[i].balance);
        }
    }
}
