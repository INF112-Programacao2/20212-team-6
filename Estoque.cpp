#if defined(_WIN32) || defined(_WIN64)
# define strtok_r strtok_s
#endif

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <stdlib.h>

#include "Estoque.h"
#include "produto.h"
#include "dispmovel.h"
#include "fone.h"
#include "notebook.h"
#include "televisores.h"
#include "Db_sys.h"


//inicialização de atributos static
double Estoque::valorTotalDoEstoque = 0;
int Estoque::qtdDeProdutos = 0;
std::vector<Produto*> Estoque::Estoque1 = {}; // inicia o estoque vazio

Estoque::Estoque() {}

void Estoque::setValorTotalDoEstoque(int qtde, double preco, int operacao)
{
    if (operacao == 1) // aumento
        valorTotalDoEstoque += preco * qtde;
    else if (operacao == 2) // decremento
        valorTotalDoEstoque -= preco * qtde;
}

void Estoque::Criar_arquivo_estoque()
{
    std::string res = "";

    res += "10012|100|8|Celular|Motorola|1|8|8|100%";
    res += "40013|1200|18|Televisao|LG|4|1080|34%";
    res += "30014|80|2|Fone|Sony|3|1|interno%";
    res += "20015|2000|7|Laptop|Apple|2|12|16|100%";

    Db_sys::salvar("produtos", res);
    
    
}

void Estoque::Ler_arquivo_estoque()
{
    const int size =5;
    std::string d = Db_sys::ler("produtos",0);
    char b[1000] = {};
    char tem[1000] = {};
    int sizex = 0;
    std::string hold[100] = {"","","",""};
    char* tk = nullptr;
    Produto pd[100] = {};
    for (int a = 0;a < d.length();a++)
    {
        if (d[a] == '%')
        {
            sizex++;
        }
        b[a] = d[a];
    }
    hold[0] = strtok_r(b,"%",&tk);
    for (int x = 1;x < sizex;x++)
    {
        hold[x] = strtok_r(NULL, "%", &tk);
    }

    //sizex--;
    double pdx=0;
    int qt = 0;
    int idx = 0;
    std::string des = "";
    std::string mar = "";
    int temp1 = 0;
    int temp2 = 0;
    int temp3 = 0;
    bool temq = false;
    std::string tm = "";
    //Produto* prod = nullptr;
    

    for (int q = 0;q < sizex;q++)
    {
        hold[q].copy(tem, hold[q].length() + 1);
        tem[hold[q].size() + 1] = '\0';
        idx = std::stoi(strtok_r(tem, "|", &tk));
        
        pdx = std::stoi(strtok_r(NULL, "|", &tk));
        qt = std::stoi(strtok_r(NULL, "|", &tk));
        des = strtok_r(NULL, "|", &tk);
        mar = strtok_r(NULL, "|", &tk);

        switch (std::stoi(strtok_r(NULL, "|", &tk)))
        {
            case(1):
            {
                temp1 = std::stoi(strtok_r(NULL, "|", &tk));
                temp2 = std::stoi(strtok_r(NULL, "|", &tk));
                temp3 = std::stoi(strtok_r(NULL, "|", &tk));
                Produto* prod = new DispMovel(idx,pdx,qt,mar,des,temp1,temp2,temp3);
                prod->setEmEstoque();
                Estoque1.push_back(prod);
                setValorTotalDoEstoque(prod->getQuantidade(), prod->getPreco(), 1);
                setQtdDeProdutos(prod->getQuantidade(), 1);

                break;
            }

            case(2):
            {
                temp1 = std::stoi(strtok_r(NULL, "|", &tk));
                temp2 = std::stoi(strtok_r(NULL, "|", &tk));
                temp3 = std::stoi(strtok_r(NULL, "|", &tk));
                Produto* prod = new Notebook(idx, pdx, qt, mar, des, temp1, temp2, temp3);
                prod->setEmEstoque();
                Estoque1.push_back(prod);
                setValorTotalDoEstoque(prod->getQuantidade(), prod->getPreco(), 1);
                setQtdDeProdutos(prod->getQuantidade(), 1);

                break;
            }

            case(3):
            {
                temq = (std::stoi(strtok_r(NULL, "|", &tk)) == 1) ? false : true;
                tm = strtok_r(NULL, "|", &tk);
                Produto* prod = new FoneDeOuvido(idx, pdx, qt, mar, des, temq,tm);
                prod->setEmEstoque();
                Estoque1.push_back(prod);
                setValorTotalDoEstoque(prod->getQuantidade(), prod->getPreco(), 1);
                setQtdDeProdutos(prod->getQuantidade(), 1);

                break;
            }

            case(4):
            {
                temp1 = std::stoi(strtok_r(NULL, "|", &tk));;
                temp2 = std::stoi(strtok_r(NULL, "|", &tk));
                Produto* prod = new Televisores(idx, pdx, qt, mar, des, temp1,temp2);
                prod->setEmEstoque();
                Estoque1.push_back(prod);
                setValorTotalDoEstoque(prod->getQuantidade(),prod->getPreco(),1);
                setQtdDeProdutos(prod->getQuantidade(),1);

                break;
            }

            default:
                break;
        }
    }
    
    



}

