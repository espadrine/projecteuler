#include <iostream>

int main() {
  unsigned long sumOfSquares = 0;
  unsigned long sum = 0;
  for (unsigned long i = 1; i <= 100; i++) {
    sumOfSquares += i * i;
    sum += i;
  }
  unsigned long difference = sum * sum - sumOfSquares;
  std::cout << difference << std::endl;
  return 0;
}
