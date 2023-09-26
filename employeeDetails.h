#define MAX_EMPLOYEES 100
struct Date {
  int dd, mm, yy;
};

struct Employee {
  int empNo;
  char empFirstName[20];
  char empLastName[20];
  float basicSalary;
  float netSalary;
  struct Date hiredate;
};

void addEmployeeData(struct Employee *emp);
void displayEmployee(const struct Employee emp[], int len);
void updateEmployeeDetails(struct Employee *emp);