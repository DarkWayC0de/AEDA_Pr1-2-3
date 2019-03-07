//
// Created by darkwaycode on 6/03/19.
//

#ifndef PR1_NUMBEREXCEPTION_H
#define PR1_NUMBEREXCEPTION_H
#include <exception>
class NumberException: public std::exception {

};
class base_grande_exception: public NumberException{
 public:
  const  char* what() const noexcept override;
};
class fuera_rango_exception: public NumberException{
 public:
  const char* what() const noexcept override;
};
 class base_negativa : public NumberException{
  public:
   const char* what() const noexcept override;
 };
class divzero : public NumberException{
 public:
  const char* what() const noexcept override;
};

#endif //PR1_NUMBEREXCEPTION_H
