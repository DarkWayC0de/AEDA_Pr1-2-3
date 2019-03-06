//
// Created by darkwaycode on 12/02/19.
//

#ifndef PR1_NUMBER_H
#define PR1_NUMBER_H

#include <vector>
#include <cmath>

template <size_t N, size_t B, class T = char>
class Number{
private:
    std::vector<T> number_;

public:

    explicit Number(int valor=0){
            if (valor >= 0) {
                to_base(valor);
            } else {
                std::cout << "No se pueden representar numeros negativos, acabas de intentar representar " << valor
                          << " en base " << B << " con " << N << " digitos\n";
                throw std::system_error(errno, std::system_category(), "no se pudo crear el Number ");
            }
    }
    ~Number() = default;

    std::ostream& write(std::ostream &os)const{
        for (auto i = static_cast<int>(N - 1); i >= 0; i--) {
            if(i<number_.size()){
                os << number_.at(i);
            }else{
                os << 0;
            }
        }
    }
  std::ostream& write_mof(std::ostream &os, int a){
    std::vector<T> number2_;
    T simbolos[a];
    rellenar_vector_de_datos(simbolos,a);
    div_Base(this->dec(),simbolos, number2_,a);
    if (number2_.size()>N){
      std::cout<<"El numero "<<a<<" no puede ser representado en "<<N<<" caracteres de la base "<<B<<" \n";
      number2_.clear();
      throw std::system_error(errno, std::system_category(), "no se pudo crear el Number");
    }
    for (auto i = static_cast<int>(N - 1); i >= 0; i--) {
      if(i<number2_.size()){
        os << number2_.at(i);
      }else{
        os << 0;
      }
    }
  }

    size_t get_N(){
        return N;
    }
    size_t get_B(){
        return B;
    }
    int dec()const {
        int resultado= 0;
        for (auto i = static_cast<int>(this->number_.size() - 1); i >= 0  ; --i) {
            resultado+=(numero_real(number_[i])*pow(B,i));
        }
        return resultado;
    }
    template<size_t U, size_t V,class R, size_t L,size_t P, class Y>
    friend Number<L+1,P,Y> operator+(const Number<L,P,Y>& op1,const  Number<U,V,R>& op2);
    template<size_t U, size_t V,class R, size_t L,size_t P, class Y>
    friend Number<L+1,P,Y> operator-(const Number<L,P,Y>& op1,const  Number<U,V,R>& op2);
    template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
    friend Number<L*U,P,Y> operator*(const Number<L,P,Y>& op1, const Number<U,V,R>& op2);
    template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
    friend Number<L*U,P,Y> operator/(const Number<L,P,Y>& op1, const Number<U,V,R>& op2);
    template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
    friend Number<L*U,P,Y> operator%(const Number<L,P,Y>& op1, const Number<U,V,R>& op2);
    template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
    friend bool operator!=(const Number<L,P,Y>& op1, const Number<U,V,R>& op2);
    template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
    friend bool operator==(const Number<L,P,Y>& op1, const Number<U,V,R>& op2);
    template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
    friend bool operator<=(const Number<L,P,Y>& op1, const Number<U,V,R>& op2);
    template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
    friend bool operator>=(const Number<L,P,Y>& op1, const Number<U,V,R>& op2);
    template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
    friend bool operator<(const Number<L,P,Y>& op1, const Number<U,V,R>& op2);
    template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
    friend bool operator>(const Number<L,P,Y>& op1, const Number<U,V,R>& op2);
private:
    int numero_real(char a)const{
        int resl= 0;
        T simbolos[B];
        rellenar_vector_de_datos(simbolos);
        for (int i = 0; i <B ; ++i) {
            if(simbolos[i]==a){
                resl=i;
                break;
            }
        }
        return  resl;
    }

