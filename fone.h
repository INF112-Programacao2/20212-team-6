#include "produto.h"

class FoneDeOuvido : public Produto {
private:
    bool _bt;
    std::string _tipo;
public:
    //Construtor
    FoneDeOuvido(int id, double preco, int quantidade, std::string marca, bool bt, std::string tipo);
    //Gets
    bool getBt();
    std::string getTipo();
    //Sets
    void setBt(bool bt);
    void setTipo(std::string tipo);
};