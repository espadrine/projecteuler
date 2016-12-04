#include <iostream>
#include <bitset>

int main() {
  const int LIMIT = 2E6;
  std::bitset<LIMIT> primes;
  primes.set();
  primes.reset(0);
  primes.reset(1);
  long sum = 0;
  for (long i = 2; i < LIMIT; i++) {
    if (!primes[i]) { continue; }
    else {
      for (long j = i; j < LIMIT; j += i) {
        primes.reset(j);
      }
      sum += i;
    }
  }
  std::cout << sum << std::endl;
  return 0;
}
