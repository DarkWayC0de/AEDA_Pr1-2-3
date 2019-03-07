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

#define BS 16
#define BS1 16
#define BS2 8


int main() {
  std::cout<<"Introduce el numero a codificar con "<<NU<<" caracteres en la base "<<BS<<" :";
  int a;
  std::cin>>a;
  try {
    Number<NU, BS> A(a);
      std::cout << "El numero " << a << " codificado con " << NU << " caracteres en la base " << BS << " (";
      try{
      A.write(std::cout);
    }catch (NumberException& exception) {
      std::cout << "\nSe ha producido el error " << exception.what() << "\n\n";
    }
    std::cout << ")\n";
    std::cout << "Introduce el numero a codificar con " << NU << " caracteres en la base " << BS << " :";
    int b;
    std::cin >> b;
    try {
      Number<NU, BS> B(b);
      std::cout << "El numero " << b << " codificado con " << NU << " caracteres en la base " << BS << " (";
      try {
        B.write(std::cout);
      }catch (NumberException& exception) {
        std::cout << "\nSe ha producido el error " << exception.what() << "\n\n";
      }
      std::cout << ")\n";

      std::cout << "Procedemos a realizar la divicion de los dos numeros codificados\n";
      try {
        Number<NU * NU, BS> G = A / B;
        Number<NU * NU, BS> H = A % B;
        std::cout << "El numero (";
        try {
          A.write(std::cout);
        }catch(NumberException& exception) {
          std::cout << "\nSe ha producido el error " << exception.what() << "\n\n";
        }
        std::cout << ") en base " << BS << " / (";
        try {
          B.write(std::cout);
        }catch(NumberException& exception) {
          std::cout << "\nSe ha producido el error " << exception.what() << "\n\n";
        }
        std::cout << ") en base " << BS << " = (";
        try {
          G.write(std::cout);
        }catch(NumberException& exception) {
          std::cout << "\nSe ha producido el error " << exception.what() << "\n\n";
        }
        std::cout << ") en base " << BS
                  << "\n"
                     "Y el resto dicha divicion es (";
        try {
          H.write(std::cout);
        }catch(NumberException& exception) {
          std::cout << "\nSe ha producido el error " << exception.what() << "\n\n";
        }
        std::cout << ") en base " << BS << "\n";

      }catch(NumberException& exception) {
        std::cout << "\nSe ha producido el error " << exception.what() << "\n\n";
      }

      std::cout << "Procedemos a realizar la suma de los dos numeros codificados\n";
      try {
        Number<NU + 1, BS> C = A + B;
        std::cout << "El numero (";
        try {
          A.write(std::cout);
        }catch(NumberException& exception) {
          std::cout << "\nSe ha producido el error " << exception.what() << "\n\n";
        }
        std::cout << ") en base " << BS << " + (";
        try {
          B.write(std::cout);
        }catch(NumberException& exception) {
          std::cout << "\nSe ha producido el error " << exception.what() << "\n\n";
        }
        std::cout << ") en base " << BS << " = (";
        try {
          C.write(std::cout);
        }catch(NumberException& exception) {
          std::cout << "\nSe ha producido el error " << exception.what() << "\n\n";
        }
        std::cout << ") en base " << BS << "\n";
      }catch (NumberException& exception) {
        std::cout << "\nSe ha producido el error " << exception.what() << "\n\n";
      }
      std::cout << "Procedemos a realizar la resta de los dos numeros codificados\n";
      try {
        Number<NU + 1, BS> D = A - B;
        std::cout << "El numero (";
        try{
          A.write(std::cout);
        }catch(NumberException& exception) {
          std::cout << "\nSe ha producido el error " << exception.what() << "\n\n";
        }
        std::cout << ") en base " << BS << " - (";
        try{
          B.write(std::cout);
        }catch(NumberException& exception) {
          std::cout << "\nSe ha producido el error " << exception.what() << "\n\n";
        }
        std::cout << ") en base " << BS << " = (";
        try{
          D.write(std::cout);
        }catch(NumberException& exception) {
          std::cout << "\nSe ha producido el error " << exception.what() << "\n\n";
        }
        std::cout << ") en base " << BS << "\n";
      }catch(NumberException& exception) {
        std::cout << "\nSe ha producido el error " << exception.what() << "\n\n";
      }
      std::cout << "Procedemos a realizar la multiplicacion de los dos numeros codificados\n";
      try{
        Number<NU * NU, BS> F = A * B;
        std::cout << "El numero (";
        try {
          A.write(std::cout);
        }catch(NumberException& exception) {
          std::cout << "\nSe ha producido el error " << exception.what() << "\n\n";
        }
        std::cout << ") en base " << BS << " * (";
        try {
          B.write(std::cout);
        }catch(NumberException& exception) {
          std::cout << "\nSe ha producido el error " << exception.what() << "\n\n";
        }
        std::cout << ") en base " << BS << " = (";
        try {
          F.write(std::cout);
        }catch(NumberException& exception) {
          std::cout << "\nSe ha producido el error " << exception.what() << "\n\n";
        }
        std::cout << ") en base " << BS << "\n";
      }catch(NumberException& exception) {
        std::cout << "\nSe ha producido el error " << exception.what() << "\n\n";
      }

      std::cout<<"Gracias por hacer uso de la calculadora PR2\n";
    }catch (NumberException & exception) {
      std::cout << "Se ha producido el error " << exception.what() << "\n\nPorfavor reinicie la aplicacion\n";
    }
  }catch (NumberException & exception){
    std::cout<<"Se ha producido el error " <<exception.what()<<"\n\nPorfavor reinicie la aplicacion\n";
  }




}