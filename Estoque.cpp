#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#include "Estoque.h"
#include "produto.h"
#include "dispmovel.h"
#include "fone.h"
#include "notebook.h"
#include "televisores.h"

double Estoque::valorTotalDoEstoque = 0;
int Estoque::qtdDeProdutos = 0;
std::vector<Produto *> Estoque::Estoque1 = {}; // inicia o estoque vazio

Estoque::Estoque() {}

void Estoque::setValorTotalDoEstoque(int qtde, double preco) { valorTotalDoEstoque += preco * qtde; }

void Estoque::setQtdDeProdutos(int qtde) { qtdDeProdutos += qtde; }

double Estoque::getValorTotalDoEstoque() { return valorTotalDoEstoque; }

int Estoque::getQtdDeProdutos() { return qtdDeProdutos; }

bool possui_bt() // função local criada para identificar se o produto fone tem bluetooth no momento da entrada de dados
{
    int opcao_bt;
    bool _bt = false;
    bool _erro = false;
    // FAZER TRATAMENTO DE EXCECAO AQUI
    // try
    // {
        std::cout << "POSSUI CONEXAO VIA BLUETOOTH?" << std::endl;
        std::cout << std::endl;
        std::cout << "| (1) Sim\n";
        std::cout << "| (2) Não\n";
        std::cout << std::endl;
        std::cout << "Digite o numero correspondente a uma das opcoes acima: ";
        std::cin >> opcao_bt;

    //     if ((opcao_bt != 1) && (opcao_bt != 2) || std::cin.fail())
    //     {
    //         throw std::invalid_argument("ERRO: Voce deve escolher uma das opcoes acima: \n");
    //     }
    // }
    // catch (std::invalid_argument &erro)
    // {
    //     std::cerr << erro.what();
    //     std::cin >> opcao_bt;
    // }

    if (opcao_bt == 1)
        _bt = true;
    else if (opcao_bt == 2)
        _bt = false;

    return _bt;
}

int Estoque::geradorID(int a, int b) // gerará um código aleatório para o produto dentro do intervalo fornecido
{
    int x = b - a; // para ver quantos números há no intervalo fornecido
    srand((unsigned)time(0));
    return a + (rand() % x);
}

void Estoque::imprimeProdutoEmEstoque(int a, int b)
{
    for (int i = 0; i < Estoque1.size(); i++)
    {
        if ((Estoque1.at(i)->getID() >= a) && (Estoque1.at(i)->getID() <= b))
        {
            Estoque1.at(i)->imprimirProduto();
            std::cout << std::endl;
        }
    }
}

