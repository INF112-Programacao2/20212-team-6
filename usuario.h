#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>

class Usuario
{
    protected:
        std::string _nome;
        unsigned long long int _cpf;
        int _id_usuario;
    public:
        Usuario(std::string nome, unsigned long long int cpf, int id_usuario);
        std::string get_nome();
};

#endif