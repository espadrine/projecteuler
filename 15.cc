#include <iostream>

// Without the cache, it takes ½h and has factorial complexity.
// With it, a millisecond and quadratic, but quadratic in space..
static unsigned long *cache;
unsigned long pathCount(int, int, int);
inline unsigned long cachedPathCount(int col, int row, int size) {
  int cacheIndex = (col + 1) + row * size;
  unsigned long cached = cache[cacheIndex];
  unsigned long pc;
  if (cached != -1) {
    return cached;
  } else {
    pc = pathCount(col, row, size);
    cache[cacheIndex] = pc;
    return pc;
  }
}

// col and row are 0-indexed starting from the top left.
unsigned long pathCount(int col, int row, int size) {
  bool lastCol = (col == size - 1);
  bool lastRow = (row == size - 1);
  if (lastCol || lastRow) {
    return 1;
  } else {
    unsigned long count = 0;
    int pc;  // path count
    int cacheIndex;
    if (!lastCol) {  // Go right.
      count += cachedPathCount(col + 1, row, size);
    }
    if (!lastRow) {  // Go down.
      count += cachedPathCount(col, row + 1, size);
    }
    return count;
  }
}

int main() {
  const int size = 20;  // Size of the lattice.
  int cacheSize = (size + 1) * (size + 1);
  cache = new unsigned long[cacheSize];
  for (int i = 0; i < cacheSize; i++) { cache[i] = -1; }
  std::cout << pathCount(0, 0, size + 1) << std::endl;
  delete[] cache;
  return 0;
}
