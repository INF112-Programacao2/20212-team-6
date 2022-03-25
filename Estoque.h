#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <vector>

#include "produto.h"

// os atributos foram declarados como static para garantir que haverá somente uma cópia destes durante todo o programa
// a maioria dos métodos foram declarados como static para que possam ser usados em qualquer lugar independente de existir ou não um objeto da classe
// os códigos estabelecidos para os produtos se baseam em um intervalo:
// 10000 - 19999: celulares
// 20000 - 29999: notebooks
// 30000 - 39999: fones de ouvidos
// 40000 - 49999: televisores
// alguns métodos terão suas operações baseadas nesses intervalos

class Estoque {
    protected:
        static double valorTotalDoEstoque;
        static int qtdDeProdutos;
    public:
        Estoque();
        static std::vector<Produto*> Estoque1;          // foi usado o tipo vector por conta de sua alocação dinâmica automática
        void adicionar_produto();
        // static void excluir_produto();
        static void excluir_produto(int codigo, int qdte);      // sobrecarga de método para diferentes ocasiões de exclusão
        static void excluir_produto(int codigo);
        static void imprimeEstoque();
        static void imprimeProdutoEmEstoque(int a, int b);
        static void Relatorio();                        // dá algumas opcoes ao usuario e gera relatório contendo informações do estoque a partir delas
        static void setValorTotalDoEstoque(int qtde, double preco, int operacao);
        static void setQtdDeProdutos(int qtde, int operacao);
        static double getValorTotalDoEstoque();
        static int getQtdDeProdutos();
        static bool identificaProduto(int codigo);
        static std::string identificaDescricaoProduto(int codigo);
        static int geradorID(int x, int y);                         // gera automaticamente um ID para o produto no momento do seu cadastro
        ~Estoque();
};

#endif