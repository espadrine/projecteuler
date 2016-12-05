#include <iostream>

int divisors(int num) {
  int divs = 1;
  // Find the prime factorization. Count the power of primes.
  // Divisors(a^p*b^q) = (p+1)*(q+1).
  int power = 0;
  for (int i = 2; num > 1;) {
    if (num % i == 0) {
      num /= i;
      power++;
    } else {
      divs *= power + 1;
      i++;
      power = 0;
    }
  }
  divs *= power + 1;
  return divs;
}

int main() {
  int triNum = 0;
  int i = 1;
  while (divisors(triNum) <= 500) {
    // Compute the next triangle number.
    triNum += i;
    i++;
  }  // About 100ms later…
  std::cout << triNum << std::endl;
  return 0;
}
