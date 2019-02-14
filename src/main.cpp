#include <iostream>
#include "../include/Number.h"
#define NU 5
#define BS 2

int main() {

    Number<NU,BS> A(31);
    A.write(std::cout);
    Number<NU,BS> B(31);
    Number<NU+1,BS> C =  A + B;
    Number<NU+1,BS> D =  A - B;
    Number<NU*NU,BS> F =  A * B;
    std::cout<<"\n";
    C.write(std::cout);
    std::cout<<"\n";
    D.write(std::cout);
    std::cout<<"\n";
    F.write(std::cout);

    return 0;
}