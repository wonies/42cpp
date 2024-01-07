#include "Bureaucrat.hpp"

void test1(void);
void test2(void);
void test3(void);

int main(void) {
  test1();
  test2();
  test3();

  return 0;
}

void test1(void) {
  try {
    Bureaucrat officer("wonie", 1);
    Form form("주차 위반 건에 관하여", 5, 120);
    form.beSigned(officer);
    officer.signForm();

  } catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}

void test2(void) {
  try {
    Bureaucrat officer("konie", 10);
    Form form("식품 위반 건에 관하여", 3, 5);
    form.beSigned(officer);
    officer.signForm();
    // std::cout << officer << std::endl;
  } catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}

void test3(void) {
  try {
    Bureaucrat officer("monie", 149);
    Form from("주류 위반 건에 관하여", 130, 150);
    officer.setDownGrade();
    officer.setDownGrade();
    // std::cout << officer << std::endl;
  } catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}
