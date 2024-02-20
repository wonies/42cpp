#include "../include/Pmerge.hpp"

// void Pmerge::jnum(int n) {
//   _sequence.push_back(0);
//   _sequence.push_back(1);
//   for (int i = 2; i <= n + 1; ++i) {
//     int next = _sequence[i - 1] + 2 * _sequence[i - 2];
//     _sequence.push_back(next);
//   }
// }

// void Pmerge::comparesort(int left, int mid, int right) {
//   std::vector<std::pair<int, int> > _L(mid - left + 1);
//   std::vector<std::pair<int, int> > _R(right - mid);
//   int lsize = _L.size();
//   int rsize = _R.size();
//   for (int i = 0; i < lsize; i++) _L[i] = _vector[left + i];
//   for (int i = 0; i < rsize; i++) _R[i] = _vector[mid + 1 + i];

//   int i = 0;
//   int j = 0;
//   int k = left;

//   while (i < lsize && j < rsize) {
//     if (_L[i].first <= _R[j].first) {
//       _vector[k++] = _L[i++];
//     } else {
//       _vector[k++] = _R[j++];
//     }
//   }
//   while (i < lsize) _vector[k++] = _L[i++];
//   while (j < rsize) _vector[k++] = _R[j++];
// }

// void Pmerge::pendtomain(int idx, int bidx) {
//   while (idx > bidx) {
//     binaryinsert(_vector[idx - 1].second, 0, idx - 1);
//     std::vector<int>::iterator it = mainchain.begin();
//     while (it != mainchain.end()) {
//       std::cout << "mainchain's val : " << *it << " ";
//       it++;
//     }
//     std::cout << "\n";
//     idx--;
//   }
// }

// void Pmerge::pendorder(void) {
//   int j = 1;
//   int ssize = _sequence.size();
//   while (j < ssize) {
//     if (_size < _sequence[j]) {
//       break;
//     } else {
//       pendtomain(_sequence[j], _sequence[j - 1]);
//       j++;
//     }
//   }
// }

// void Pmerge::binaryinsert(int value, int left, int right) {
//   if (left >= right) {
//     mainchain.insert(mainchain.begin() + left, value);
//     return;
//   }
//   int mid = left + (right - left) / 2;
//   if (mainchain[mid] < value) {
//     binaryinsert(value, left, mid);
//   } else
//     binaryinsert(value, mid + 1, right);
// }

// // void Pmerge::insertsort(int value, int right) {
// //   std::vector<int>::iterator it = mainchain.begin();
// //   while (it != mainchain.end()) {
// //     if (value > *it)
// //       ++it;
// //     else {
// //       mainchain.insert(it, value);
// //       return;
// //     }
// //   }
// //   mainchain.push_back(value);
// // }

// void Pmerge::sortpair(int left, int right, int k) {
//   if (left < right) {
//     int pivot = (left + right) / 2;
//     sortpair(left, pivot, k);
//     sortpair(pivot + 1, right, k);
//     comparesort(left, pivot, right);
//   }
// }

// void Pmerge::pairvec(void) {
//   int mid = vec.size() / 2;
//   _vector.clear();
//   for (int i = 0; i < mid; i++) {
//     std::cout << "vec i : " << vec[i] << "\n";
//     std::cout << "vec i + mid : " << vec[i + mid] << "\n";
//     if (vec[i] > vec[i + mid])
//       _vector.push_back(std::make_pair(vec[i], vec[i + mid]));
//     else
//       _vector.push_back(std::make_pair(vec[i + mid], vec[i]));
//   }

//   sortpair(0, mid - 1, 5);
//   for (int i = 0; i < mid; i++)
//     std::cout << "vector first : " << _vector[i].first
//               << " vector second : " << _vector[i].second << "\n";
// }

// void Pmerge::printvector(void) {
//   int _vecmainchain = mainchain.size();
//   std::cout << "After: ";
//   for (int i = 0; i < _vecmainchain; i++) {
//     std::cout << mainchain[i] << " ";
//   }
//   std::cout << "\n";
// }

