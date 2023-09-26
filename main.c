#include "employeeDetails.h"
#include <stdbool.h>
#include <stdio.h>

int main() {
  int len = 0;
  struct Employee emp[MAX_EMPLOYEES];
  printf("**** EMPLOYEE MANAGEMENT SYSTEM ****\n");
  printf("************* WELCOME *************\n");
  char response;

  do {
    printf("Enter the details of the employee:\n");
    addEmployeeData(&emp[len]);
    len++;

    printf("Do you want to enter another employee? (y/n): ");
    scanf(" %c", &response);
  } while (response == 'y' || response == 'Y');

  displayEmployee(emp, len);
  getchar();

  while (1) {
    printf("Do you want to update employee data? (y/n): ");
    scanf(" %c", &response);

    if (response != 'y' && response != 'Y') {
      break;
    }

    int empNoUpdate;
    printf("Enter the employee number of the employee to update: ");
    scanf("%d", &empNoUpdate);
    int flag = 0;

    for (int i = 0; i < len; i++) {
      if (emp[i].empNo == empNoUpdate) {
        updateEmployeeDetails(&emp[i]);
        flag = 1;
        break;
      }
    }

    if (!flag) {
      printf("Employee with the specified employee number not found.\n");
    }

    printf("Updated Employee Details:\n");
    displayEmployee(emp, len);
  }

  return 0;
}