    void to_base(int a){
      //Creamos un vector con los datos que representaran nuestros numeros
      T simbolos[B];
      rellenar_vector_de_datos(simbolos);
      div_Base(a,simbolos);
      if (number_.size()>N){
        std::cout<<"El numero "<<a<<" no puede ser representado en "<<N<<" caracteres de la base "<<B<<" \n";
        number_.clear();
        throw std::system_error(errno, std::system_category(), "no se pudo crear el Number");
      }
    }
    void div_Base(int a, T simbolos[]){
        if(a<B){
            number_.push_back(simbolos[a]);
        }else{
            number_.push_back(simbolos[a%B]);
            div_Base(static_cast<int>(a / B), simbolos);

        }
    }
  void div_Base(int a, T simbolos[],std::vector<T> &number_2, int b){
    if(a<b){
      number_2.push_back(simbolos[a]);
    }else{
      number_2.push_back(simbolos[a%b]);
      div_Base(static_cast<int>(a / b), simbolos);

    }
  }
    void rellenar_vector_de_datos(T simbolos[], int a=B)const{
        if(std::is_same<T,char>::value != 0) {
            int car = 0;
            for (int i = 0; i < a; ++i) {
                if (i > 9) {
                    simbolos[i] = 'A' + car++;
                } else {
                    simbolos[i] = '0' + i;
                }

            }
        } else{
            if(std::is_same<T,int>::value != 0){
                for (int i = 0; i < a; ++i) {
                    simbolos[i]=i;
                }
            }
        }
    }
};
template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
Number<L + 1, P, Y> operator+( const Number<L, P, Y> &op1,const  Number<U, V, R> &op2) {
    try {
        int a = op1.dec() + op2.dec();
        if (a >= 0) {
            Number<L + 1, P, Y> aux(a);
            return aux;
        } else {
            std::cout<<"El resultado de la operacion + es superior a la capacidad de int\n";
            throw std::system_error(errno, std::system_category(), "no se pudo representar el numero");
        }
    }catch (std::system_error& e) {
        throw e;
    }
    
}

template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
Number<L+1, P, Y> operator-(const Number<L, P, Y> &op1, const Number<U, V, R>& op2){
    try {
        int a = op1.dec() - op2.dec();
        if (a >= 0) {
            Number<L + 1, P, Y> aux(a);
            return aux;
        } else {
            std::cout<<"El resultado de la operacion - es superior a la capacidad de int\n";
            throw std::system_error(errno, std::system_category(), "no se pudo representar el numero");
        }
    }catch (std::system_error& e) {
        throw e;
    }
}
template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
Number<L*U,P,Y>operator*(const Number<L,P,Y>& op1, const Number<U,V,R>& op2){
    try {
        int a = op1.dec()*op2.dec();
        if (a >=0) {
            Number<L*U,P,Y> aux(a);
            return aux;
        } else {
            std::cout<<"El resultado de la operacion * es superior a la capacidad de int\n";
            throw std::system_error(errno, std::system_category(), "no se pudo representar el numero");
        }
    }catch (std::system_error& e) {
        throw e;
    }
}
template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
Number<L*U,P,Y> operator/(const Number<L,P,Y>& op1, const Number<U,V,R>& op2){
    try {
        int a = op1.dec()/op2.dec();
        if (a >= 0) {
            Number<L*U,P,Y> aux(a);
            return aux;
        } else {
            std::cout<<"El resultado de la operacion / es superior a la capacidad de int\n";
            throw std::system_error(errno, std::system_category(), "no se pudo representar el numero");
        }
    }catch (std::system_error& e) {
        throw e;
    }
}
template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
Number<L*U,P,Y> operator%(const Number<L,P,Y>& op1, const Number<U,V,R>& op2){
    try {
            int a = op1.dec()%op2.dec();
            if (a >=0) {
                Number<L*U,P,Y> aux(a);
                return aux;
            } else {
                std::cout<<"El resultado de la operacion % es superior a la capacidad de int\n";
                throw std::system_error(errno, std::system_category(), "no se pudo representar el numero");
            }
    }catch (std::system_error& e) {
        throw e;
    }
}

template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
bool operator==(const Number<L,P,Y>& op1, const Number<U,V,R>& op2){
    return (op1.dec()==op2.dec());
}
template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
bool operator!=(const Number<L,P,Y>& op1, const Number<U,V,R>& op2){
    return (op1.dec()!=op2.dec());
}
template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
bool operator<(const Number<L,P,Y>& op1, const Number<U,V,R>& op2){
    return (op1.dec()<op2.dec());
}
template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
bool operator>(const Number<L,P,Y>& op1, const Number<U,V,R>& op2){
    return (op1.dec()>op2.dec());
}
template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
bool operator<=(const Number<L,P,Y>& op1, const Number<U,V,R>& op2){
    return (op1.dec()<=op2.dec());
}
template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
bool operator>=(const Number<L,P,Y>& op1, const Number<U,V,R>& op2){
    return (op1.dec()>=op2.dec());
}


#endif //PR1_NUMBER_Hi


