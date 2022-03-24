#include<iostream>
#include"Estoque.h"

class NavegacaoCompras{
    private:
        Estoque listar;
        int opc;

    public:
        NavegacaoCompras();
        void imprimirProdutosDisponiveis();
};