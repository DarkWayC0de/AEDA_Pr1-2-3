//
// Created by darkwaycode on 6/03/19.
//

#include "../include/NumberException.h"

const  char* base_grande_exception::what() const noexcept {
  return "La base que se a solicitado mostra no es representable";
}

const char* fuera_rango_exception::what() const noexcept{
  return "El numero no puede ser representado eneste numero de caracteres";
}

const char* base_negativa::what() const noexcept{
  return "Se ha indicado una base que no es apta para hacer una representacion numerica";
}
const char* divzero::what() const noexcept{
  return "Se a intentado hacer una divicion con un 0";
}
