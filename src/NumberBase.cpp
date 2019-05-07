//
// Created by darkwaycode on 18/03/19.
//

#include "../include/NumberBase.h"

NumberBase::NumberBase(int b, int n):B_(b),N_(n){
  if(B_<=1 ||N_<=1){
    throw wrong_number_exception();
  }
}