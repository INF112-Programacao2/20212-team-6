#include "produto.h"

class DispMovel : public Produto {
private:
    int _tela;
    int _ram;
    int _armazenamento;
public:
    //Gets
    int getTela();
    int getRam();
    int getArmazenamento();
    //Sets
    void setTela();
    void setRam();
    void setArmazenamento();
};