void Estoque::adicionar_produto()
{
    int opcao_produto; // registrará a opcao do usuario
    int codigo;        // atributos criados localmente para serem repassados ao métodos set do objeto produto
    double preco;
    int quantidade;
    std::string marca;

    std::cout << "COMPLETE AS INFORMACOES ABAIXO PARA REGISTRAR O NOVO PRODUTO NO ESTOQUE\n";
    std::cout << std::endl;
    std::cout << "Observaçao: O código do produto será gerado automaticamente\n";
    std::cout << "|   PRECO: ";
    std::cin >> preco;
    std::cout << "|   QUANTIDADE: ";
    std::cin >> quantidade;
    std::cout << "|   MARCA: ";
    std::cin.ignore();
    std::getline(std::cin, marca);
    std::cout << std::endl;

z: // FAZER TRATAMENTO DE EXCECAO AQUI
    std::cout << "QUAL TIPO DE PRODUTO DESEJA REGISTRAR?\n";
    std::cout << std::endl;
    std::cout << "1. Celular\n";
    std::cout << "2. Notebook\n";
    std::cout << "3. Fone de ouvido\n";
    std::cout << "4. Televisor\n";
    std::cout << std::endl;
    std::cin >> opcao_produto;

    switch (opcao_produto)
    {
        case 1:
        { // atributos criados localmente para serem repassados aos construtores
            int tamanho_tela, ram, memoria;
            codigo = geradorID(10000, 19999); // intervalo fornecido para função foi o definido para os códigos que categorizam celulares
            std::cout << "TAMANHO DA TELA (EM POLEGADAS): ";
            std::cin >> tamanho_tela;
            std::cout << "RAM: ";
            std::cin >> ram;
            std::cout << "MEMORIA: ";
            std::cin >> memoria;
            // instanciando objeto da classe produto para criar um produto do tipo celular
            Produto *_p1 = new DispMovel(codigo, preco, quantidade, marca, tamanho_tela, ram, memoria);
            Estoque1.push_back(_p1); // guardando produto criado no estoque
            break;
        }
        case 2:
        { // atributos criados localmente para serem repassados aos construtores
            int tamanho_tela2, ram2, memoria2;
            codigo = geradorID(20000, 29999); // intervalo fornecido para função foi o definido para os códigos que categorizam notebooks
            std::cout << "|   TAMANHO DA TELA (EM POLEGADAS): ";
            std::cin >> tamanho_tela2;
            std::cout << "|   RAM: ";
            std::cin >> ram2;
            std::cout << "|   MEMORIA: ";
            std::cin >> memoria2;
            // instanciando objeto da classe produto para criar um produto do tipo notebook
            Produto *_p2 = new Notebook(codigo, preco, quantidade, marca, tamanho_tela2, ram2, memoria2);
            Estoque1.push_back(_p2); // guardando produto criado no estoque
            break;
        }
        case 3:
        { // atributos criados localmente para serem repassados aos construtores
            bool _bt;
            int _tipo;
            std::string __tipo;
            codigo = geradorID(30000, 39999); // intervalo fornecido para função foi o definido para os códigos que categorizam fones de ouvido

        x: // FAZER TRATAMENTO DE EXCECAO AQUI
            std::cout << std::endl;
            std::cout << "DIGITE O NUMERO CORRESPONDENTE AO TIPO DE FONE" << std::endl;
            std::cout << std::endl;
            std::cout << "1. AURICULAR       | Simples, pequenos e leves " << std::endl;
            std::cout << "2. INTRA-AURICULAR | Fones com borracha, encaixam no canal auditivo" << std::endl;
            std::cout << "3. SUPRA-AURICULAR | Posicionados sobre a orelha" << std::endl;
            std::cout << "4. CIRCUMAURAL     | Grandes, cobrem toda a orelha" << std::endl;
            std::cout << std::endl;
            std::cout << "OPCAO: ";
            std::cin >> _tipo;

            switch (_tipo)
            {
                case 1:
                {
                    __tipo = "Auricular";
                    _bt = possui_bt();
                    break;
                }
                case 2:
                {
                    __tipo = "Intra-auricular";
                    _bt = possui_bt();
                    break;
                }
                case 3:
                {
                    __tipo = "Supra-auricular";
                    _bt = possui_bt();
                    break;
                }
                case 4:
                {
                    __tipo = "Circumaural";
                    _bt = possui_bt();
                    break;
                }
                default:
                {
                    std::cout << "Opcao invalida! Selecione uma das opcoes exibidas\n";
                    goto x; // vai para o início do menu
                    break;
                }
            }
            // instanciando objeto da classe produto para criar um produto do tipo fone de ouvido
            Produto *_p3 = new FoneDeOuvido(codigo, preco, quantidade, marca, _bt, __tipo);
            Estoque1.push_back(_p3); // adicionando produto criado ao estoque
            break;
        }
        case 4:
        { // atributos criados localmente para serem repassados aos construtores
            int tela;
            int resolucao;
            codigo = geradorID(40000, 49999); // intervalo fornecido para função foi o definido para os códigos que categorizam celulares

            std::cout << "Complete as informações abaixo para finalizar o registro do televisor" << std::endl;
            std::cout << std::endl;
            std::cout << "|   TAMANHO DA TELA (EM POLEGADAS): ";
            std::cin >> tela;
            std::cout << "|   RESOLUCAO (p): ";
            std::cin >> resolucao;
            // instanciando objeto da classe produto para criar um produto do tipo televisor
            Produto *_p4 = new Televisores(codigo, preco, quantidade, marca, tela, resolucao);
            Estoque1.push_back(_p4); // adicionando produto criado ao estoque
            break;
        }
        default:
        {
            std::cout << "Opcao invalida! Selecione uma das opcoes DO MENU\n";
            goto z; // vai para o início do menu
            break;
        }
    }

    // atualizando qtde total de produtos em estoque e valor total do estoque de acordo com as informações dos produtos registrados
    setValorTotalDoEstoque(quantidade, preco);
    setQtdDeProdutos(quantidade);

    std::cout << "Produto adicionado ao estoque com sucesso!\n";
}

