#ifndef NAVEGACAO_H
#define NAVEGACAO_H

#include<iostream>
#include"Estoque.h"
#include"produto.h"

class NavegacaoCompras : public Estoque{
    private:
        Estoque listar;
        int opc;
        int codigo;
        //Produto compra;

    public:
        NavegacaoCompras();
        void imprimirProdutosDisponiveis();
        Produto selecaoDeCompra();
        Produto RetornaProdutoBuscado(int codigo);
};

#endif