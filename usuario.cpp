#include "usuario.h"

Usuario::Usuario(std::string nome, unsigned long long int cpf, int id_usuario)
{
    _nome = nome;
    _cpf = cpf;
    _id_usuario = id_usuario;
}

std::string Usuario::get_nome()
{
    return _nome;
}
