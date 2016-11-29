#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

static const unsigned long long PRIME_FACTOR = 600851475143;

std::vector<unsigned long long> primeFactors(unsigned long long multiple) {
  std::vector<unsigned long long> factors;
  for (unsigned long long i = 2; multiple > 1;) {
    // Checking for primality is too slow for such a small number (< 10^100).
    if (multiple % i == 0) {
      factors.push_back(i);
      multiple /= i;
    } else { i++; }
  }
  return factors;
}

int main() {
  auto factors = primeFactors(PRIME_FACTOR);
  std::cout << *std::max_element(factors.begin(), factors.end()) << std::endl;
  return 0;
}
