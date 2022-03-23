#include <iostream>
#include <string>

#include "produto.h"

Produto::Produto() {}

Produto::Produto(int id, double preco, int quantidade)
{
    _id = id;
    _preco = preco;
    _quantidade = quantidade;
}

Produto::Produto(int id, double preco, int quantidade, std::string marca, std::string descricao)
{
    _id = id;
    _preco = preco;
    _quantidade = quantidade;
    _marca = marca;
    _descricao = descricao;
}

int Produto::getID()
{
    return _id;
}

double Produto::getPreco()
{
    return _preco;
}

int Produto::getQuantidade()
{
    return _quantidade;
}

bool Produto::getEmEstoque()
{
    return _emEstoque;
}

std::string Produto::getMarca()
{
    return _marca;
}

std::string Produto::getDescricao()
{
    return _descricao;
}

void Produto::setEmEstoque()
{
    if (_quantidade != 0)
        _emEstoque = true;
    else
        _emEstoque = false;
}

void Produto::setMarca(std::string marca)
{
    _marca = marca;
}

void Produto::setDescricao(std::string descricao)
{
    _descricao = descricao;
}

void Produto::setQuantidade(int qtde) {
    _quantidade = qtde;
}

void Produto::imprimirProduto()
{
    std::cout << "CODIGO: " << getID() << std::endl;
    std::cout << "DESCRIÇÃO DO PRODUTO: " << getDescricao() << std::endl;
    std::cout << "PRECO: " << getPreco() << std::endl;
    std::cout << "QUANTIDADE: " << getQuantidade() << std::endl;
    std::cout << "MARCA: " << getMarca() << std::endl;
}
