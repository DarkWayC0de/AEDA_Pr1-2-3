#include <iostream>
#include "../include/Number.h"
#define NU 5
#define NU1 5
#define BS 16
#define BS1 2

int main() {
try {
    std::cout<<"Introduce el numero a codificar con "<<NU<<" caracteres en la base "<<BS<<" :";
    int a;
    std::cin>>a;
    Number<NU, BS> A(a);
    std::cout<<"El numero "<<a<<" codificado con "<<NU<<" caracteres en la base "<<BS<<" (";
    A.write(std::cout);
    std::cout << ")\n";
    std::cout<<"Introduce el numero a codificar con "<<NU1<<" caracteres en la base "<<BS1<<" :";
    int b;
    std::cin>>b;
    Number<NU1, BS1> B(b);
    std::cout<<"El numero "<<b<<" codificado con "<<NU1<<" caracteres en la base "<<BS1<<" (";
    B.write(std::cout);
    std::cout << ")\n";
    std::cout<< "\nProcedemos a realizar las operaciones aritmeticas\n"
                "Procedemos a realizar la suma de los dos numeros codificados\n";
    Number<NU + 1, BS> C = A + B;
    std::cout<<"El numero (";
    A.write(std::cout);
    std::cout<<") en base "<<BS<<" + (";
    B.write(std::cout);
    std::cout<<") en base "<<BS1<<" = (";
    C.write(std::cout);
    std::cout<<") en base "<<BS<<"\n";
    std::cout << "Procedemos a realizar la resta de los dos numeros codificados\n";
    Number<NU + 1, BS> D = A - B;
    std::cout<<"El numero (";
    A.write(std::cout);
    std::cout<<") en base "<<BS<<" - (";
    B.write(std::cout);
    std::cout<<") en base "<<BS1<<" = (";
    D.write(std::cout);
    std::cout<<") en base "<<BS<<"\n";
    std::cout << "Procedemos a realizar la multiplicacion de los dos numeros codificados\n";
    Number<NU * NU1, BS> F = A * B;
    std::cout<<"El numero (";
    A.write(std::cout);
    std::cout<<") en base "<<BS<<" * (";
    B.write(std::cout);
    std::cout<<") en base "<<BS1<<" = (";
    F.write(std::cout);
    std::cout<<") en base "<<BS<<"\n";
    std::cout << "Procedemos a realizar la divicion de los dos numeros codificados\n";
    Number<NU * NU1, BS> G = A / B;
    Number<NU * NU1, BS> H = A % B;
    std::cout<<"El numero (";
    A.write(std::cout);
    std::cout<<") en base "<<BS<<" * (";
    B.write(std::cout);
    std::cout<<") en base "<<BS1<<" = (";
    G.write(std::cout);
    std::cout<<") en base "<<BS
    <<"\n"
      "Y el resto dicha divicion es (";
    H.write(std::cout);
    std::cout<<") en base "<<BS<<"\n";
    std::cout << "\nProcedemos a realizar uso de los operadores relacionales\n"
                 "Comprobacion de igualdad\n";
    std::cout<<"El numero (";
    A.write(std::cout);
    std::cout<<") en base "<<BS<<" == (";
    B.write(std::cout);
    std::cout<<") en base "<<BS1<<" ?\n";
    if (A==B){
        std::cout<<"Si, son iguales\n";
    }else{
        std::cout<<"No, son distintos\n";
    }
    std::cout<<"Comprobacion de no igualdad\n";
    std::cout<<"El numero (";
    A.write(std::cout);
    std::cout<<") en base "<<BS<<" != (";
    B.write(std::cout);
    std::cout<<") en base "<<BS1<<" ?\n";
    if (A!=B){
        std::cout<<"Si, son distintos\n";
    }else{
        std::cout<<"No, son iguales\n";
    }
    std::cout<<"Comprobacion superioridad\n";
    std::cout<<"El numero (";
    A.write(std::cout);
    std::cout<<") en base "<<BS<<" > (";
    B.write(std::cout);
    std::cout<<") en base "<<BS1<<" ?\n";
    if (A>B){
        std::cout<<"Si, es mayor\n";
    }else{
        std::cout<<"No, no es mayor\n";
    }
    std::cout<<"Comprobacion superioridad o igualdad\n";
    std::cout<<"El numero (";
    A.write(std::cout);
    std::cout<<") en base "<<BS<<" >= (";
    B.write(std::cout);
    std::cout<<") en base "<<BS1<<" ?\n";
    if (A>=B){
        std::cout<<"Si, es  mayor o igual\n";
    }else{
        std::cout<<"No, no es mayor ni igual\n";
    }
    std::cout<<"Comprobacion inferioridad\n";
    std::cout<<"El numero (";
    A.write(std::cout);
    std::cout<<") en base "<<BS<<" < (";
    B.write(std::cout);
    std::cout<<") en base "<<BS1<<" ?\n";
    if (A<B){
        std::cout<<"Si, es menor \n";
    }else{
        std::cout<<"No, no es menor\n";
    }
    std::cout<<"Comprobacion inferioridad o igualdad\n";
    std::cout<<"El numero (";
    A.write(std::cout);
    std::cout<<") en base "<<BS<<" <= (";
    B.write(std::cout);
    std::cout<<") en base "<<BS1<<" ?\n";
    if (A<=B){
        std::cout<<"Si, es menor o igual\n";
    }else{
        std::cout<<"No, no es menor ni igual\n";
    }


}
catch (std::system_error& e) {
    std::cerr << "Pr1 : " << e.what() << "\n";
}
catch (...){
    std::cerr<<"Pr1: Error desconocido";
    return 1;
}
    return 0;
}