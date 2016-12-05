#include <iostream>
#include <cmath>

int divisors(int num) {
  int divs = 2;  // 1 and num are always divisors.
  // All factors in (2, sqrt(num)) are paired with factors in (sqrt(num), num/2)
  int root = std::sqrt(num);
  for (int i = 2; i <= root; i++) {
    if (num % i == 0) {
      divs += 2;
      // We only count one factor when the pair is twice the same number.
      if (i * i == num) { divs--; }
    }
  }
  return divs;
}

int main() {
  int triNum = 0;
  int i = 1;
  while (divisors(triNum) <= 500) {
    // Compute the next triangle number.
    triNum += i;
    i++;
  }  // About 150ms later…
  std::cout << triNum << std::endl;
  return 0;
}
