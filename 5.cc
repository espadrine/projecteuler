#include <iostream>

unsigned long gcd(unsigned long a, unsigned long b) {
  for (;;) {
    if (a == 0) { return b; }
    b %= a;
    if (b == 0) { return a; }
    a %= b;
  }
}

unsigned long lcm(unsigned long a, unsigned long b) {
  unsigned long denom = gcd(a, b);
  if (denom == 0) { return 0; }
  return a / denom * b;
}

int main() {
  unsigned long leastMultiple = 1;
  for (unsigned long i = 2; i <= 20; i++) {
    leastMultiple = lcm(leastMultiple, i);
  }
  std::cout << leastMultiple << std::endl;
  return 0;
}
