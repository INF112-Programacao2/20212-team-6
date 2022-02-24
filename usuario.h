#include <iostream>

class Usuario
{
    protected:
        std::string _nome;
        long int _cpf;
    public:
        Usuario(std::string nome, int cpf);
        std::string get_nome();


};
