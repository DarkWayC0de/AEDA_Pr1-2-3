#include <iostream>
#include "../include/Number.h"
#define NU 8
#define NU1 2
#define BS 2
#define BS1 16

int main() {

    Number<NU,BS> A(122);
    A.write(std::cout);
    Number<NU1,BS1> B(255);
    std::cout<<"\n";
    B.write(std::cout);
    Number<NU+1,BS> C =  A + B;
    Number<NU+1,BS> D =  A - B;
    Number<NU*NU1,BS> F =  A*B;
    Number<NU*NU1,BS1> G =  B /A;
    std::cout<<"\n";
    C.write(std::cout);
    std::cout<<"\n";
    D.write(std::cout);
    std::cout<<"\n";
    F.write(std::cout);
    std::cout<<"\n";
    G.write(std::cout);

    return 0;
}