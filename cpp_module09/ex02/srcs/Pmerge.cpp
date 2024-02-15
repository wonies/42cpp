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

// void Pmerge::pairsort(int low, int high) {
//   if (low < high) {
//     int mid = (low + high) / 2;
//     if (_vector[low] > _vector[mid]) std::swap(_vector[low], _vector[mid]);
//     if (_vector[mid + 1] > _vector[high])
//       std::swap(_vector[mid + 1], _vector[high]);
//     if (_vector[low] > _vector[mid + 1])
//       std::swap(_vector[low], _vector[mid + 1]);

//     // 이제 _vector[low], _vector[mid], _vector[mid + 1] 중 가장 큰 값이
//     // _vector[low]에 위치하게 됩니다.
//   }
// }

// void Pmerge::pairsplit(int low, int high) {
//   if (low < high) {
//     int mid = (low + high) / 2;
//     pairsplit(low, mid);
//     pairsplit(mid + 1, high);
//     pairsort(low, high);
//   }
// }

// void Pmerge::pairsplit(void) {
//   int i = 0;
//   while (i < _size - 1) {
//     if (_vector[i] <= _vector[i + 1]) std::swap(_vector[i], _vector[i + 1]);
//     i += 2;
//   }
//   // i = 0;
//   // while (i < _size - 3) {
//   //   if (_vector[i] >= _vector[i + 2]) {
//   //     std::swap(_vector[i], _vector[i + 2]);
//   //     std::swap(_vector[i + 1], _vector[i + 3]);
//   //   }
//   //   i += 2;
//   // }
//   if (_size % 2 == 0) {
//     for (int i = 0; i < _size - 1; i++) {
//       _mainchain.push_back(_vector[i++]);
//       _pending.push_back(_vector[i]);
//     }
//   } else {
//     for (int i = 0; i < _size - 2; i++) {
//       _mainchain.push_back(_vector[i++]);
//       _pending.push_back(_vector[i]);
//     }
//     _pending.push_back(_vector.back());
//   }
//   for (int i = 0; i < _size / 2; i++) {
//     std::cout << "main chain : " << _mainchain[i] << " ";
//     std::cout << "pending chain : " << _pending[i] << "\n";
//   }
//   // pendtomain();
// }

// std::vector<int> Pmerge::jacobsthal(int n) {
//   std::vector<int> sequence;

//   sequence.push_back(0);
//   sequence.push_back(1);

//   for (int i = 2; i < n; i++) {
//     int next = sequence[i - 1] + 2 * sequence[i - 2];
//     sequence.push_back(next);
//   }
//   return sequence;
// }

// void Pmerge::pendtomain(void) {
//   std::vector<int> jacobsthal_sequence = jacobsthal(_pending.size() + 1);

//   for (size_t i = 0; i < _pending.size(); ++i) {
//     int num = _pending[i];
//     size_t index = 0;
//     while (index < jacobsthal_sequence.size() &&
//            jacobsthal_sequence[index] < num) {
//       ++index;
//     }
//     _mainchain.insert(_mainchain.begin() + index, num);
//   }
// }

// void Pmerge::pairsplit(void) {
//   if (low < high) {
//   }
// }

void Pmerge::pairsort(int low, int high) {
  std::cout << low << " " << high << "\n";
}

void Pmerge::pair(int low, int high, int depth) {
  if (depth == 6) return;
  if (low < high) {
    int mid = (low + high) / 2;
    pair(low, mid, depth + 1);
    pair(mid, high, depth + 1);
    if (low + 1 == high) pairsort(low, high);
  }
}
