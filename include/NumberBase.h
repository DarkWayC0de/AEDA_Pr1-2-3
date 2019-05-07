//
// Created by darkwaycode on 18/03/19.
//

#ifndef PR1_NUMBERBASE_H
#define PR1_NUMBERBASE_H
#include "NumberException.h"
#include <iostream>

class NumberBase {
 private:
  int B_;
  int N_;
 public:
  NumberBase(int b, int n);

  virtual ~NumberBase() = default;
  virtual NumberBase* duplicate()const = 0;
  virtual NumberBase* operator+(const NumberBase*)const =0;
  virtual NumberBase* operator-(const NumberBase*)const=0;

 protected:
  virtual void to_base(int) = 0;
  virtual std::ostream& write(std::ostream&) const =0;


};

#endif //PR1_NUMBERBASE_H
