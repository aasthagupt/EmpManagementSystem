#include <ctype.h>
#include <stdbool.h>

bool isValidDate(int dd, int mm, int yy) {
  if (mm < 1 || mm > 12 || dd < 1 || dd > 31 || yy < 0) {
    return false;
  }

  switch (mm) {
  case 4:
  case 6:
  case 9:
  case 11:
    if (dd > 30) {
      return false;
    }
    break;
  case 2:
    if (yy % 4 == 0 && (yy % 100 != 0 || yy % 400 == 0)) {
      if (dd > 29) {
        return false;
      }
    } else {
      if (dd > 28) {
        return false;
      }
    }
    break;
  default:
    if (dd > 31) {
      return false;
    }
    break;
  }

  return true;
}

bool isValidName(const char *name) {
  for (int i = 0; name[i]; i++) {
    if (!isalpha(name[i])) {
      return false;
    }
  }
  return true;
}

bool isValidEmpNo(int empNo) { return (empNo >= 100 && empNo <= 1000); }