#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

typedef struct {
  string str;
  int i;
} table_t;

table_t table[9] = {
    {string("one"), 1},   {string("two"), 2},   {string("three"), 3},
    {string("four"), 4},  {string("five"), 5},  {string("six"), 6},
    {string("seven"), 7}, {string("eight"), 8}, {string("nine"), 9}};

uint32_t find_str(string str) {
  for (int i = 0; i < 9; i++) {
    // both methods work
    // if (!strncmp(table[i].str.c_str(), str.c_str(), table[i].str.length()))
    if (!str.compare(0, table[i].str.length(), table[i].str.c_str()))
      return table[i].i;
  }
  return -1;
}

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
        } else {
          int found = find_str(line.substr(i));
          if (found != -1) {
            if (first_digit == -1) {
              first_digit = found;
              last_digit = found;
            } else
              last_digit = found;
          }
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
