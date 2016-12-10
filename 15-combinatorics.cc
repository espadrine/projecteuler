#include <iostream>

int main() {
  const int size = 20;  // Size of the lattice.
  unsigned long pathCount = 1;
  // The solution is (2*size choose size). Indeed, if you see it as a sequence
  // of 2*size choices, you merely need to pick "right" size times (and the
  // other times will then be "down").
  // This algorithm is linear, and constant in space.
  for (int i = 0; i < size; i++) {
    pathCount *= (2 * size) - i;
    pathCount /= i + 1;
  }
  std::cout << pathCount << std::endl;
  return 0;
}
