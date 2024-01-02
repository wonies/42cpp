#include "Amateria.hpp"

Amateria::Amateria(void) {}

Amateria::Amateria(std::string const &type)
    : _type(type) {
}  //  ㅊㅜ사ㅇ클래스를 바탕으로.. 자식이 어떤 생성자 불러올지 결정함

Amateria::Amateria(Amateria const &instance) {}

Amateria &Amateria::operator=(const Ice &rhs) {
  if (this != &rhs) {
    this->type = rhs.type;
  }
  return type;
}

Amateria::~Amateria(void) {}

std::string const Amateria::&getType() const { return type; }
