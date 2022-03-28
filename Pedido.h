#ifndef PEDIDO_H
#define PEDIDO_H

#include "Produto.h"

class Pedido
{
	public:
		static const int size = 100;
		static int ph_id;
		Pedido();
		~Pedido();
		Produto carrinho[size];
		int quantidade[size];
		void add_produto(Produto& p);
		double valor_total();
		int p_size;
		void limpar_carrinho();
		int remover_item(std::string in);
		void listar_produtos();

	private:

};

#endif