void Estoque::setQtdDeProdutos(int qtde, int operacao)
{
    if (operacao == 1) // aumento
        qtdDeProdutos += qtde;
    else if (operacao == 2)  // decremento
        qtdDeProdutos -= qtde;
}

double Estoque::getValorTotalDoEstoque() { return valorTotalDoEstoque; }

int Estoque::getQtdDeProdutos() { return qtdDeProdutos; }

bool possui_bt() // função local criada para identificar se o produto fone tem bluetooth no momento da entrada de dados
{
    std::cout << std::endl;
    int opcao_bt;
    bool _bt = false;
    bool _erro = false;

    std::cout << "POSSUI CONEXÃO VIA BLUETOOTH?" << std::endl;
    std::cout << std::endl;
opcoes_bt:
    std::cout << std::endl;
    std::cout << "|\t(1) Sim\n";
    std::cout << "|\t(2) Não\n";
    std::cout << std::endl;
    std::cout << "Digite o número correspondente a uma das opções acima: ";
    std::cin >> opcao_bt;

    if (opcao_bt == 1)
        _bt = true;
    else if (opcao_bt == 2)
        _bt = false;
    else
    {
        std::cout << "\tOpção inválida! Selecione uma das opções abaixo:\n";
        goto opcoes_bt;
    }

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
            if (Estoque1.at(i)->getEmEstoque())
            {
                Estoque1.at(i)->imprimirProduto();
                std::cout << std::endl;
            }
            else
            {
                std::cout << "\tProduto fora de estoque!\n";
                break;
            }
        }
        // else
        // {    
        //         std::cout << "\tProduto fora de estoque!\n";
        //         break;
        // }
    }
}

bool Estoque::identificaProduto(int codigo)
{   // varrerá o estoque procurando pelo produto com base no código
    bool em_estoque = false;

    for (int i = 0; i < Estoque1.size(); i++)
    {
        if (codigo == Estoque1[i]->getID())
        {
            em_estoque = Estoque1[i]->getEmEstoque();
            break;
        }
    }
    return em_estoque;
}

std::string Estoque::identificaDescricaoProduto(int codigo)
{   // varrerá o estoque procurando pelo produto com base no código e retorna sua descrição
    std::string descricao;
    for (int i = 0; i < Estoque1.size(); i++)
    {
        if (codigo == Estoque1[i]->getID())
        {
            descricao = Estoque1[i]->getDescricao();
            break;
        }
    }

    return descricao;
}

