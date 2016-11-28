#include <iostream>

int main() {
  int a = 1, b = 2;
  int sum = 0;
  for (int i = 0; a < 4000000; i++) {
    if (a % 2 == 0) {
      sum += a;
    }
    int tmp = b;
    b += a;
    a = tmp;
  }
  std::cout << sum << std::endl;
  return 0;
}
