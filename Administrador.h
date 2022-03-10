#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <string>

#include "usuario.h"
#include "Produto.h"
#include "Estoque.h"

class Administrador : public Usuario {
    protected:
        Estoque EstoqueDaLoja;       // estoque
    public:
        Admin(std::string nome, int cpf);
        void menuAdm();
        void adicionarProduto();
        void excluirProduto();                 // será implementada quando houver o estoque real
        void relatorioDeVendas();
        void relatorioDeEstoque();
};

#endif
