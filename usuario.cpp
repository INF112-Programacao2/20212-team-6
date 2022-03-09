#include "usuario.h"
#include <iostream>

Usuario::Usuario(std::string nome, int cpf, int id_usuario)
{
    _nome = nome;
    _cpf = cpf;
    _id_usuario = id_usuario;
}

std::string Usuario::get_nome()
{
    return _nome;
}
