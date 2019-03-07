//
// Created by darkwaycode on 12/02/19.
//

#ifndef PR1_NUMBER_H
#define PR1_NUMBER_H

#include <cmath>
#include "NumberException.h"

template <size_t N, size_t B, class T = char>
class Number{
private:
    T* number_;
    int index_;
    bool neg_;
public:

    explicit Number(int valor=0):index_(0),neg_(false){
      if(B<=0){
        throw  base_negativa();
      }else {
        number_ = new T[N];
        if (valor >= 0) {
          to_base(valor);
        } else {
          neg_ = true;
          to_base(-valor);
        }
      }
    }
    Number(const Number &obj) {
      number_= new T[N];
      for (auto i = 0; i <N ; ++i) {
        *(number_+i)= *(obj.number_+i);
      }
      index_ = obj.index_;
      neg_=obj.neg_;
    }
    ~Number(){
      delete[] number_;
      number_=NULL;
      index_=0;
      neg_=false;
    }

    std::ostream& write(std::ostream &os)const{
      if(B <=16) {
        if (neg_) {
          os << "-";
        }
        for (auto i = static_cast<int>(N - 1); i >= 0; i--) {
          if (i <= index_) {
            os << number_[i];
          } else {
            os << 0;
          }
        }
      }else{
        throw base_grande_exception();
      }
    }

  std::ostream& write_mof(std::ostream &os, int a){
      if(a <=16) {
        T *number2_ = new T[N];
        int index2_ = 0;
        bool neg2_(false);
        T simbolos[a];
        rellenar_vector_de_datos(simbolos, a);
        int b(this->dec());
        if (b < 0) {
          b = -b;
          neg2_ = true;
        }
        div_Base(b, simbolos, number2_, a, index2_);
        if (neg2_) {
          os << "-";
        }
        for (auto i = static_cast<int>(N - 1); i >= 0; i--) {
          if (i <= index2_) {
            os << number2_[i];
          } else {
            os << 0;
          }
        }
      } else{
        throw base_grande_exception();
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
      for (auto i = static_cast<int>(this->index_); i >= 0  ; --i) {
        resultado+=(numero_real(number_[i])*pow(B,i));
      }
      return (neg_ )? -resultado : resultado;
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
    template <size_t  L, size_t P, class Y>
    Number& operator=(const Number<L,P,Y> obj){
      number_= new T[N];
      for (auto i = 0; i <N ; ++i) {
        *(number_+i)= *(obj.number_+i);
      }
      index_ = obj.index_;
      neg_ = obj.neg_;
    }
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
    }
    void div_Base(int a, T simbolos[],int pos=0){
      if(pos>N-1){
        throw fuera_rango_exception();
      }else {
        if (a < B) {
          number_[pos] = simbolos[a];
          index_ = pos;
        } else {
          number_[pos] = simbolos[a % B];
          div_Base(static_cast<int>(a / B), simbolos, ++pos);

        }
      }
    }
  void div_Base(int a, T simbolos[],T* &number_2, int b, int &index2_, int pos=0){
    if(pos>N){
      std::cout<<"El numero "<<a<<" no puede ser representado en "<<N<<" caracteres de la base "<<B<<" \n";
      throw std::system_error(errno, std::system_category(), "no se pudo crear el Number");
    }else {
      if (a < b) {
        number_2[pos] = simbolos[a];
        index2_=pos;
      } else {
        number_2[pos] = simbolos[a % b];
        div_Base(static_cast<int>(a / b),simbolos,number_2, b,index2_,++pos);

      }
    }
  }
    void rellenar_vector_de_datos(T simbolos[], int a=static_cast<int>(B))const{
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
        int a = op1.dec() + op2.dec();
        Number<L + 1, P, Y> aux(a);
        return aux;
}

template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
Number<L+1, P, Y> operator-(const Number<L, P, Y> &op1, const Number<U, V, R>& op2){
  int a = op1.dec() - op2.dec();
  Number<L + 1, P, Y> aux(a);
  return aux;
}
template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
Number<L*U,P,Y>operator*(const Number<L,P,Y>& op1, const Number<U,V,R>& op2){
  int a = op1.dec()*op2.dec();
  Number<L*U,P,Y> aux(a);
  return aux;
}
template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
Number<L*U,P,Y> operator/(const Number<L,P,Y>& op1, const Number<U,V,R>& op2){
  int a = op1.dec()/op2.dec();
  Number<L*U,P,Y> aux(a);
  return aux;
}
template<size_t U, size_t V, class R, size_t L, size_t P, class Y>
Number<L*U,P,Y> operator%(const Number<L,P,Y>& op1, const Number<U,V,R>& op2){
  int a = op1.dec()%op2.dec();
  Number<L*U,P,Y> aux(a);
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




#endif //PR1_NUMBER_Hi


