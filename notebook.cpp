#include "notebook.h"

Notebook::Notebook(int id, double preco, int quantidade, std::string marca, int tela, int ram, int armazenamento):
    Produto(id, preco, quantidade, marca), _tela(tela), _ram(ram), _armazenamento(armazenamento) {}

int Notebook::getArmazenamento(){
    return _armazenamento;
}

int Notebook::getRam(){
    return _ram;
}

int Notebook::getTela(){
    return _tela;
}

void Notebook::setArmazenamento(int armazenamento){
    _armazenamento = armazenamento;
}

void Notebook::setRam(int ram){
    _ram = ram;
}

void Notebook::setTela(int tela){
    _tela = tela;
}