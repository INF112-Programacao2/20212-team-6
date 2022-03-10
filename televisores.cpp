#include "televisores.h"

Televisores::Televisores(int id, double preco, int quantidade, std::string marca, int tela, int resolucao):
    Produto(id, preco, quantidade, marca), _tela(tela), _resolucao(resolucao) {}

int Televisores::getTela(){
    return _tela;
}

int Televisores::getResolucao(){
    return _resolucao;
}

void Televisores::setTela(int tela){
    _tela = tela;
}

void Televisores::setResolucao(int resolucao){
    _resolucao = resolucao;
}