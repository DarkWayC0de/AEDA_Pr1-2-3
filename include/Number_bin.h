//
// Created by darkwaycode on 4/03/19.
//

#ifndef PR1_NUM2ER_BIN_H
#define PR1_NUM2ER_BIN_H
#include "NumberBase.h"
#include <cmath>

template <size_t N, class T>
class Number<N,2,T> : public NumberBase{
private:
    T* number_;
    int index_;
public:

    explicit Number(int valor=0):index_(0),NumberBase(2, static_cast<int>(N)){
            number_=new T[N];
            if (valor >= 0) {
                to_base(valor);
            } else {
                to_base(-valor);
                cmpla2(number_,index_);
            }
    }
    Number(const Number &obj) {
      number_= new T[N];
      for (auto i = 0; i <N ; ++i) {
        *(number_+i)= *(obj.number_+i);
      }
      index_ = obj.index_;
      //neg_=obj.neg_;
    }
    ~Number() override {
          delete[] number_;
          number_=NULL;
          index_=0;
          //neg_=false;
    }

    std::ostream& write(std::ostream &os)const override {
      /*if(neg_){
        os<<"-";
      }*/
      for (auto i = static_cast<int>(N - 1); i >= 0; i--) {
        if(i <=index_){
          os << number_[i];
        }else{
          os << 0;
        }
      }
    }

    size_t get_N(){
        return N;
    }
    size_t get_2(){
        return 2;
    }
    int dec() const {
        int resultado= 0;
        bool neg (false);
        if(number_[N-1]=='1'){
          T* number2= new T[N];
          for (auto i = 0; i <N ; ++i) {
            *(number2+i)= *(this->number_+i);
          }
          int index = this->index_;
          cmpla2(number2,index);
          neg=true;
          for (auto i = static_cast<int>(index); i >= 0; --i) {
            resultado += (numero_real(number2[i]) * pow(2, i));
          }
        }else {
          for (auto i = static_cast<int>(this->index_); i >= 0; --i) {
            resultado += (numero_real(number_[i]) * pow(2, i));
          }
        }
      return (neg )? -resultado : resultado;
    }
    template<size_t U,class R, size_t L, class Y>
    friend Number<L+1,2,Y> operator+(const Number<L,2,Y>& op1,const  Number<U,2,R>& op2);
    template<size_t U, class R, size_t L, class Y>
    friend Number<L+1,2,Y> operator-(const Number<L,2,Y>& op1,const  Number<U,2,R>& op2);
    template< size_t L, class Y>
    Number& operator=(const Number<L,2,Y> obj){
      number_= new T[N];
      for (auto i = 0; i <N ; ++i) {
        *(number_+i)= *(obj.number_+i);
      }
      index_ = obj.index_;
    }
private:
    void cmpla2(T* number, int &index) const{
      bool fir1(false);
      for (auto i = 0; i <=index; ++i) {
        if(fir1){
          if(number[i]=='1'){
            number[i]='0';
          }else{
            number[i]='1';
          }
        }
        if(number[i]=='1'&&!fir1){
          fir1 =true;
        }
      }
      if(index<=N-1){
        for (int i = index+1; i <N ; ++i) {
          number[i]='1';
        }
        index= static_cast<int>(N-1);
      }else{
        throw fuera_rango_exception();
      }

    }
    int numero_real(char a)const{
        int resl= 0;
        T simbolos[2];
        rellenar_vector_de_datos(simbolos);
        for (int i = 0; i <2 ; ++i) {
            if(simbolos[i]==a){
                resl=i;
                break;
            }
        }
        return  resl;
    }

    void to_base(int a) override {
      //Creamos un vector con los datos que representaran nuestros numeros

      T simbolos[2];
      rellenar_vector_de_datos(simbolos);
      div_2ase(a,simbolos);
    }
    void div_2ase(int a, T simbolos[],int pos=0){
      if(pos>N-2){
        throw fuera_rango_exception();
      }else {
        if (a < 2) {
          number_[pos] = simbolos[a];
          index_ = pos;
        } else {
          number_[pos] = simbolos[a % 2];
          div_2ase(static_cast<int>(a / 2), simbolos, ++pos);

        }
      }
    }

    void rellenar_vector_de_datos(T simbolos[], int a=static_cast<int>(2))const{
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
template<size_t U, class R, size_t L, class Y>
Number<L + 1,2, Y> operator+( const Number<L,2, Y> &op1,const  Number<U,2,R> &op2) {
        int a = op1.dec() + op2.dec();
        Number<L + 1, 2,Y> aux(a);
        return aux;
}

template<size_t U,class R, size_t L,class Y>
Number<L+1,2, Y> operator-(const Number<L,2, Y> &op1, const Number<U,2, R>& op2){
  Number<U,2,R> op3;
  for (auto i = 0; i <U ; ++i) {
    *(op3.number_+i)= *(op2.number_+i);
  }
  op3.index_= op2.index_;
  op3.cmpla2(op3.number_,op3.index_);
  return op1+op3;
}





#endif //PR1_NUM2ER_BIN_Hi


