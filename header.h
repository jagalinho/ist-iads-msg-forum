#define MAX_STR 140 		//Tamanho maximo de cada mensagem
#define MAX_MSGS 10000 		//Numero maximo de mensagens
#define MAX_USER 999 		//Numero de utilizador maximo
#define TRUE 1
#define FALSE 0

typedef struct {
    int userid;
    char msg[MAX_STR+2];
} Mens;

void addMsg(Mens mensagens[], int ordemAlfabetica[], int lenmsgs[], int posatual, int nusermsg[]);
void atualizaAlfabetica(Mens mensagens[], int ordemAlfabetica[], int posatual);
int msgcmp(Mens msg1, Mens msg2);
void listaMsgs(Mens mensagens[], int posatual);
void listaMsgsUser(Mens mensagens[], int posatual, int user);
void printMsgsLongas(Mens mensagens[], int lenmsgs[], int posatual, int j);
int iMaxElemento(int v[], int tamanho);
void printUserIguais(int nusermsg[], int tamanho, int iMax);
void listaMsgsAlfa(Mens mensagens[], int ordemAlfabetica[], int posatual);
int nPalavra(Mens mensagens[], int lenmsgs[], int posatual, char palavra[]);
int wordcmp(char word[], int lenword, char str[], int start, int end);
