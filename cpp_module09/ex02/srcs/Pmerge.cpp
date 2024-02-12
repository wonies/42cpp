#include "Pmerge.hpp"

// void Pmerge::mergeFjsort(int low, int high) {
//   int midi = low + (high - low) / 2;
//   int lowmid = midi - low + 1;
//   int highmid = high - midi;
//   std::vector<int> leftarr(lowmid);
//   std::deque<int> rightarr(highmid);
//   for (int i = 0; i < lowmid; i++) leftarr[i] = _vector[low + i];
//   for (int i = 0; i < highmid; i++) rightarr[i] = _vector[midi + 1 + i];

//   int i = 0;
//   int j = 0;
//   int k = low;

//   while (i < lowmid && j < highmid) {
//     if (leftarr[i] >= rightarr[j])
//       _vector[k++] = leftarr[i++];
//     else
//       _vector[k++] = rightarr[j++];
//   }
// }

// void Pmerge::pairsort(int low, int high) {
//   std::cout << low << " ";
//   std::cout << high << std::endl;
//   //   if (!(low + 1 == high)) {
//   //     std::cout << low << " ";
//   //     std::cout << high << std::endl;
//   //     return;
//   //   }
//   if (_vector[low] < _vector[high]) {
//     int temp = _vector[high];
//     _vector[high] = _vector[low];
//     _vector[low] = temp;
//   }
// }

// void Pmerge::pairsort(int low, int high) {
//   int mid = (low + high) / 2;
//   for (int i = low; i < mid; i += 2) {
//     if (_vector[i] > _vector[i + 1]) {
//       int temp = _vector[i];
//       _vector[i] = _vector[i + 1];
//       _vector[i + 1] = temp;
//     }
//   }
// }

void Pmerge::pairsort(int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;
    if (_vector[low] > _vector[mid]) std::swap(_vector[low], _vector[mid]);
    if (_vector[mid + 1] > _vector[high])
      std::swap(_vector[mid + 1], _vector[high]);
    if (_vector[low] > _vector[mid + 1])
      std::swap(_vector[low], _vector[mid + 1]);

    // 이제 _vector[low], _vector[mid], _vector[mid + 1] 중 가장 큰 값이
    // _vector[low]에 위치하게 됩니다.
  }
}

void Pmerge::pairsplit(int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;
    pairsplit(low, mid);
    pairsplit(mid + 1, high);
    pairsort(low, high);
  }
}