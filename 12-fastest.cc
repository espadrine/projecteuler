#include <iostream>

int divisors(int num) {
  int divs = 2;  // 1 and num are always divisors.
  // All factors in (2, sqrt(num)) are paired with factors in (sqrt(num), num/2)
  // Why is this faster than the math trick? My guess: branch prediction.
  for (int i = 2; i*i <= num; i++) {
    if (num % i == 0) {
      divs += 2;
      // We only count one factor when the pair is twice the same number.
      if (num / i == i) { divs--; }
    }
  }
  return divs;
}

int main() {
  int divs = 0;
  int num = 0;
  for (int i = 1; divs <= 500; i++) {
    // The ith triangular number is (i+1)*i/2.
    // n and n+1 have no factors in common except for 1.
    if (i % 2 == 0) {
      divs = divisors(i / 2) * divisors(i + 1);
    } else {
      divs = divisors((i + 1) / 2) * divisors(i);
    }
    if (divs > 500) { num = i; }
  }  // About 10ms later… ¯\_(ツ)_/¯
  std::cout << (num * (num + 1) / 2) << std::endl;
  return 0;
}
