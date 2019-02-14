#include <iostream>
#include "../include/Number.h"
#define NU 5
#define BS 16

int main() {

    Number<NU,BS> A(10);
    A.write(std::cout);
    Number<NU,BS> B(3);
    Number<NU+1,BS> C =  A + B;
    std::cout<<"\n";
    C.write(std::cout);


    return 0;
}