#ifndef CLIENTE_H
#define CLIENTE_H

#include "usuario.h"
#include "Pedido.h"
#include "produto.h"
#include "navegacaoCompras.h"

class Cliente : public Usuario {
    private: 
        std::string endereco;
        unsigned long long int telefone;
        Pedido Carrinho;
        int selecao;
        Produto *p;
        std::string remove;
        NavegacaoCompras Compras;
    public: 
        Cliente(std::string nome,  unsigned long long int cpf, int id_usuario, std::string endereco,  unsigned long long int telefone);

    //metodos set
    void setNome(std::string Nome);
    void setCPF( unsigned long long int CPF);
    void setID(int id);
    void setEndereco(std::string Endereco);
    void setTelefone( unsigned long long int tel);
    void setSelecao(int opc);
    void setP(Produto *p);
    void setRemove(std::string remove);

    //metodos get
    std::string getNome();
    unsigned long long int getCPF();
    int getID();
    std::string getEndereco();
    unsigned long long int getTelefone();
    int getSelecao();
    Produto getP();
    std::string getRemove();

    void exibirDados();
    void meuCarrinho();
    void menuDoCliente();
};

#endif