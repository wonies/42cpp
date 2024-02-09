#include <iostream>
#include <vector>

void mergesort(std::vector<long long>& origin, int low, int high) {
  int lside = high - low + 1;
  int rside =
}

void merge(std::vector<long long>& origin, int low, int high) {
  int mid = (low + high) / 2;
  if (low < high) {
    merge(origin, low, mid);
    merge(origin, mid + 1, high);
    mergesort(origin, low, high);
  }
}

int main(void) {
  std::vector<long long> origin = {27, 10, 12, 20, 25, 13, 15, 22};
  merge(origin, 0, 7);
}