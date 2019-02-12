//
// Created by darkwaycode on 12/02/19.
//

#ifndef PR1_NUMBER_H
#define PR1_NUMBER_H

#include <vector>

//
template <size_t N, size_t B, class T = char>
class Number{
private:
    std::vector<T> number_;

public:

    Number(int valor=0){
        to_base(valor);
    }

    std::ostream& write(std::ostream &os)const{
        for (int i = N-1; i>=0; i--) {
            if(i<number_.size()){
                os << number_.at(i);
            }else{
                os << 0;
            }
        }
    }

private:

    void to_base(int a){
        //Creamos un vector con los datos que representaran nuestros numeros
        T simbolos[B];
        rellenar_vector_de_datos(simbolos);
        div_Base(a,simbolos);
        if (number_.size()>N){
            std::cout<<"El numero "<<a<<" no puede ser representado  en "<<N<<" \n";
            number_.clear();
        }
    }
    void div_Base(int a, T simbolos[]){
        if(a<B){
            number_.push_back(simbolos[a]);
        }else{
            div_Base(a/B,simbolos);
            number_.push_back(simbolos[a%B]);
        }
    }
    void rellenar_vector_de_datos(T simbolos[]){
        int car= 0;
        for (int i = 0; i <B ; ++i) {
            if(i>9){
                simbolos[i]='A'+ car++;
            } else{
                simbolos[i]='0'+i;
            }
        }
    }
};

#endif //PR1_NUMBER_H
