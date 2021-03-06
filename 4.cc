#include <iostream>
#include <string>

bool isPalindrome(unsigned long num) {
  std::string digits = std::to_string(num);
  size_t len = digits.size();
  for (int i = 0; i < len; i++) {
    if (digits[i] != digits[len - i - 1]) { return false; }
  }
  return true;
}

int main() {
  const unsigned long LARGEST_3_DIGIT = 999, SMALLEST_3_DIGIT = 100;
  unsigned long largestNum = 0;
  unsigned long n1 = LARGEST_3_DIGIT, n2 = LARGEST_3_DIGIT;
  for (unsigned long n1 = LARGEST_3_DIGIT; n1 >= SMALLEST_3_DIGIT; n1--) {
    for (unsigned long n2 = LARGEST_3_DIGIT; n2 >= SMALLEST_3_DIGIT; n2--) {
      unsigned long num = n1 * n2;
      if (isPalindrome(num)) {
        if (num > largestNum) {
          largestNum = num;
        }
      }
    }
  }
  if (isPalindrome(largestNum)) {
    std::cout << largestNum << std::endl;
  }
  return 0;
}
