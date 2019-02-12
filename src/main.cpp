#include <iostream>
#include "../include/Number.h"

int main() {

    Number<2,21> A(4);      //representar el decimal 4 en base 21 en 2 caracteres
    Number<5,2> B(5);//representar el decimal 3 en base 2(binario) en 5 caracteres(bits en binario)
    Number<3,10> C(1111);
    A.write(std::cout);
    std::cout<<"\n";
    B.write(std::cout);

    std::cout<<"\n";
    C.write(std::cout);
    return 0;
}