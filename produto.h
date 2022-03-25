#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>

class Produto {
private:
    int _id;
    double _preco;
    int _quantidade;
    bool _emEstoque;
    std::string _descricao;
    std::string _marca;

public:
    //Construtor
    Produto();
    Produto(int id, double preco, int quantidade);
    Produto(int id, double preco, int quantidade, std::string marca, std::string descricao);
    virtual void imprimirProduto();     // exibe informações do produto, será sobrescrita nas subclasses

    //Gets
    int getID();
    double getPreco();
    int getQuantidade();
    bool getEmEstoque();
    std::string getMarca();
    std::string getDescricao();

    //Sets
    void setEmEstoque();
    void setQuantidade(int qtde);
    void setMarca(std::string marca);
    void setDescricao(std::string descricao);

};

#endif
