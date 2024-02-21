// #include "../include/Pmerge.hpp"

// void Pmerge::jnumdeq(int n) {
//   _seq.push_back(0);
//   _seq.push_back(1);
//   for (int i = 2; i <= n + 1; ++i) {
//     int next = (_seq[i - 1]) + (_seq[i - 2] * 2);
//     _seq.push_back(next);
//   }
// }

// void Pmerge::mainsortdeq(int left, int mid, int right) {
//   std::deque<std::pair<int, int> > _L(mid - left + 1);
//   std::deque<std::pair<int, int> > _R(right - mid);
//   int lsize = _L.size();
//   int rsize = _R.size();
//   for (int i = 0; i < lsize; i++) _L[i] = _deque[left + i];
//   for (int i = 0; i < rsize; i++) _R[i] = _deque[mid + 1 + i];

//   int i = 0;
//   int j = 0;
//   int k = left;

//   while (i < lsize && j < rsize) {
//     if (_L[i].first <= _R[j].first) {
//       _deque[k++] = _L[i++];
//     } else {
//       _deque[k++] = _R[j++];
//     }
//   }
//   while (i < lsize) _deque[k++] = _L[i++];
//   while (j < rsize) _deque[k++] = _R[j++];
// }

// void Pmerge::sortdeque(int left, int right) {
//   if (left < right) {
//     int mid = (left + right) / 2;
//     sortdeque(left, mid);
//     sortdeque(mid + 1, right);
//     mainsortdeq(left, mid, right);
//   }
// }

// void Pmerge::binaryinsertdeq(int value, int left, int right) {
//   if (left >= right) {
//     if (deqmainchain[left] > value) {
//       ic++;
//       deqmainchain.insert(deqmainchain.begin() + left, value);
//     } else {
//       deqmainchain.insert(deqmainchain.begin() + left + 1, value);
//     }
//     return;
//   }
//   int mid = (left + right) / 2;
//   if (deqmainchain[mid] == value) {
//     deqmainchain.insert(deqmainchain.begin() + mid, value);
//     return;
//   } else if (deqmainchain[mid] < value) {
//     binaryinsertdeq(value, mid + 1, right);
//   } else {
//     binaryinsertdeq(value, left, mid);
//   }
// }

// void Pmerge::pendtomaindeq(int idx, int bidx) {
//   while (idx > bidx) {
//     binaryinsertdeq(_vector[idx - 1].second, 0, idx + ic);
//     idx--;
//   }
// }

// void Pmerge::pendingorderdeq(void) {
//   int j = 1;
//   int ssize = _seq.size();
//   while (j < ssize) {
//     if (pairsize < _seq[j]) {
//       pendtomaindeq(pairsize, _seq[j - 1]);
//       if (_deqsize % 2 != 0) {
//         int msize = deqmainchain.size();
//         binaryinsertdeq(oddvec, 0, msize - 1);
//       }
//       break;
//     } else {
//       pendtomaindeq(_seq[j], _seq[j - 1]);
//       j++;
//     }
//   }
// }

// void Pmerge::pairdeque(void) {
//   int mid = deq.size() / 2;
//   for (int i = 0; i < mid; ++i) {
//     if (deq[i] > deq[i + mid])
//       _deque.push_back(std::make_pair(deq[i], deq[i + mid]));
//     else
//       _deque.push_back(std::make_pair(deq[i + mid], vec[i]));
//   }
//   sortdeque(0, mid - 1);
// }

// void Pmerge::pairdeq(void) {
//   pairdeque();
//   jnumdeq(pairsize + 1);
//   for (int i = 0; i < pairsize; ++i) deqmainchain.push_back(_deque[i].first);
//   pendingorderdeq();
// }