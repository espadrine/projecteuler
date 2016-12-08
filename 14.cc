#include <iostream>

inline unsigned long long collatz(unsigned long long n) {
  if (n % 2 == 0) {
    return n / 2;
  } else {
    return 3 * n + 1;
  }
}

int collatzSeq(unsigned long long term) {
  int length = 1;
  while (term != 1) {
    term = collatz(term);
    length++;
  }
  return length;
}

int main() {
  int longest = 0;
  unsigned long long startLongest = 3;
  for (unsigned long long start = 3; start < 1E6; start++) {
    int length = collatzSeq(start);
    if (length > longest) {
      longest = length;
      startLongest = start;
    }
  }  // About 1s later…
  std::cout << startLongest << std::endl;
  return 0;
}
