// arvore_binaria.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <stdio.h>
#include <stdlib.h>

typedef struct no_st {
	int dados;
	struct no_st* esquerda;
	struct no_st* direita;
} *no;

int contaNos(no raiz) {
	if (raiz->direita == NULL && raiz->esquerda == NULL)
	{
		return 1;
	}
	else
	{
		if (raiz->esquerda == NULL)
		{
			return 1 + contaNos(raiz->direita);
		}
		else if(raiz->direita == NULL)
		{
			return 1 + contaNos(raiz->esquerda);
		}
		else
		{
			
			return 1 + contaNos(raiz->esquerda) + contaNos(raiz->direita);
		}
		
	}
	
}

int somaNos(no raiz) {
	if (raiz == NULL)
	{
		return 0;
	}
	else
	{
		return raiz->dados + somaNos(raiz->esquerda) + somaNos(raiz->direita);
	}
}

void mostraPreOrder(no raiz) {
	printf("%d, ", raiz->dados);
	
	if (raiz->esquerda != NULL && raiz->direita != NULL)
	{
		mostraPreOrder(raiz->esquerda);
		mostraPreOrder(raiz->direita);
	}
	else
	{
		if (raiz->esquerda != NULL)
		{
			mostraPreOrder(raiz->esquerda);
		}
		if (raiz->direita != NULL)
			mostraPreOrder(raiz->direita);
	}
	
}

void mostraInOrder(no raiz) {
	if (raiz != NULL) {
		mostraInOrder(raiz->esquerda);
		printf("%d, ", raiz->dados);
		mostraInOrder(raiz->direita);
	}
}

void mostraPosOrder(no raiz) {
	
	if (raiz != NULL) {
		mostraPosOrder(raiz->esquerda);
		mostraPosOrder(raiz->direita);
		printf("%d, ", raiz->dados);
	}
	
}

int contaPeso(no raiz) {
	if (raiz == NULL)
	{
		return 0;
	}
	else
	{
		if (contaPeso(raiz->direita) > contaPeso(raiz->esquerda))
		{
			return 1 + contaPeso(raiz->direita);
		}
		else
		{
			return 1 + contaPeso(raiz->esquerda);
		}
	}
	
}

int main() {

	no raiz = NULL;
	no novo = NULL;

	novo = (no)malloc(sizeof(struct no_st));
	novo->dados = 12;
	novo->esquerda = NULL;
	novo->direita = NULL;
	raiz = novo;

	novo = (no)malloc(sizeof(struct no_st));
	novo->dados = 8;
	novo->esquerda = NULL;
	novo->direita = NULL;
	raiz->esquerda = novo;

	novo = (no)malloc(sizeof(struct no_st));
	novo->dados = 9;
	novo->esquerda = NULL;
	novo->direita = NULL;
	raiz->esquerda->direita = novo;

	novo = (no)malloc(sizeof(struct no_st));
	novo->dados = 10;
	novo->esquerda = NULL;
	novo->direita = NULL;
	raiz->esquerda->direita->direita = novo;

	novo = (no)malloc(sizeof(struct no_st));
	novo->dados = 7;
	novo->esquerda = NULL;
	novo->direita = NULL;
	raiz->esquerda->esquerda = novo;

	novo = (no)malloc(sizeof(struct no_st));
	novo->dados = 15;
	novo->esquerda = NULL;
	novo->direita = NULL;
	raiz->direita = novo;

	novo = (no)malloc(sizeof(struct no_st));
	novo->dados = 17;
	novo->esquerda = NULL;
	novo->direita = NULL;
	raiz->direita->direita = novo;

	novo = (no)malloc(sizeof(struct no_st));
	novo->dados = 13;
	novo->esquerda = NULL;
	novo->direita = NULL;
	raiz->direita->esquerda = novo;

	novo = (no)malloc(sizeof(struct no_st));
	novo->dados = 11;
	novo->esquerda = NULL;
	novo->direita = NULL;
	raiz->esquerda->direita->direita->direita = novo;

	printf("\nNUMERO de NOS: %d", contaNos(raiz));
	printf("\nSOMA = %d", somaNos(raiz));

	printf("\n\nPreOrder ");
	mostraPreOrder(raiz);

	printf("\n\nInOrder ");
	mostraInOrder(raiz);

	printf("\n\nPosOrder ");
	mostraPosOrder(raiz);

	printf("\n\nPeso desta arvore =  %d", contaPeso(raiz));
	
	return 0;
}
