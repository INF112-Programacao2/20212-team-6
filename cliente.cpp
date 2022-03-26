#include <iostream> 
#include <string>
#include "cliente.h"
#include "Pedido.h"
#include "produto.h"

Cliente::Cliente(std::string nome, unsigned long long int cpf, int id_usuario, std::string endereco, unsigned long long int telefone)
    : Usuario(nome, cpf, id_usuario) {
    this->endereco = endereco;
    this->telefone = telefone;
    this->saldoEmConta = 1000;
}

// MÉTODOS SET

void Cliente::setNome(std::string Nome) {
    this->_nome = Nome;
}

void Cliente::setCPF(unsigned long long int CPF) {
    this->_cpf = CPF;
}

void Cliente::setID(int id) {
    this->_id_usuario = id;
}

void Cliente::setEndereco(std::string Endereco) {
    this->endereco = Endereco;
}


void Cliente::setTelefone(unsigned long long int tel) {
    this->telefone = tel;
}

void Cliente::setSelecao(int opc) {
    this->selecao = opc;
}

void Cliente::setP(Produto* p) {
    this->p = p;
}

void Cliente::setRemove(std::string remove) {
    this->remove = remove;
}

void Cliente::setSaldo(double saldo){
    this->saldoEmConta=saldo-Carrinho.valor_total();
}

// MÉTODOS GET
std::string Cliente::getNome() {
    return _nome;
}

unsigned long long int Cliente::getCPF() {
    return _cpf;
}

int Cliente::getID() {
    return _id_usuario;
}

std::string Cliente::getEndereco() {
    return endereco;
}

unsigned long long int Cliente::getTelefone() {
    return telefone;
}

int Cliente::getSelecao() {
    return selecao;
}

Produto Cliente::getP() {
    return *p;
}

std::string Cliente::getRemove() {
    return remove;
}

double Cliente::getSaldo(){
    return saldoEmConta;
}
// MOSTRA DADOS DO CLIENTE NA TELA

void Cliente::exibirDados() {
    std::cout << "-------------------------------------------\n";
    std::cout << "DADOS DO CLIENTE\n";
    std::cout << "NOME: " << getNome() << std::endl;
    std::cout << "CPF: " << getCPF() << std::endl;
    std::cout << "ID de usuario: " << getID() << std::endl;
    std::cout << "ENDEREÇO: " << getEndereco() << std::endl;
    std::cout << "TELEFONE: " << getTelefone() << std::endl;
    std::cout << "-------------------------------------------\n";
}
//Aqui o cliente realiza uma nova compra
void Cliente::meuCarrinho() {

    do {

        std::cout << "____________MEU CARRINHO____________\n\n";
        std::cout << "Prossiga selecionando uma das seguintes opcoes:\n";
        std::cout << "1) Visualizar meu carrinho\n";
        std::cout << "2) Adicionar itens\n";
        std::cout << "3) Remover itens\n";
        std::cout << "4) Limpar carrinho\n";
        std::cout << "5) Concluir compra\n";
        std::cout << "_____________________________________\n";
        std::cout << "Se deseja sair, digite 6\n";
        std::cin >> selecao;

        switch (selecao)
        {
        case 1:
        {
            Carrinho.listar_produtos();
            std::cout << "\n Valor total: " << Carrinho.valor_total() << std::endl;
            break;
        }
        case 2:
        {
            Compras.imprimirProdutosDisponiveis();
            Produto p = Compras.selecaoDeCompra();
            Carrinho.add_produto(p);
            break;
        }
        case 3:
        {
            std::cout << "Digite a posicao do item que deseja remover:\n";
            std::cin >> remove;
            Carrinho.remover_item(remove);
            break;
        }
        case 4:
        {
            Carrinho.limpar_carrinho();
            break;
        }
        case 5:
        {
            std::cout <<"\n Valor total: " << Carrinho.valor_total();
            std::cout << "Valor total em conta é R$ " << getSaldo()<< std::endl;
            if(getSaldo()<Carrinho.valor_total())
            {
                std::cout <<"Infelizmente você nao tem saldo suficiente para realizar essa compra.\n";
                std::cout <<"Se acredita que isso esteja errado, favor entrar em contato com um administrador (31 9999-9999).\n";
                break;
            }
            else
            {
                setSaldo(saldoEmConta);
                std::cout << "O valor restante em conta é R$ " << getSaldo() << std::endl;
            }
        }   
        default:
            break;
        }
    } while (selecao < 7);




}
