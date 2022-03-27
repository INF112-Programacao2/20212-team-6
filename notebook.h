#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include "produto.h"

class Notebook : public Produto 
{
private:
    int _tela;
    int _ram;
    int _armazenamento;
public:
    //Construtor
    Notebook(int id, double preco, int quantidade, std::string marca, std::string descricao, int tela, int ram, int armazenamento);
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