// void Pmerge::pair(void) {
//   _size = vec.size() / 2;
//   std::cout << "Before: ";
//   pairvec();
//   jnum(_size);

//   for (int i = 0; i < _size; i++) {
//     mainchain.push_back(_vector[i].first);
//   }
//   pendorder();
// }

// bool Pmerge::input(int ac, char **av) {
//   if (ac == 2) {
//     int i = 0;
//     int numflag = 0;
//     std::string systeminput;
//     while (av[1][i] != '\0') {
//       systeminput += av[1][i];
//       if (av[1][i] < 48 || av[1][i] > 57) numflag = 1;
//       ++i;
//     }
//     if (numflag == 1) {
//       FILE *pipe = popen(systeminput.c_str(), "r");
//       if (!pipe) throw std::runtime_error("Error: can't read the command");
//       char buf[128];
//       while (fgets(buf, sizeof(buf), pipe) != NULL) {
//         std::istringstream iss(buf);
//         int num = 0;
//         while (iss >> num) vec.push_back(num);
//       }
//     } else {
//       throw std::runtime_error("Error: can't sort");
//     }
//   } else {
//     int i = 0;
//     char *endptr = NULL;
//     while (av[++i]) {
//       double input = strtod(av[i], &endptr);
//       if (*endptr != '\0') throw std::runtime_error("Error: not valid
//       input"); vec.push_back(input);
//     }
//   }
//   return 1;
// }

// void Pmerge::excute(int ac, char **av) {
//   input(ac, av);
//   int _vecsize = vec.size();
//   // std::cout << "vec size : " << vecsize << std::endl;
//   clock_t vecstart = clock();
//   // vector();
//   clock_t vecend = clock();
//   double usec = (((double)(vecend - vecstart)) * 1000 / CLOCKS_PER_SEC);
//   std::cout << "Time to process a range of " << _vecsize
//             << " elements with std::vector : " << usec << " us\n";
// }

// void Pmerge::vector(void) {}

void Pmerge::prints(void) {
  int mid = _vecsize;
  for (int i = 0; i < mid / 2; ++i) {
    std::cout << _vector[i].first << " ";
    std::cout << _vector[i].second << " ";
  }  // pair끼리 잘 배열되어있는 지 확인
}

void Pmerge::jnum(int n) {
  _sequence.push_back(0);
  _sequence.push_back(1);
  for (int i = 2; i <= n + 1; ++i) {
    int next = (_sequence[i - 1]) + (_sequence[i - 2] * 2);
    _sequence.push_back(next);
  }
}

void Pmerge::mainsort(int left, int mid, int right) {
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

void Pmerge::binaryinsert(int value, int left, int right) {
  if (left >= right) {
    if (mainchain[left] > value) {
      k++;
      mainchain.insert(mainchain.begin() + left, value);
    } else {
      mainchain.insert(mainchain.begin() + left + 1, value);
    }
    return;
  }
  int mid = (left + right) / 2;
  if (mainchain[mid] == value) {
    // std::cout << "mid == value / mainchain mid : " << mainchain[mid]
    //           << std::endl;

    mainchain.insert(mainchain.begin() + mid, value);
    return;
  } else if (mainchain[mid] < value) {
    // std::cout << "mid value / mainchain mid : " << mainchain[mid] <<
    // std::endl;
    binaryinsert(value, mid + 1, right);
  } else {
    // std::cout << "left mid  / mainchain mid : " << mainchain[mid] <<
    // std::endl;
    binaryinsert(value, left, mid);
  }
}
// void Pmerge::binaryinsert(int value, int left, int right) {
//   if (left >= right) {
//     mainchain.insert(mainchain.begin() + left, value);
//     return;
//   }
//   int mid = (left + right) / 2;
//   if (mainchain[mid] < value) {
//     binaryinsert(value, left, mid);
//   } else
//     binaryinsert(value, mid + 1, right);
// }

void Pmerge::pendtomain(int idx, int bidx) {
  while (idx > bidx) {
    binaryinsert(_vector[idx - 1].second, 0, idx + k);
    idx--;
  }
}

void Pmerge::pendingorder(void) {
  int j = 1;
  int ssize = _sequence.size();
  std::cout << "ssize : " << ssize << std::endl;
  while (j < ssize) {
    if (pairsize < _sequence[j]) {
      pendtomain(pairsize, _sequence[j - 1]);
      std::cout << "pair size : " << pairsize << std::endl;
      break;
    } else {
      pendtomain(_sequence[j], _sequence[j - 1]);
      j++;
    }
  }
}

void Pmerge::sortpair(int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    sortpair(left, mid);
    sortpair(mid + 1, right);
    mainsort(left, mid, right);
  }
}

