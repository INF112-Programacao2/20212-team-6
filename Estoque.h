#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <vector>

#include "produto.h"

class Estoque {
    public: 
        std::vector<Produto> Estoque;          // foi usado o tipo std::vector por conta de sua alocação dinâmica automática
        static int indiceDoEstoque;            // controla o indice do estoque para quando novos produtos forem adicionados
        void adicionar_produto();
        void Relatorio();
};

#endif

// falta o valor total do estoque em reais, os diferentes tipos de produtos, quanto tem em reais de cada produto, quantos produtos saíram com as vendas,
// quantos produtos entraram com a compra de novos produtos;
// ideia: dar ao administrador várias opcoes de informações que ele pode visualizar 