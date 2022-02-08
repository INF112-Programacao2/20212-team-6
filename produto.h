class Produto {
    private:
    int _id;
    double _preco;
    int _quantidade;
    bool _emEstoque;

    public:
    Produto(int id, double preco, int quantidade);

    int getID();
    double getPreco();
    int getQuantidade();
    bool getEmEstoque();

    void setEmEstoque();

};