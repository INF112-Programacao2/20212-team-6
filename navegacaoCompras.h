#include<iostream>
#include"Estoque.h"
#include"produto.h"

class NavegacaoCompras{
    private:
        Estoque listar;
        int opc;
        int codigo;
        //Produto compra;

    public:
        NavegacaoCompras();
        void imprimirProdutosDisponiveis();
        void selecaoDeCompra();
};