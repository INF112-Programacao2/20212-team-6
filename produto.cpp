#include "produto.h"

Produto::Produto(int id, double preco, int quantidade){
    _id = id;
    _preco = preco;
    _quantidade = quantidade;
}

int Produto::getID(){
    return _id;
}

double Produto::getPreco(){
    return _preco;
}

int Produto::getQuantidade(){
    return _quantidade;
}

bool Produto::getEmEstoque(){
    return _emEstoque;
}

void Produto::setEmEstoque(){
    if(_quantidade!=0)
        _emEstoque=true;
    else
        _emEstoque=false;
}
