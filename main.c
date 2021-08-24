/*
---------------IAED Projeto 1 - Taguspark - Grupo 33---------------
87667 - Joao Andre de Franca Ferreira Galinho
87653 - Filipe Miguel Cerqueiro Henriques
*/

#include <stdio.h>
#include <string.h>
#include "header.h"

int main() {
    Mens mensagens[MAX_MSGS];
    int posatual=0, nusermsg[MAX_USER+1], ordemAlfabetica[MAX_MSGS], lenmsgs[MAX_MSGS], user, nOcorrencias;
    char c, palavra[MAX_STR+1];
    
    while (TRUE) {
        switch (c = getchar()) {
            case 'A':  				//Adiciona uma mensagem
            	getchar();
            	if (posatual < MAX_MSGS) {
                	addMsg(mensagens, ordemAlfabetica, lenmsgs, posatual, nusermsg);
                	posatual++;
                } else
                	printf("*OUT OF MEMORY");
                break;
            case 'L':				//Lista todas as mensagens por ordem de introducao
            	getchar();
            	printf("*TOTAL MESSAGES:%d\n", posatual);
                listaMsgs(mensagens, posatual);
                break;
            case 'U':				//Lista todas as mensagens enviadas por um dado utilizador
            	getchar();
            	scanf("%d", &user);
            	printf("*MESSAGES FROM USER:%d\n", user);
                listaMsgsUser(mensagens, posatual, user);
                getchar();
                break;
            case 'O':				//Imprime a(s) mensagem(ns) mais longa(s)
            	getchar();
                printMsgsLongas(mensagens, lenmsgs, posatual, iMaxElemento(lenmsgs, posatual));
                break;
            case 'T':				//Imprime o(s) numero(s) do(s) utilizador(es) mais ativo(s)
            	getchar();
                printUserIguais(nusermsg, MAX_USER+1, iMaxElemento(nusermsg, MAX_USER+1));
                break;
            case 'S':				//Lista todas as mensagens por ordem alfabetica
            	getchar();
            	printf("*SORTED MESSAGES:%d\n", posatual);
                listaMsgsAlfa(mensagens, ordemAlfabetica, posatual);
                break;
            case 'C':				//Conta o numero de ocorrencias de uma dada palavra em todas as mensagens
            	getchar();
            	scanf("%s", palavra);
                nOcorrencias = nPalavra(mensagens, lenmsgs, posatual, palavra);
                printf("*WORD %s:%d\n", palavra, nOcorrencias);
                getchar();
                break;
            case 'X':				//Termina o programa
            	getchar();
            	printf("%d\n", posatual);
                return 0;
            default:
            	getchar();
                break;
        }
    }
    
    return 0;
}
