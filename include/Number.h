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
    size_t get_N(){
        return N;
    }
    size_t get_B(){
        return B;
    }
    int dec()const {
        int resultado= 0;
        for (int i = this->number_.size()-1;i >= 0  ; --i) {
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
        }
    }
    void div_Base(int a, T simbolos[]){
        if(a<B){
            number_.push_back(simbolos[a]);
        }else{
            number_.push_back(simbolos[a%B]);
            div_Base(a/B,simbolos);

        }
    }
    void rellenar_vector_de_datos(T simbolos[])const{
        if(std::is_same<T,char>::value != 0) {
            int car = 0;
            for (int i = 0; i < B; ++i) {
                if (i > 9) {
                    simbolos[i] = 'A' + car++;
                } else {
                    simbolos[i] = '0' + i;
                }

            }
        } else{
            if(std::is_same<T,int>::value != 0){
                for (int i = 0; i < B; ++i) {
                    simbolos[i]=i;
                }
            }
        }
    }
};
template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
Number<L + 1, P, Y> operator+( const Number<L, P, Y> &op1,const  Number<U, V, R> &op2) {
    Number<L+1,P,Y> aux(op1.dec()+op2.dec());
    return aux;
}

template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
Number<L+1, P, Y> operator-(const Number<L, P, Y> &op1, const Number<U, V, R>& op2){
    Number<L+1,P,Y> aux(op1.dec()-op2.dec());
    return aux;
}
template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
Number<L*U,P,Y>operator*(const Number<L,P,Y>& op1, const Number<U,V,R>& op2){
    Number<L*U,P,Y> aux(op1.dec()*op2.dec());
    return aux;
}
template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
Number<L*U,P,Y> operator/(const Number<L,P,Y>& op1, const Number<U,V,R>& op2){
    Number<L*U,P,Y> aux(op1.dec()/op2.dec());
    return aux;
}
template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
Number<L*U,P,Y> operator%(const Number<L,P,Y>& op1, const Number<U,V,R>& op2){
    Number<L*U,P,Y> aux(op1.dec()%op2.dec());
    return aux;
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
/*
Number operator++(const Number& op1, const Number& op2)const{
    int tamano=0,base=0,numero=0;
    Number<tamano,base> aux(numero);
    return aux;
}
Number operator--(const Number& op1, const Number& op2)const{
    int tamano=0,base=0,numero=0;
    Number<tamano,base> aux(numero);
    return aux;
}
*/

#endif //PR1_NUMBER_Hi


