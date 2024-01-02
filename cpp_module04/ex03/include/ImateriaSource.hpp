#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

class IMateriaSource {
 public:
  IMateriaSource(void);
  IMateriaSource(**replace parameters **);
  IMateriaSource(IMateriaSource const &instance);
  IMateriaSource &operator=(IMateriaSource const &rhs);
  virtual ~IMateriaSource(void);
  virtual void learnMateria(Amateria *) = 0;
  virtual Amateria *createMateria(std::string const &type) = 0;

 private:
};

#endif