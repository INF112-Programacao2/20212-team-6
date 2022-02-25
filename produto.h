#include <iostream>

class Produto {
private:
    int _id;
    double _preco;
    int _quantidade;
    bool _emEstoque;

    std::string _marca;

public:
    //Construtor
    Produto();
    Produto(int id, double preco, int quantidade);

    //Gets
    int getID();
    double getPreco();
    int getQuantidade();
    bool getEmEstoque();

    std::string getMarca();

    //Sets
    void setEmEstoque();

    void setMarca(std::string marca);

};
