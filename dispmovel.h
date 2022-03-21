#ifndef DISPMOVEL_H
#define DISPMOVEL_H

#include "produto.h"

class DispMovel : public Produto {
private:
    int _tela;
    int _ram;
    int _armazenamento;
public:
    //Construtor
    DispMovel(int id, double preco, int quantidade, std::string marca, int tela, int ram, int armazenamento);
    //Gets
    int getTela();
    int getRam();
    int getArmazenamento();
    //Sets
    void setTela(int tela);
    void setRam(int ram);
    void setArmazenamento(int armazenamento);
    //função para visualizar dados do produto derivada da classe base
    void imprimirProduto() override;
};

#endif
