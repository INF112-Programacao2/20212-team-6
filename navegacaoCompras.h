#ifndef NAVEGACAOCOMPRAS_H
#define NAVEGACAOCOMPRAS_H
#include<iostream>
#include"Estoque.h"
#include"produto.h"
#include"Pedido.h"

class NavegacaoCompras : public Estoque
{
    private:
        Estoque listar;
        int opc;
        int codigo;

    public:
        NavegacaoCompras();
        void imprimirProdutosDisponiveis();
        Produto selecaoDeCompra();
        Produto RetornaProdutoBuscado(int codigo);
};

#endif