void Estoque::Relatorio()
{
    if (Estoque1.empty())
    {
        std::cout << "ATENCAO: Estoque vazio!" << std::endl;
    }
    else
    {
        // dar opcoes para visualização do estoque por produto
        int opcao_geral;
        int opcao_produtos_;

        std::cout << "____________________________ AREA DO ESTOQUE ____________________________" << std::endl;
        std::cout << "_________________________________________________________________________\n";
        std::cout << "   OPCOES\n";
        std::cout << "" << std::endl;
        std::cout << "   1. Visualizar produtos disponíveis por categoria\n";
        std::cout << "      CELULARES, NOTEBOOKS, FONES DE OUVIDO, TELEVISORES\n";
        std::cout << "   2. Visualizar todos os produtos disponíveis\n";    // falta implementar
        std::cout << "" << std::endl;
        std::cout << "_________________________________________________________________________\n";
        std::cout << "Digite um numero correspondente a uma das opcoes acima: ";
        std::cin >> opcao_geral;

        switch (opcao_geral)
        {
            case 1: // FAZER TRATAMENTO DE EXCECAO AQUI
            {
                menu_produtos:
                std::cout << "  Selecione uma das opcoes de produto para visualização     \n";
                std::cout << "      (1) CELULARES\n";
                std::cout << "      (2) NOTEBOOKS\n";
                std::cout << "      (3) FONES DE OUVIDO\n";
                std::cout << "      (4) TELEVISORES\n";
                std::cout << std::endl;
                std::cout << "  Digite o numero correspondente a opcao: ";
                std::cin >> opcao_produtos_;

                switch (opcao_produtos_)
                {
                    case 1:
                    {
                        std::cout << "EXIBINDO CELULARES EM ESTOQUE..\n";
                        imprimeProdutoEmEstoque(10000, 19999);         // exibe de acordo com intervalo referente ao produto
                        break;
                    }
                    case 2:
                    {
                        std::cout << "EXIBINDO NOTEBOOKS EM ESTOQUE..\n";
                        imprimeProdutoEmEstoque(20000, 29999);         // exibe de acordo com intervalo referente ao produto
                        break;
                    }
                    case 3:
                    {
                        std::cout << "EXIBINDO FONES DE OUVIDO EM ESTOQUE..\n";
                        imprimeProdutoEmEstoque(30000, 39999);         // exibe de acordo com intervalo referente ao produto
                        break;
                    }
                    case 4:
                    {
                        std::cout << "EXIBINDO TELEVISORES EM ESTOQUE..\n";
                        imprimeProdutoEmEstoque(40000, 49999);         // exibe de acordo com intervalo referente ao produto
                        break;
                    }
                    default:
                    {
                        std::cout << "OPCAO INVALIDA! Selecione uma das opcoes DO MENU: ";
                        goto menu_produtos;
                        break;
                    }
                }

                break;
            }
            case 2:
            {
                std::cout << "MENU\n";    // apenas pra teste, será completado depois com a visualização de todos os produtos em estoque
                break;
            }
            default:
            {
                std::cout << "MENU 2\n"; // apenas pra teste, será completado depois
                break;
            }
        }
        std::cout << "Valor total do estoque em reais: R$ " << getValorTotalDoEstoque() << std::endl;
        std::cout << "Quantidade total de produtos em estoque: " << getQtdDeProdutos() << std::endl;
        std::cout << std::endl;
    }
}

Estoque::~Estoque() {}
