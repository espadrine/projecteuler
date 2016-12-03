#include <iostream>

// There is a trivial cubic solution, an obvious quadratic one. This is linear.
int main() {
  const int SUM = 1000;
  // i^2 + j^2 = k^2 and i+j+k = SUM
  // i^2 + j^2 = k^2 = (SUM - i - j)^2
  //           = SUM^2 + i^2 + j^2 - 2SUMi - 2SUMj + 2ij
  // SUMi + SUMj - ij = SUM^2/2
  // i(SUM-j) + SUMj = SUM^2/2
  // i = (SUM^2/2 - SUMj) / (SUM-j)
  for (int j = 0; j < SUM; j++) {
    int iNum = (SUM * SUM) / 2 - SUM * j;
    int iDenom = SUM - j;
    int i = iNum / iDenom;
    int k = SUM - i - j;
    if (i > j || j > k) { continue; }
    // If i is an integer, so is k and both equalities hold.
    if (iNum % iDenom == 0) {
      std::cout << i * j * k << std::endl;
      return 0;
    }
  }
  return 1;
}
