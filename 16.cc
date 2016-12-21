#include <iostream>
#include <vector>

int main() {
  std::vector<int> digits = {1};  // eg. 132 = {2, 3, 1}.
  int remainder = 0;
  // Loop over powers of two, starting with 2^0 = 1.
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < digits.size(); j++) {
      digits[j] = digits[j] * 2 + remainder;
      remainder = 0;
      if (digits[j] >= 10) {
        remainder = digits[j] / 10;
        digits[j] %= 10;
      }
    }
    while (remainder > 0) {
      digits.push_back(remainder % 10);
      remainder /= 10;
    }
  }
  int sum = 0;
  for (int digit: digits) { sum += digit; }
  std::cout << sum << std::endl;
  return 0;
}