void Estoque::imprimeEstoque()
{
    std::cout << "____________________________ ESTOQUE TOTAL ____________________________" << std::endl;
    for (int i = 0; i < Estoque1.size(); i++)
    {
        std::cout << std::endl;
        Estoque1.at(i)->imprimirProduto();
        std::cout << std::endl;
    }
}

void Estoque::adicionar_produto()
{
    int opcao_produto; // registrará a opcao do usuario
    int codigo;        // atributos criados localmente para serem repassados ao métodos set do objeto produto
    double preco;
    int quantidade;
    std::string marca;
    std::string descricao;

    std::cout << "COMPLETE AS INFORMAÇÕES ABAIXO PARA REGISTRAR O NOVO PRODUTO NO ESTOQUE\n";
    std::cout << std::endl;
    std::cout << "ATENÇÃO: O código do produto será gerado automaticamente\n";
    std::cout << std::endl;
    std::cout << "|\tPRECO: ";
    std::cin >> preco;
    std::cout << "|\tQUANTIDADE: ";
    std::cin >> quantidade;
    std::cout << "|\tMARCA: ";
    std::cin.ignore();
    std::getline(std::cin, marca);
    std::cout << "|\tDESCRIÇÃO DO PRODUTO: ";
    std::getline(std::cin, descricao);
    std::cout << std::endl;

tiposProduto:
    std::cout << "QUAL TIPO DE PRODUTO DESEJA REGISTRAR?\n";
    std::cout << std::endl;
    std::cout << "\t1. Celular\n";
    std::cout << "\t2. Notebook\n";
    std::cout << "\t3. Fone de ouvido\n";
    std::cout << "\t4. Televisor\n";
    std::cout << std::endl;
    std::cout << "\tDigite a opção correspondente ao produto: ";
    std::cin >> opcao_produto;
    std::cout << std::endl;

    switch (opcao_produto)
    {
    case 1:
    { // atributos criados localmente para serem repassados aos construtores
        int tamanho_tela, ram, memoria;
        codigo = geradorID(10000, 19999); // intervalo fornecido para função foi o definido para os códigos que categorizam celulares
        if (identificaProduto(codigo))  //verifica se o código gerado já não existe
            codigo = geradorID(10000, 19999); // tenta gerar outro código caso o primeiro gerado já exista
        std::cout << "\tTAMANHO DA TELA (EM POLEGADAS): ";
        std::cin >> tamanho_tela;
        std::cout << "\tRAM (GB): ";
        std::cin >> ram;
        std::cout << "\tMEMÓRIA (GB): ";
        std::cin >> memoria;
        // instanciando objeto da classe produto para criar um produto do tipo celular
        Produto* _p1 = new DispMovel(codigo, preco, quantidade, marca, descricao, tamanho_tela, ram, memoria);
        _p1->setEmEstoque();
        Estoque1.push_back(_p1); // guardando produto criado no estoque
        break;
    }
    case 2:
    { // atributos criados localmente para serem repassados aos construtores
        int tamanho_tela2, ram2, memoria2;
        codigo = geradorID(20000, 29999); // intervalo fornecido para função foi o definido para os códigos que categorizam notebooks
        if (identificaProduto(codigo))  //verifica se o código gerado já não existe
            codigo = geradorID(20000, 29999); // tenta gerar outro código caso o primeiro gerado já exista
        std::cout << "|\tTAMANHO DA TELA (EM POLEGADAS): ";
        std::cin >> tamanho_tela2;
        std::cout << "|\tRAM (GB): ";
        std::cin >> ram2;
        std::cout << "|\tMEMÓRIA (GB): ";
        std::cin >> memoria2;
        // instanciando objeto da classe produto para criar um produto do tipo notebook
        Produto* _p2 = new Notebook(codigo, preco, quantidade, marca, descricao, tamanho_tela2, ram2, memoria2);
        _p2->setEmEstoque();
        Estoque1.push_back(_p2); // guardando produto criado no estoque
        break;
    }
    case 3:
    { // atributos criados localmente para serem repassados aos construtores
        bool _bt;
        int _tipo;
        std::string __tipo;
        codigo = geradorID(30000, 39999); // intervalo fornecido para função foi o definido para os códigos que categorizam fones de ouvido
        if (identificaProduto(codigo))  //verifica se o código gerado já não existe
            codigo = geradorID(30000, 39999); // tenta gerar outro código caso o primeiro gerado já exista
        std::cout << std::endl;
    opcoes_tipo_fone:
        std::cout << "DIGITE O NUMERO CORRESPONDENTE AO TIPO DE FONE" << std::endl;
        std::cout << std::endl;
        std::cout << "\t1. AURICULAR       | Simples, pequenos e leves " << std::endl;
        std::cout << "\t2. INTRA-AURICULAR | Fones com borracha, encaixam no canal auditivo" << std::endl;
        std::cout << "\t3. SUPRA-AURICULAR | Posicionados sobre a orelha" << std::endl;
        std::cout << "\t4. CIRCUMAURAL     | Grandes, cobrem toda a orelha" << std::endl;
        std::cout << std::endl;
        std::cout << "OPCAO: ";
        std::cin >> _tipo;

        switch (_tipo)
        {
        case 1:
        {
            __tipo = "Auricular";
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
            std::cout << "\tOpcao invalida! Selecione uma das opcoes exibidas\n";
            goto opcoes_tipo_fone; // vai para o início do menu
            break;
        }
        }
        // instanciando objeto da classe produto para criar um produto do tipo fone de ouvido
        Produto* _p3 = new FoneDeOuvido(codigo, preco, quantidade, marca, descricao, _bt, __tipo);
        _p3->setEmEstoque();
        Estoque1.push_back(_p3); // adicionando produto criado ao estoque
        break;
    }
    case 4:
    { // atributos criados localmente para serem repassados aos construtores
        int tela;
        int resolucao;
        codigo = geradorID(40000, 49999); // intervalo fornecido para função foi o definido para os códigos que categorizam celulares
        if (identificaProduto(codigo))
            codigo = geradorID(40000, 49999); // tenta gerar outro código caso o primeiro gerado já exista
        std::cout << "Complete as informações abaixo para finalizar o registro do televisor" << std::endl;
        std::cout << std::endl;
        std::cout << "|\tTAMANHO DA TELA (EM POLEGADAS): ";
        std::cin >> tela;
        std::cout << "|\tRESOLUÇÃO (p): ";
        std::cin >> resolucao;
        // instanciando objeto da classe produto para criar um produto do tipo televisor
        Produto* _p4 = new Televisores(codigo, preco, quantidade, marca, descricao, tela, resolucao);
        _p4->setEmEstoque();
        Estoque1.push_back(_p4); // adicionando produto criado ao estoque
        break;
    }
    default:
    {
        std::cout << "\tOpção inválida! Selecione uma das opções DO MENU\n";
        goto tiposProduto; // vai para o início do menu
        break;
    }
    }

    // atualizando qtde total de produtos em estoque e valor total do estoque de acordo com as informações dos produtos registrados
    setValorTotalDoEstoque(quantidade, preco, 1);
    setQtdDeProdutos(quantidade, 1);

    std::cout << std::endl;
    std::cout << "\tProduto adicionado ao estoque com sucesso!\n";
}

