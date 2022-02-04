#include "produto.h"

Produto::Produto(int id, double preco){
    _id = id;
    _preco = preco;
}

int Produto::getID(){
    return _id;
}

double Produto::getPreco(){
    return _preco;
}