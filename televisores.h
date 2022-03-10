#include "produto.h"

class Televisores : public Produto {
private:
    int _tela;
    int _resolucao;
public:
    //Construtor
    Televisores(int id, double preco, int quantidade, std::string marca, int tela, int resolucao);
    //Gets
    int getTela();
    int getResolucao();
    //Sets
    void setTela(int tela);
    void setResolucao(int resolucao);
};