void Estoque::excluir_produto(int codigo, int qdte) {    // verificar lógica disso
    int qtde_produto_restante;
    for (int i = 0; i < Estoque1.size(); i++)
    {
        if (codigo == Estoque1[i]->getID())
        {
            qtde_produto_restante = Estoque1[i]->getQuantidade() - qdte;
            setQtdDeProdutos(qdte, 2);   // qtde de produtos em estoque
            setValorTotalDoEstoque(qdte, Estoque1[i]->getPreco(), 2);   // atualiza valor do estoque
            Estoque1[i]->setQuantidade(qtde_produto_restante);   // atualizando quantidade do produto em si
        }
    }
}

void Estoque::excluir_produto(int codigo) { // verificar lógica disso
    for (int i = 0; i < Estoque1.size(); i++)
    {
        if (codigo == Estoque1[i]->getID())
        {
            setQtdDeProdutos(Estoque1[i]->getQuantidade(), 2);  // atualizando valores antes da exclusão do produto
            setValorTotalDoEstoque(Estoque1[i]->getQuantidade(), Estoque1[i]->getPreco(), 2);
            Estoque1[i]->setQuantidade(0);
            break;
        }
    }
}

void Estoque::Relatorio()
{
    if (Estoque1.empty())
    {
        std::cout << std::endl;
        std::cout << "\tATENCAO: Estoque vazio!" << std::endl;
        std::cout << "\tRegistre os produtos para visualizá-los" << std::endl;
        std::cout << std::endl;
    }
    else
    {
        // dar opcoes para visualização do estoque por produto
        int opcao_geral;
        int opcao_produtos_;

        std::cout << "____________________________ AREA DO ESTOQUE ____________________________" << std::endl;
        std::cout << "_________________________________________________________________________\n";
        std::cout << std::endl;
    menu_estoque:
        std::cout << "\t1. Visualizar produtos por categoria\n";
        std::cout << std::endl;
        std::cout << "\tCELULARES, NOTEBOOKS, FONES DE OUVIDO, TELEVISORES\n";
        std::cout << std::endl;
        std::cout << "\t2. Visualizar todos os produtos\n";
        std::cout << std::endl;
        std::cout << "_________________________________________________________________________\n";
        std::cout << std::endl;
        std::cout << "\tDigite um número correspondente a uma das opcoes acima\n";
        std::cout << std::endl;
        std::cout << "\tOU Aperte 3 para voltar ao menu anterior: ";
        std::cin >> opcao_geral;
        std::cout << std::endl;

        switch (opcao_geral)
        {
        case 1:
        {
        menu_produtos:
            std::cout << "  Selecione uma das opcoes de produto para visualização     \n";
            std::cout << std::endl;
            std::cout << "\t(1) CELULARES\n";
            std::cout << "\t(2) NOTEBOOKS\n";
            std::cout << "\t(3) FONES DE OUVIDO\n";
            std::cout << "\t(4) TELEVISORES\n";
            std::cout << std::endl;
            std::cout << "\tDigite o número correspondente à opcao: ";
            std::cin >> opcao_produtos_;
            std::cout << std::endl;

            switch (opcao_produtos_)
            {
            case 1:
            {
                imprimeProdutoEmEstoque(10000, 19999);         // exibe de acordo com intervalo referente ao produto
                break;
            }
            case 2:
            {
                imprimeProdutoEmEstoque(20000, 29999);         // exibe de acordo com intervalo referente ao produto
                break;
            }
            case 3:
            {
                imprimeProdutoEmEstoque(30000, 39999);         // exibe de acordo com intervalo referente ao produto
                break;
            }
            case 4:
            {
                imprimeProdutoEmEstoque(40000, 49999);         // exibe de acordo com intervalo referente ao produto
                break;
            }
            default:
            {
                std::cout << "\tOPÇÃO INVÁLIDA! Selecione uma das opções DO MENU: ";
                goto menu_produtos;
                break;
            }
            }

            break;
        }
        case 2:
        {
            imprimeEstoque();
            std::cout << "\tValor total do estoque em reais: R$ " << getValorTotalDoEstoque() << std::endl;
            std::cout << "\tQuantidade total de produtos em estoque: " << getQtdDeProdutos() << std::endl;
            std::cout << std::endl;
            break;
        }
        case 3:
            break;
        default:
        {
            std::cout << "OPÇÃO INVÁLIDA! Selecione uma das opções DO MENU:\n";
            goto menu_estoque;
            break;
        }
        }
    }
}

Estoque::~Estoque() {}
