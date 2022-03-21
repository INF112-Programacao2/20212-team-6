#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <vector>

#include "produto.h"

class Estoque {
    protected:
        static double valorTotalDoEstoque;
        static int qtdDeProdutos;
    public: 
        Estoque();
        static std::vector<Produto*> Estoque1;   // foi usado o tipo std::vector por conta de sua alocação dinâmica automática
        void adicionar_produto();
        void excluir_produto();
        static void imprimeProdutoEmEstoque(int a, int b);
        static void Relatorio();   // dá algumas opcoes ao usuario e exibe informações do estoque a partir delas
        static void setValorTotalDoEstoque(int qtde, double preco);
        static void setQtdDeProdutos(int qtde);
        static double getValorTotalDoEstoque();
        static int getQtdDeProdutos();
        static int geradorID(int x, int y); // gera automaticamente um ID para o produto no momento do seu cadastro
        ~Estoque();
};

#endif
