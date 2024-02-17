#include "../include/Pmerge.hpp"

void Pmerge::jnum(int n) {
  _sequence.push_back(0);
  _sequence.push_back(1);
  for (int i = 2; i <= n + 1; ++i) {
    int next = _sequence[i - 1] + 2 * _sequence[i - 2];
    _sequence.push_back(next);
  }
}

void Pmerge::comparesort(int left, int mid, int right) {
  std::vector<std::pair<int, int> > _L(mid - left + 1);
  std::vector<std::pair<int, int> > _R(right - mid);
  int lsize = _L.size();
  int rsize = _R.size();
  for (int i = 0; i < lsize; i++) _L[i] = _vector[left + i];
  for (int i = 0; i < rsize; i++) _R[i] = _vector[mid + 1 + i];

  int i = 0;
  int j = 0;
  int k = left;

  while (i < lsize && j < rsize) {
    if (_L[i].first <= _R[j].first) {
      _vector[k++] = _L[i++];
    } else {
      _vector[k++] = _R[j++];
    }
  }
  while (i < lsize) _vector[k++] = _L[i++];
  while (j < rsize) _vector[k++] = _R[j++];
}

void Pmerge::pendtomain(int idx) {
  while (idx == _idx) {
  }
}

void Pmerge::pendorder(void) {
  int i = 0;
  int j = 2;
  _idx = 0;
  while (i < _size) {
    if (_size < _sequence[j])
      break;
    else {
      pendtomain(_sequence[j]);
      _idx = _sequence[j];
    }
  }
}
// void Pmerge::insertsort(int left, int right) {}

void Pmerge::sortpair(int left, int right, int k) {
  if (right - left + 1 <= k)
    insertsort(left, right);
  else if (left < right) {
    int pivot = (left + right) / 2;
    sortpair(left, pivot, k);
    sortpair(pivot + 1, right, k);
    comparesort(left, pivot, right);
  }
}

void Pmerge::pairvec(void) {
  int mid = vec.size() / 2;
  _vector.clear();
  for (int i = 0; i < mid; i++) {
    std::cout << "vec i : " << vec[i] << "\n";
    std::cout << "vec i + mid : " << vec[i + mid] << "\n";
    // _vector[i] = std::make_pair(vec[i], vec[i + mid]);
    if (vec[i] > vec[i + mid])
      _vector.push_back(std::make_pair(vec[i], vec[i + mid]));
    else
      _vector.push_back(std::make_pair(vec[i + mid], vec[i]));

    // _vector.push_back(std::make_pair(vec[i], vec[i + mid]));
    // std::cout << "vector first : " << _vector[i].first
    //           << " vector second : " << _vector[i].second << "\n";
  }

  sortpair(0, mid - 1, 5);
  for (int i = 0; i < mid; i++)
    std::cout << "vector first : " << _vector[i].first
              << " vector second : " << _vector[i].second << "\n";
}

// void insertion(int value) {
//   for (size_t i = 0; i < _size; ++i) {
//     std::pair<int, int> key = _vector[i];
//     int j = i - 1;

//     while (j >= 0 && _vector[j].first < value) {
//       _vector[j + i] = _vector[j];
//       --j;
//     }
//     _vector[j + 1] = key;
//   }
// }

// void Pmerge::jsort(int n) {
//   if (n >= _sequence[n]) {
//     for (int i = 0; i < n; i++) {
//       _vector[i].second
//     }
//   }
// }

void Pmerge::pair(void) {
  _size = vec.size() / 2;
  pairvec();
  jnum(_size);
  // jsort(_size);
  sortpair(0, _size, 5);
  for (int i = 0; i < _size; i++) {
    std::cout << "vector : " << _vector[i].first << std::endl;
    mainchain.push_back(_vector[i].first);
  }
  insertsort(0, 5);
}
