#include "fone.h"

FoneDeOuvido::FoneDeOuvido(int id, double preco, int quantidade, std::string marca, bool bt, std::string tipo):
    Produto(id, preco, quantidade, marca), _bt(bt), _tipo(tipo) {}

bool FoneDeOuvido::getBt(){
    return _bt;
}

std::string FoneDeOuvido::getTipo(){
    return _tipo;
}