#include <iostream>

class Usuario
{
    protected:
        std::string _nome;
        long int _cpf;
        int _id_usuario;
    public:
        Usuario(std::string nome, int cpf, int id_usuario);
        std::string get_nome();


};