void Pmerge::pairvector(void) {
  int mid = vec.size() / 2;
  for (int i = 0; i < mid; i++) {
    if (vec[i] > vec[i + mid])
      _vector.push_back(std::make_pair(vec[i], vec[i + mid]));
    else
      _vector.push_back(std::make_pair(vec[i + mid], vec[i]));
  }
  sortpair(0, mid - 1);
  prints();
  // for (int i = 0; i < mid; ++i) {
  //   std::cout << _vector[i].first << " ";
  //   std::cout << _vector[i].second << " ";
  // }  // pair끼리 잘 배열되어있는 지 확인
#ifdef DEBUG
  std::cout << std::endl;
  std::cout << "_vector info" << std::endl;
  std::cout << "_vector first:  ";
  for (int i = 0; i < mid; ++i) std::cout << _vector[i].first << " ";
  std::cout << std::endl;
  std::cout << "_vector second: ";
  for (int i = 0; i < mid; ++i) std::cout << _vector[i].second << " ";
  std::cout << std::endl;
#endif
}

void Pmerge::pair(void) {
  pairsize = vec.size() / 2;
  pairvector();
  jnum(pairsize + 1);
  for (int i = 0; i < pairsize; ++i) mainchain.push_back(_vector[i].first);
  pendingorder();
}

bool Pmerge::input(int ac, char **av) {
  if (ac == 2) {
    int i = 0;
    int numflag = 0;
    std::string systeminput;
    while (av[1][i] != '\0') {
      systeminput += av[1][i];
      if (av[1][i] < 48 || av[1][i] > 57) numflag = 1;
      ++i;
    }
    if (numflag == 1) {
      FILE *pipe = popen(systeminput.c_str(), "r");
      if (!pipe) throw std::runtime_error("Error: can't read the command");
      char buf[128];
      while (fgets(buf, sizeof(buf), pipe) != NULL) {
        std::istringstream iss(buf);
        int num = 0;
        while (iss >> num) vec.push_back(num);
      }
    } else {
      throw std::runtime_error("Error: can't sort");
    }
  } else {
    int i = 0;
    char *endptr = NULL;
    while (av[++i]) {
      double input = strtod(av[i], &endptr);
      if (*endptr != '\0') throw std::runtime_error("Error: not valid input");
      vec.push_back(input);
    }
    int _vecsize = vec.size();
    i = 0;
    std::cout << "Before: ";
    while (i < _vecsize) {
      std::cout << vec[i++] << " ";
    }
    std::cout << "\n";
  }
  return true;
}

void Pmerge::execute(int ac, char **av) {
  input(ac, av);
  int _vecsize = vec.size();
  clock_t vecstart = clock();
  k = 0;
  pair();
  clock_t vecend = clock();
  std::cout << "After: ";
  int i = -1;
  while (++i < _vecsize) std::cout << mainchain[i] << " ";
  double usec = (((double)(vecend - vecstart)) * 1000 / CLOCKS_PER_SEC);
  std::cout << "Time to process a range of " << _vecsize
            << " elements with std::vector : " << usec << " us\n";
}