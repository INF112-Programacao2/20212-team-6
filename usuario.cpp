#include "usuario.h"
#include <iostream>

Usuario::Usuario(std::string nome, int cpf)
{
    _nome = nome;
    _cpf = cpf;
}

std::string Usuario::get_nome()
{
    return _nome;
}
