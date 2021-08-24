#include <stdio.h>
#include <string.h>
#include "header.h"

/*
---------------Funcao addMsg---------------
* Adiciona uma mensagem na base de dados e o seu indice num vetor de indices ordenado alfabeticamente, tal como guarda o numero de mensagens que cada utilizador enviou e o tamanho de cada mensagem em vetores auxiliares. ;) *
*/

void addMsg(Mens mensagens[], int ordemAlfabetica[], int lenmsgs[], int posatual, int nusermsg[]) {
    scanf("%d", &mensagens[posatual].userid);
    getchar();
    fgets(mensagens[posatual].msg, MAX_STR+2, stdin);
    
    lenmsgs[posatual] = strlen(mensagens[posatual].msg);
    
    mensagens[posatual].msg[lenmsgs[posatual]-1] = '\0';
    
    nusermsg[mensagens[posatual].userid]++;
    
    atualizaAlfabetica(mensagens, ordemAlfabetica, posatual);
}

/*
---------------Funcao atualizaAlfabetica---------------
* Insere o 'posatual' (indice da ultima mensagem introduzida) na posicao correta do vetor dos indices das mensagens ordenado alfabeticamente. *
*/

void atualizaAlfabetica(Mens mensagens[], int ordemAlfabetica[], int posatual) {
	int i, posalfa=posatual;
	
   	if (!((posatual == 0) || (!msgcmp(mensagens[posatual], mensagens[ordemAlfabetica[posatual-1]]))))
    	for (i=0; i<posatual; i++)
        	if (msgcmp(mensagens[posatual], mensagens[ordemAlfabetica[i]])) {
		    	posalfa = i;
		    	break;
		   	}
    
    for (i=posatual-1; i>=posalfa; i--)
        ordemAlfabetica[i+1] = ordemAlfabetica[i];
    ordemAlfabetica[posalfa] = posatual;
}

/*
---------------Funcao msgcmp---------------
* Compara as duas mensagens dadas alfabeticamente, admitindo que se tiverem a mesma string, mas um numero de utilizador inferior, a mensagem com o numero de utilizador inferior sera considerada menor. Retorna 'TRUE' cajo a msg1 seja considerada menor que a msg2 e 'FALSE' caso contrario. *
*/

int msgcmp(Mens msg1, Mens msg2) {
	int ncmp;
	
	ncmp = strcmp(msg1.msg, msg2.msg);
	if (ncmp < 0)
		return TRUE;
	else if (ncmp == 0)
		if (msg1.userid < msg2.userid)
			return TRUE;
	
	return FALSE;
}

/*
---------------Funcao listaMsgs---------------
* Lista todas as mensagens guardadas. *
*/

void listaMsgs(Mens mensagens[], int posatual) {
    int i;
    
    for (i=0; i<posatual; i++)
        printf("%d:%s\n", mensagens[i].userid, mensagens[i].msg);
}

/*
---------------Funcao listaMsgsUser---------------
* Lista todas as mensagens de um determinado utilizador. *
*/

void listaMsgsUser(Mens mensagens[], int posatual, int user) {
    int i;
    
    for (i=0; i<posatual; i++)
    	if (mensagens[i].userid == user)
        	printf("%s\n", mensagens[i].msg);
}

/*
---------------Funcao printMsgsLongas---------------
* Imprime a mensagem mais longa. Caso haja varias com o mesmo tamanho, imprime todas elas. *
*/

void printMsgsLongas(Mens mensagens[], int lenmsgs[], int posatual, int j) {
	int i;
	
	for (i=0; i<posatual; i++)
		if (lenmsgs[i] == lenmsgs[j])
			printf("*LONGEST SENTENCE:%d:%s\n", mensagens[i].userid, mensagens[i].msg);
}

/*
---------------Funcao iMaxElemento---------------
* Retorna o indice correspondente ao valor maximo do vetor dado. *
*/

int iMaxElemento(int v[], int tamanho) {
	int i, iMax=0;
	
	for (i=1; i<tamanho; i++)
		if (v[i] > v[iMax])
			iMax = i;
	
	return iMax;
}

/*
---------------Funcao printUserIguais---------------
* Imprime todos os elementos iguais ao elemento correspondente ao indice dado. *
*/

void printUserIguais(int nusermsg[], int tamanho, int iMax) {
	int i;
	
	for (i=0; i<tamanho; i++)
    	if (nusermsg[i] == nusermsg[iMax])
        	printf("*MOST ACTIVE USER:%d:%d\n", i, nusermsg[i]);
}

/*
---------------Funcao listaMsgsAlfa---------------
* Lista todas as mensagens guardadas pela ordem indicada no vetor ordemAlfabetica. *
*/

void listaMsgsAlfa(Mens mensagens[], int ordemAlfabetica[], int posatual) {
	int i;
	
	for (i=0; i<posatual; i++)
		printf("%d:%s\n", mensagens[ordemAlfabetica[i]].userid, mensagens[ordemAlfabetica[i]].msg);
}

/*
---------------Funcao nPalavra---------------
* Conta o numero de ocorrencias da palavra dada em todas as mensagens guardadas. *
*/

int nPalavra(Mens mensagens[], int lenmsgs[], int posatual, char palavra[]) {
	int i, l, lenpalavra, inicio=0, output=0;
	
	lenpalavra = strlen(palavra);
	
	for (i=0; i<posatual; i++) {
		for (l=0; l<=lenmsgs[i]; l++)
			if ((mensagens[i].msg[l] == ' ') ||
			(mensagens[i].msg[l] == '\0') ||
			(mensagens[i].msg[l] == '\n') ||
			(mensagens[i].msg[l] == '.') ||
			(mensagens[i].msg[l] == ',') ||
			(mensagens[i].msg[l] == ';') ||
			(mensagens[i].msg[l] == '\t')) {
				if (wordcmp(palavra, lenpalavra, mensagens[i].msg, inicio, l))
					output++;
				inicio = l+1;
			}
		inicio = 0;
	}
	
	return output;
}

/*
---------------Funcao wordcmp---------------
* Compara a palavra dada com a delimitacao (entre os indices 'start'(inclusive) e 'end'(nao inclusive)) da string dada e retorna 'TRUE' caso sejam iguais e 'FALSE' caso contrario. *
*/

int wordcmp(char word[], int lenword, char str[], int start, int end) {
	int i=0;
	
	if (lenword == (end-start)) {
		while (start < end)
			if (str[start++] != word[i++])
				return FALSE;
	} else
		return FALSE;
	
	return TRUE;
}
