#include <fstream>
#include <iostream>
// #include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[]) {
  fstream file("input");
  string line;

  uint32_t sum = 0;

  // -1 -> not found

  if (file.is_open()) {
    while (getline(file, line)) {
      uint32_t first_digit = -1;
      uint32_t last_digit = -1;
      for (int i = 0; i < line.length(); i++) {
        if (isdigit(line[i])) {
          if (first_digit == -1) {
            first_digit = line[i] - '0';
            last_digit = line[i] - '0';
          } else
            last_digit = line[i] - '0';
        }
      }
      sum += first_digit * 10 + last_digit;
      printf("%s --- %d + %d\n", line.c_str(), first_digit, last_digit);
    }
  }
  file.close();
  printf("Sum: %d\n", sum);
  return 0;
}
