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

void Pmerge::pendtomain(int idx, int bidx) {
  while (idx > bidx) {
    std::cout << "idx : " << idx << std::endl;
    std::cout << "b_idx : " << bidx << std::endl;
    insertsort(_vector[idx - 1].second);
    std::vector<int>::iterator it = mainchain.begin();
    while (it != mainchain.end()) {
      std::cout << "mainchain's val : " << *it << " ";
      it++;
    }
    std::cout << "\n";
    idx--;
  }
}

void Pmerge::pendorder(void) {
  int j = 1;  // 시작 인덱스를 1로 설정
  int ssize = _sequence.size();
  while (j < ssize) {  // _sequence 범위를 넘지 않도록 조건 변경
    if (_size < _sequence[j]) {
      break;  // _size가 현재 확인하는 Jacobsthal 수보다 작으면 반복 종료
    } else {
      pendtomain(_sequence[j], _sequence[j - 1]);
      j++;  // 다음 Jacobsthal 수 확인을 위해 인덱스 증가
    }
  }
}
void Pmerge::insertsort(int value) {
  // int n = mainchain.size();
  std::vector<int>::iterator it = mainchain.begin();
  while (it != mainchain.end()) {
    if (value > *it)
      ++it;
    else {
      mainchain.insert(it, value);
      return;
    }
  }
  mainchain.push_back(value);
}

void Pmerge::sortpair(int left, int right, int k) {
  if (left < right) {
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
    if (vec[i] > vec[i + mid])
      _vector.push_back(std::make_pair(vec[i], vec[i + mid]));
    else
      _vector.push_back(std::make_pair(vec[i + mid], vec[i]));
  }

  sortpair(0, mid - 1, 5);
  for (int i = 0; i < mid; i++)
    std::cout << "vector first : " << _vector[i].first
              << " vector second : " << _vector[i].second << "\n";
}

void Pmerge::printvector(void) {
  int _vecmainchain = mainchain.size();
  std::cout << "After: ";
  for (int i = 0; i < _vecmainchain; i++) {
    std::cout << mainchain[i] << " ";
  }
  std::cout << "\n";
}

void Pmerge::pair(void) {
  _vecstart = clock();
  _size = vec.size() / 2;
  int _vecsize = vec.size();

  std::cout << "Before: ";
  for (int i = 0; i < _vecsize; ++i) std::cout << vec[i] << " ";
  std::cout << "\n";
  pairvec();
  jnum(_size);

  for (int i = 0; i < _size; i++) {
    mainchain.push_back(_vector[i].first);
    std::cout << "mainchain : " << mainchain[i] << std::endl;
  }
  pendorder();
  _vecend = clock();
}

bool Pmerge::input(int ac, char **av) {
  std::cout << "hello\n";
  if (ac == 2) {
    int i = 0;
    // int flag = 0;
    std::string systeminput;
    while (av[1][i] != '\0') {
      systeminput += av[1][i];
      ++i;
    }
    FILE *pipe = popen(systeminput.c_str(), "r");
    if (!pipe) throw std::runtime_error("Error: can't read the command");
    char buf[128];
    while (fgets(buf, sizeof(buf), pipe) != NULL) {
      std::istringstream iss(buf);
      int num = 0;
      while (iss >> num) vec.push_back(num);
    }
    // if (flag == 0) {
    //   // int result = system(av[1]);
    //   // if (result != 0) throw std::runtime_error("Error: not enough
    //   // arguments");
    //   FILE *pipe = popen(systeminput.c_str(), "r");
    //   if (!pipe) throw std ::runtime_error("Error: can't not read the
    //   command"); char buffer[128]; while (fgets(buffer, sizeof(buffer), pipe)
    //   != NULL) {
    //     std::istringstream iss(buffer);
    //     int num = 0;
    //     std::cout << "\nnum :" << num << std::endl;
    //     while (iss >> num) vec.push_back(num);
    //   }
    // }
  }
  return 1;
}

void Pmerge::excute(int ac, char **av) {
  input(ac, av);
  int vecsize = vec.size();
  std::cout << "vec size : " << vecsize << std::endl;
  clock_t vecstart = clock();
  // vector(ac, av);
  clock_t vecend = clock();
  double usec = (((double)(vecend - vecstart)) * 1000 / CLOCKS_PER_SEC);
  std::cout << "Time to process a range of " << vec.size()
            << " elements with std::vector : " << usec << " us\n";
}