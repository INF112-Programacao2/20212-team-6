#include "produto.h"

class Televisores : public Produto {
private:
    int _tela;
    int _resolucao;
public:
    //Gets
    int getTela();
    int getResolucao();
};