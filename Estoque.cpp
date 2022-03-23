#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "Estoque.h"
#include "produto.h"
#include "dispmovel.h"
#include "fone.h"
#include "notebook.h"
#include "televisores.h"

//inicialização de atributos static
double Estoque::valorTotalDoEstoque = 0;
int Estoque::qtdDeProdutos = 0;
std::vector<Produto*> Estoque::Estoque1 = {}; // inicia o estoque vazio

Estoque::Estoque() {}

void Estoque::setValorTotalDoEstoque(int qtde, double preco, int operacao) 
{ 
    if (operacao==1) // aumento
        valorTotalDoEstoque += preco * qtde;
    else if (operacao==2) // decremento
        valorTotalDoEstoque -= preco * qtde;
}

void Estoque::setQtdDeProdutos(int qtde, int operacao) 
{ 
    if (operacao==1) // aumento
        qtdDeProdutos += qtde;
    else if (operacao==2)  // decremento
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
            if(Estoque1.at(i)->getEmEstoque())
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
        else
        {    
                std::cout << "\tProduto fora de estoque!\n";
                break;
        }
    }
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

bool Estoque::identificaProduto(int codigo)
{   // varrerá o estoque procurando pelo produto com base no código
    bool em_estoque = false;
    
    for (int i = 0; i < Estoque1.size(); i++)     
    {
        if (codigo==Estoque1[i]->getID()) 
        {
            em_estoque = Estoque1[i]->getEmEstoque();
            break;
        }
    }
    return em_estoque;
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
            Produto *_p1 = new DispMovel(codigo, preco, quantidade, marca, descricao, tamanho_tela, ram, memoria);
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
            Produto *_p2 = new Notebook(codigo, preco, quantidade, marca, descricao, tamanho_tela2, ram2, memoria2);
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
            Produto *_p3 = new FoneDeOuvido(codigo, preco, quantidade, marca, descricao, _bt, __tipo);
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
            Produto *_p4 = new Televisores(codigo, preco, quantidade, marca, descricao, tela, resolucao);
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

void Estoque::excluir_produto() 
{
    int codigo;        // atributos criados localmente para localizar o produto no estoque
    int quantidade;
    double preco;
    int opcao_geral;
    int opcao_est;
    int opcao_consulta;
    int nova_qtd;

    menu_excluiProduto:
    std::cout << "__________________________ OPÇÕES __________________________\n";
    std::cout << std::endl;
    std::cout << "  1. REMOVER SOMENTE ALGUMAS UNIDADES DO PRODUTO\n";
    std::cout << "  2. REMOVER O PRODUTO DO ESTOQUE\n";
    std::cout << std::endl;
    std::cout << "____________________________________________________________\n";
    std::cout << std::endl;
    std::cout << "Digite uma das opções acima: ";
    std::cin >> opcao_geral;
    std::cout << std::endl;

    switch(opcao_geral)
    {
        case 1:
        {   
            // o usuário informará um código, que será usado para buscar pelo produto no estoque, e uma quantidade
            // o produto será procurado, se for encontrado sua quantidade será atualizada com a subtração da quantidade informada pelo usuário
            // caso contrário, será informado que o produto não está no estoque
            std::cout << "\tDeseja consultar o estoque antes de prosseguir?" << std::endl;
            std::cout << std::endl;
            std::cout << "\t1. SIM\n";
            std::cout << "\t2. NÃO\n";
            std::cout << std::endl;
            std::cout << "\tDigite uma das opções acima: ";
            std::cin >> opcao_consulta;

            if (opcao_consulta==1)
                imprimeEstoque();

            std::cout << "____________________________________________________________\n";
            std::cout << std::endl;
            std::cout << "  Preencha as informacoes abaixo\n";
            std::cout << "\tCÓDIGO DO PRODUTO: ";
            std::cin >> codigo;
            std::cout << "\tQUANTIDADE A RETIRAR DO ESTOQUE: ";
            std::cin >> quantidade;
            std::cout << "____________________________________________________________\n";
            std::cout << std::endl;

            if (identificaProduto(codigo))
            {
                for (int i = 0; i < Estoque1.size(); i++)     
                {
                    if (codigo==Estoque1[i]->getID()) 
                    {
                        preco = Estoque1[i]->getPreco();
                        nova_qtd = Estoque1[i]->getQuantidade() - quantidade;
                        Estoque1[i]->setQuantidade(nova_qtd);   // atualizando quantidade do produto em questão
                    }
                }
                setQtdDeProdutos(quantidade, 2);     // atualiza qtde total de produtos e valor total do estoque após exclusão do produto
                setValorTotalDoEstoque(quantidade, preco, 2);

                std::cout << "\tPRODUTO RETIRADO DO ESTOQUE COM SUCESSO!" << std::endl;
                std::cout << std::endl;
            }
            else
            {
                std::cout << "ATENÇÃO: PRODUTO FORA DE ESTOQUE!" << std::endl;
                std::cout << std::endl;
            }
            break;                     
        }
        case 2:
        {   // o usuário informará um código, que será usado para buscar pelo produto no estoque
            // a partir dele, o programa buscará pelo produto no estoque e o removerá
            std::cout << "\tDeseja consultar o estoque antes de prosseguir?" << std::endl;
            std::cout << std::endl;
            std::cout << "\t1. SIM\n";
            std::cout << "\t2. NÃO\n";
            std::cout << std::endl;
            std::cout << "\tDigite uma das opções acima: ";
            std::cin >> opcao_consulta;

            if (opcao_consulta==1)
                imprimeEstoque();

            std::cout << std::endl;
            std::cout << "  INFORME O CÓDIGO DO PRODUTO: ";
            std::cin >> codigo;
            std::cout << std::endl;
            std::cout << "_________________________________________________________________\n";

            if (identificaProduto(codigo))
            {
                for (int i = 0; i < Estoque1.size(); i++)     
                {
                    if (codigo==Estoque1[i]->getID()) 
                    {   
                        setQtdDeProdutos(Estoque1[i]->getQuantidade(), 2);  // atualizando valores antes da exclusão do produto
                        setValorTotalDoEstoque(Estoque1[i]->getQuantidade(), Estoque1[i]->getPreco(), 2);
                        Estoque1[i]->setQuantidade(0);
                        break;
                    }
                }

                std::cout << "\tPRODUTO RETIRADO DO ESTOQUE COM SUCESSO!" << std::endl;
            }
            else
                std::cout << "\tATENÇÃO: PRODUTO FORA DE ESTOQUE!" << std::endl;

            break;    
        }
        default:
        {   
            std::cout << "OPÇÃO INVÁLIDA! Selecione uma das opções DO MENU:\n";
            goto menu_excluiProduto;
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
        std::cout << "\t3. Remover produto do estoque\n";
        std::cout << std::endl;
        std::cout << "_________________________________________________________________________\n";
        std::cout << std::endl;
        std::cout << "\tDigite um número correspondente a uma das opcoes acima: ";
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
            {
                excluir_produto();
                break;
            }
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
