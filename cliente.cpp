#include <iostream> 
#include <string>
#include "cliente.h"

Cliente::Cliente(std::string nome,  unsigned long long int cpf, int id_usuario,std::string endereco,  unsigned long long int telefone) 
: Usuario (nome, cpf, id_usuario) {
    this->endereco = endereco;
    this->telefone = telefone;
}

// MÉTODOS SET

void Cliente::setNome(std::string Nome) {
        this->_nome = Nome;
}

void Cliente::setCPF( unsigned long long int CPF) {
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

// MOSTRA DADOS DO CLIENTE NA TELA

void Cliente::exibirDados() {
    std::cout << "-------------------------------------------\n";
    std::cout << "DADOS DO CLIENTE\n";
    std::cout << "NOME: "<< getNome() << std::endl;
    std::cout << "CPF: "<< getCPF() << std::endl;
    std::cout << "ID de usuario: "<< getID() << std::endl;
    std::cout << "ENDEREÇO: "<< getEndereco() << std::endl;
    std::cout << "TELEFONE: "<< getTelefone() << std::endl;
    std::cout << "-------------------------------------------\n";
}