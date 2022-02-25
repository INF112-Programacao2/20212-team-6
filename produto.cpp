#include "produto.h"

Produto::Produto()
{

}

Produto::Produto(int id, double preco, int quantidade) {
    _id = id;
    _preco = preco;
    _quantidade = quantidade;
}

int Produto::getID() {
    return _id;
}

double Produto::getPreco() {
    return _preco;
}

int Produto::getQuantidade() {
    return _quantidade;
}

bool Produto::getEmEstoque() {
    return _emEstoque;
}

std::string Produto::getMarca() {
    return _marca;
}

void Produto::setEmEstoque() {
    if (_quantidade != 0)
        _emEstoque = true;
    else
        _emEstoque = false;
}

void Produto::setMarca(std::string marca) {
    _marca = marca;
}
