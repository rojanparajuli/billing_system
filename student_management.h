#ifndef STUDENT_MANAGEMENT_H
#define STUDENT_MANAGEMENT_H

#define MAX_STUDENTS 100

typedef struct {
    int studentId;
    char name[50];
    char course[50];
    double tuitionFee;
    double libraryFee;
    double labFee;
    double totalFee;
    double amountPaid;
    double balance;
} Student;

extern Student students[MAX_STUDENTS];
extern int studentCount;

void addStudent();
void updateStudentFees();
void recordPayment();
void searchStudent();
void deleteStudent();
void generateReport();

#endif 
