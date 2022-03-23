#include "notebook.h"

Notebook::Notebook(int id, double preco, int quantidade, std::string marca, std::string descricao, int tela, int ram, int armazenamento):
    Produto(id, preco, quantidade, marca, descricao), _tela(tela), _ram(ram), _armazenamento(armazenamento) {}

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

void Notebook::imprimirProduto() {
    std::cout << "______________________________________________________________________\n";
    if (!getEmEstoque())
        std::cout << "\tATENÇÃO: PRODUTO FORA DE ESTOQUE!\n";
    std::cout << std::endl;
    std::cout << "\tCODIGO: " << getID() << std::endl;
    std::cout << "\tDESCRIÇÃO DO PRODUTO: " << getDescricao() << std::endl;
    std::cout << "\tPRECO: R$" << getPreco() << std::endl;
    std::cout << "\tQUANTIDADE: " << getQuantidade() << std::endl;
    std::cout << "\tMARCA: " << getMarca() << std::endl;
    std::cout << "\tTAMANHO DA TELA: " << getTela() << " POLEGADAS"<< std::endl;
    std::cout << "\tMEMORIA RAM: " << getRam() << " GIGABYTES"<< std::endl;
    std::cout << std::endl;    
    std::cout << "______________________________________________________________________\n";
}
