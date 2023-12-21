#include <array>
#include <fstream>
#include <sstream>
#include <vector>

typedef struct {
  int y;
  int xstart, xend;
} Position;

typedef struct {
  int num;
  bool valid;
  Position pos;
} Number;

// directions to verify
#define NUM_DIRS 8
const int dirs[NUM_DIRS][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {1, -1},
                               {1, 0},   {1, 1},  {0, -1}, {0, 1}};

bool isvalid(std::vector<std::string> text, Number num) {
  bool found = false;
  for (int j = 0; j < num.pos.xend - num.pos.xstart + 1; j++) {
    for (int i = 0; i < 6; i++) {
      int x = num.pos.xstart + j + dirs[i][0];
      int y = num.pos.y + dirs[i][1];
      if (x < 0 || y < 0 || x >= text[y].length() || y >= text.size()) {
        continue;
      }
      if (!isdigit(text[y][x]) && text[y][x] != '.') {
        found = true;
      }
    }
  }
  return found;
}

int main(int argc, char const *argv[]) {
  std::ifstream file("input");
  std::vector<std::string> contents;
  std::vector<Number> numbers;
  int sum = 0;

  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line, '\n')) {
      contents.push_back(line);
    }
  }

  file.close();

  for (int row = 0; row < contents.size(); row++) {
    Number currentNumber;
    int startCol = 0;
    int endCol = 0;
    for (int col = 0; col < contents[row].size(); ++col) {
      if (isdigit(contents[row][col])) {
        startCol = col;
        while (isdigit(contents[row][col]) && col < contents[row].size()) {
          ++col;
        }
        endCol = col - 1;
        currentNumber.num =
            std::stoi(contents[row].substr(startCol, endCol - startCol + 1));
        currentNumber.pos.y = row;
        currentNumber.pos.xstart = startCol;
        currentNumber.pos.xend = endCol;
        currentNumber.valid = isvalid(contents, currentNumber);
        if (currentNumber.valid) {
          sum += currentNumber.num;
        }
        numbers.push_back(currentNumber);
      }
    }
  }

  std::ofstream outputFile("output.csv");

  // Check if the file was opened successfully
  if (outputFile.is_open()) {
    for (int i = 0; i < numbers.size(); i++) {

      outputFile << i << "," << numbers[i].num << "," << numbers[i].valid << ","
                 << numbers[i].pos.y << "," << numbers[i].pos.xstart << ","
                 << numbers[i].pos.xend << std::endl;
    }
  }

  outputFile.close();

  printf("%c\n", contents[7][58]);

  printf("Sum: %d\n", sum);
  return 0;
}
