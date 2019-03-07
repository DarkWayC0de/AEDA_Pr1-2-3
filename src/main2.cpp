//
// Created by darkwaycode on 4/03/19.
// Main pr2
//

#include <iostream>
#include "../include/Number.h"
#include "../include/Number_bin.h"
#define NU 12
#define NU1 12
#define NU2 12

#define BS 2
#define BS1 16
#define BS2 8

//TODO: Main para comprobar que funciona todo sobretodo binario dec y hex
//TODO: Se solicitaran numeros, realizara operaciones y mostrara por pantalla los resultados
//TODO: En caso excepcion derivada de NumberException, se informa al usuario y se continua con la ejecucion
int main() {
  std::cout<<"Introduce el numero a codificar con "<<NU<<" caracteres en la base "<<BS<<" :";
  int a;
  std::cin>>a;
  Number<NU, BS> A(a);
  std::cout<<"El numero "<<a<<" codificado con "<<NU<<" caracteres en la base "<<BS<<" (";
  A.write(std::cout);
  std::cout << ")\n";
  std::cout<<"Introduce el numero a codificar con "<<NU<<" caracteres en la base "<<BS<<" :";
  int b;
  std::cin>>b;
  Number<NU,BS> B(b);
  std::cout<<"El numero "<<b<<" codificado con "<<NU<<" caracteres en la base "<<BS<<" (";
  B.write(std::cout);
  std::cout << ")\n";
  std::cout<<"Introduce el numero a codificar con "<<NU1<<" caracteres en la base "<<BS1<<" :";

  std::cout<<std::endl;
  Number<NU+1,BS> C = A-B;
  C.write(std::cout);
  Number<NU+1,BS> D = A-B;
  D.write(std::cout);

}