#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <string>

#include "usuario.h"
#include "Produto.h"
#include "Estoque.h"

class Administrador : public Usuario {
    public:
        static Estoque EstoqueDaLoja;       // estoque
        Administrador(std::string nome, int cpf, int id);
        void menuAdm();
        void adicionarProduto();
        void excluirProduto();                 
        void relatorioDeVendas();
        void relatorioDeEstoque();
};

#endif
