#include "login.h"
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

void cadastraLogin(){
    FILE *ponteiro_arquivo; // criando um ponteiro para o arquivo
    char user[32];
    char password[32];

    ponteiro_arquivo = fopen("database.dat", "a"); // abrindo o arquivo em modo de gravação, caso o arquivo não seja encontrado ele será criado automaticamente
    if(ponteiro_arquivo == NULL)
        throw std::invalid_argument("Arquivo não foi encontrado.");
    
    std::cout << "Por favor, digite um nome de usuario.\n";
    std::cin >> user;
    std::cout << "Agora escolha a sua senha.\n";
    std::cin >> password;

    //Criptografia simples com base na Cifra de César
    for(int i=0;i<strlen(user);i++){
        user[i] = user[i]-11;
    }
    for(int i=0;i<strlen(password);i++){
        password[i] = password[i]-11;
    }
    //Gravando usuario e senha no arquivo "database"
    fprintf(ponteiro_arquivo, "%s", user);
    fprintf(ponteiro_arquivo, ":");
    fprintf(ponteiro_arquivo, "%s", password);
    fprintf(ponteiro_arquivo, "\n");
    fclose(ponteiro_arquivo);
    std::cout << "\tCadastro efetuado com sucesso!\n";
}

bool verificaLogin(){
    std::ifstream entrada("database.dat");
    char login[65];
    char linhatemp[65]; // string que vai guardar temporariamente cada linha da database
    char user[32];
    char password[32];
    char userdecrypt[32];
    char passworddecrypt[32];

    std::cout << "Usuário: ";
    std::cin >> user;
    std::cout << "Senha: ";
    std::cin >> password;
    std::cout << R"(
                  .----.
      .---------. | == |
      |.-"""""-.| |----|
      ||       || | == |
      ||       || |----|
      |'-.....-'| |::::|
      `"")---(""` |___.|
     /:::::::::::\" _  "
    /:::=======:::\`\`\
    `"""""""""""""`  '-'       
)" << '\n';
    std::cout << "Verificando login...\n";
    strcpy(login, user);
    strcat(login, ":");
    strcat(login, password);
    while(true){
        entrada.getline(linhatemp, 65);
        for(int i=0;i<strlen(linhatemp);i++){
            if(linhatemp[i]!=':')
                linhatemp[i] = linhatemp[i]+11;
        }

        if(strcmp(linhatemp,login)==0){
            std::cout << "Acesso garantido!\n";
            return true;
        }
        if(entrada.eof())
            break;
    }
    std::cout << "Usuário ou senha incorretos.\n";
    return false;
}

void imprimeASCII(){
    std::cout << R"(
──────────────────────────────────────────────────────────────────────────────────────────────────
─██████████████─████████████████───██████──██████─██████████████─██████████████────██████████████─
─██░░░░░░░░░░██─██░░░░░░░░░░░░██───██░░██──██░░██─██░░░░░░░░░░██─██░░░░░░░░░░██────██░░░░░░░░░░██─
─██░░██████████─██░░████████░░██───██░░██──██░░██─██░░██████░░██─██░░██████░░██────██░░██████████─
─██░░██─────────██░░██────██░░██───██░░██──██░░██─██░░██──██░░██─██░░██──██░░██────██░░██─────────
─██░░██─────────██░░████████░░██───██░░██──██░░██─██░░██████░░██─██░░██──██░░██────██░░██████████─
─██░░██──██████─██░░░░░░░░░░░░██───██░░██──██░░██─██░░░░░░░░░░██─██░░██──██░░██────██░░░░░░░░░░██─
─██░░██──██░░██─██░░██████░░████───██░░██──██░░██─██░░██████████─██░░██──██░░██────██░░██████░░██─
─██░░██──██░░██─██░░██──██░░██─────██░░██──██░░██─██░░██─────────██░░██──██░░██────██░░██──██░░██─
─██░░██████░░██─██░░██──██░░██████─██░░██████░░██─██░░██─────────██░░██████░░██────██░░██████░░██─
─██░░░░░░░░░░██─██░░██──██░░░░░░██─██░░░░░░░░░░██─██░░██─────────██░░░░░░░░░░██────██░░░░░░░░░░██─
─██████████████─██████──██████████─██████████████─██████─────────██████████████────██████████████─
──────────────────────────────────────────────────────────────────────────────────────────────────)";

    std::cout << "\n\t\t\t\tBem vindo, usuário!\n";

}
bool menuPrincipal(){
    int escolha;
    std::cout << "\n\t1 - Login\n\t2 - Cadastro\n";

    std::cout << "\nSelecione uma opção: "; 
    std::cin >> escolha;
    if(std::cin.fail()){
        throw std::invalid_argument("Digite um número.\n");
    }
    if(escolha > 2 || escolha < 1){
        throw std::invalid_argument("Escolha uma opção válida.\n");
    }
    if(escolha==1){
        if(verificaLogin())
            return true;
    }
    if(escolha==2){
        cadastraLogin();
    }
    return false;
}