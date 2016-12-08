#include <iostream>
#include <vector>

inline unsigned long long collatz(unsigned long long n) {
  if (n % 2 == 0) {
    return n / 2;
  } else {
    return 3 * n + 1;
  }
}

static std::vector<int> cache;
int collatzSeq(unsigned long long term) {
  unsigned long long start = term;
  int length = 1;
  while (term != 1) {
    term = collatz(term);
    // This is not well decoupled (it depends on the way the loop is built in
    // main(), but it is fast.
    if (term < start) {
      return length + cache[term];
    }
    length++;
  }
  return length;
}

int main() {
  cache.push_back(0);
  int longest = 0;
  unsigned long long startLongest = 3;
  for (unsigned long long start = 1; start < 1E6; start++) {
    int length = collatzSeq(start);
    cache.push_back(length);
    if (length > longest) {
      longest = length;
      startLongest = start;
    }
  }  // About 60ms later…
  std::cout << startLongest << std::endl;
  return 0;
}
