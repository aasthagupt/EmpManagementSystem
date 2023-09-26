#include "employeeDetails.h"
#include "validations.h"
#include <stdio.h>

void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}
void addEmployeeData(struct Employee *emp) {
  do {
    printf("Enter Employee Number: ");
    if (scanf("%d", &emp->empNo) != 1 || !isValidEmpNo(emp->empNo)) {
      clearInputBuffer();
      printf(
          "Invalid Employee Number. Please enter a valid number (100-1000)\n");
    }
  } while (!isValidEmpNo(emp->empNo));

  clearInputBuffer();

  printf("Enter employee first name: ");
  scanf("%s", emp->empFirstName);

  while (!isValidName(emp->empFirstName)) {
    printf("Invalid first name. Please enter a valid first name: ");
    scanf("%s", emp->empFirstName);
  }

  printf("Enter employee last name: ");
  scanf("%s", emp->empLastName);

  while (!isValidName(emp->empLastName)) {
    printf("Invalid last name. Please enter a valid last name: ");
    scanf("%s", emp->empLastName);
  }

  printf("Enter hire date (dd mm yy): ");
  scanf("%d %d %d", &emp->hiredate.dd, &emp->hiredate.mm, &emp->hiredate.yy);

  while (!isValidDate(emp->hiredate.dd, emp->hiredate.mm, emp->hiredate.yy)) {
    printf("Invalid hire date. Please enter a valid date (dd mm yy): ");
    scanf("%d %d %d", &emp->hiredate.dd, &emp->hiredate.mm, &emp->hiredate.yy);
  }

  printf("Enter basic salary: ");
  scanf("%f", &emp->basicSalary);
}

float calculateSalary(struct Employee *emp) {
  float da = 0.4 * emp->basicSalary;
  float ta = 0.1 * emp->basicSalary;
  float pf = 0.05 * emp->basicSalary;
  return emp->netSalary = emp->basicSalary + da + ta - pf;
}

void updateEmployeeDetails(struct Employee *emp) {
  int choice;

  printf("Which field do you want to update?\n");
  printf("1. Employee First Name\n");
  printf("2. Employee Last Name\n");
  printf("3. Hire Date\n");
  printf("4. Basic Salary\n");
  printf("Enter your choice (1-4): ");
  scanf("%d", &choice);

  switch (choice) {
  case 1:
    printf("Enter updated first name: ");
    scanf("%s", emp->empFirstName);

    while (!isValidName(emp->empFirstName)) {
      printf("Invalid first name. Please enter a valid first name: ");
      scanf("%s", emp->empFirstName);
    }
    break;

  case 2:
    printf("Enter updated last name: ");
    scanf("%s", emp->empLastName);

    while (!isValidName(emp->empLastName)) {
      printf("Invalid last name. Please enter a valid last name: ");
      scanf("%s", emp->empLastName);
    }
    break;

  case 3:
    printf("Enter updated hire date (dd mm yy): ");
    scanf("%d %d %d", &emp->hiredate.dd, &emp->hiredate.mm, &emp->hiredate.yy);

    while (!isValidDate(emp->hiredate.dd, emp->hiredate.mm, emp->hiredate.yy)) {
      printf("Invalid hire date. Please enter a valid date (dd mm yy): ");
      scanf("%d %d %d", &emp->hiredate.dd, &emp->hiredate.mm,
            &emp->hiredate.yy);
    }
    break;

  case 4:
    printf("Enter updated basic salary: ");
    scanf("%f", &emp->basicSalary);
    break;

  default:
    printf("Invalid choice. No fields updated.\n");
    break;
  }
}

void displayEmployee(const struct Employee emp[], int len) {
  for (int i = 0; i < len; i++) {
    printf("Employee ID: %d\n", emp[i].empNo);
    printf("Employee First Name: %s\n", emp[i].empFirstName);
    printf("Employee Last Name: %s\n", emp[i].empLastName);
    printf("Employee Hire Date: %d %d %d\n", emp[i].hiredate.dd,
           emp[i].hiredate.mm, emp[i].hiredate.yy);
    printf("Employee Basic Salary: %.2f\n", emp[i].basicSalary);
    printf("Employee Net Salary: %.2f\n",
           calculateSalary((struct Employee *)&emp[i]));
  }
}
