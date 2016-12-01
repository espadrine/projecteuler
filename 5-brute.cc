#include <iostream>

bool isDivisible(long num, long count) {
  for (long i = 2; i <= count; i++) {
    if ((num % i) != 0) { return false; }
  }
  return true;
}

long numFromMask(long mask) {
  long num = 1;
  for (long i = 1, bitNum = 1; i <= 20; i++, bitNum <<= 1) {
    if ((mask & bitNum) > 0) {
      num *= i;
    }
  }
  return num;
}

int main() {
  const long MAX_MASK = 0xfffff;
  long smallest = numFromMask(MAX_MASK);
  // i is a mask for all the numbers we select: 1 = include 1, 2 = include 2,
  // 3 = include 1 and 2, …
  for (long mask = 1; mask < MAX_MASK; mask++) {
    long num = numFromMask(mask);
    if (isDivisible(num, 20) && num < smallest) {
      smallest = num;
    }
  }
  std::cout << smallest << std::endl;
  return 0;
}
