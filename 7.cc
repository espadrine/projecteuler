#include <iostream>
#include <vector>

int main() {
  std::vector<int> primes;
  int numberOfPrimes = 0;
  int lastPrime = 2;
  for (int i = 2; numberOfPrimes != 10001; i++) {
    bool isPrime = true;
    for (int prime: primes) {
      if (i % prime == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) {
      primes.push_back(i);
      lastPrime = i;
      numberOfPrimes++;
    }
  }
  std::cout << lastPrime << std::endl;
  return 0;
}
