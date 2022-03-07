#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <string>

#include "usuario.h"
#include "Produto.h"

const int tamanho = 20;         // usada no tamanho do estoque;

class Admin : public Usuario {
    protected:
        Produto Estoque[tamanho];       // estoque de teste
    public:
        Admin(std::string nome, int cpf);
        static int indiceDoEstoque;            // controla o indice do estoque para quando novos produtos forem adicionados
        void menuAdm();
        void adicionarProduto();
        void excluirProduto();                 // será implementada quando houver o estoque real
        void relatorioDeVendas();
        void relatorioDeEstoque();
};

#endif