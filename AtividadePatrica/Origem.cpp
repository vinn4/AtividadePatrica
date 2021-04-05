/*Declaração das Bibliotecas usadas. */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>
#include <string.h>
/*Funções da Playlsit*/
int MenuPlaylist();
void Inserir_Inicio();
void Inserir_Meio(int pos);
void Inserir_Fim();
void Mostrar_Playlist();
/*Declaração da struct (LISTA) para armazenar os dados e ponteiros para apontar para o proximo.*/
struct Playlist 
{
	char music[30], artist[20], temp[10];	
	struct Playlist *prox;
} *Head;

/*Programa Principal*/
int main()  
{
	setlocale(LC_ALL, "portuguese"); //Utilização de  acentuação.
	
	int play, c, pos;          // Declaração das variaveis que irei usar dentro do Switch.

	Head = NULL; //Inicio o Head como nulo  dentro da Main.
	
	while (1)       //Laço de repetição até que o usuário escolhar sair.

	{
		play = MenuPlaylist();      //Chamada da função para ixibir o Menu.
		switch (play)          
		{
		case 1:
			Mostrar_Playlist();      //Função que mostra as musicas listadas.
			
			break;
			

		case 2:
			Inserir_Inicio();     //Função para armazenar as musicas no inicio da Playlist.
			
			break;

		case 3:
			printf("Digite a posição que deseja: \n");      //Opção para colocar a musica em certa posição.
			scanf_s("%d", &pos);
			while ((c = getchar()) != '\n' && c != EOF) {}    //Limpeza de buffer.
			Inserir_Meio(pos);                      // Chamada da função para por no Meio.
			break;


		case 4:
			Inserir_Fim();         //Função para por  a musica no fim da Playlist.
				break;

		case 5:
			printf("SAINDO EM 3...\n");
			Sleep(300);                    //Contador para encerrar o programa.
			printf("SAINDO EM 2...\n");
			Sleep(300);
			printf("SAINDO EM 1...\n");
			return 0;             //Finaliza o programa.

		default:
			break;
		}
	}

	return 0;
}

/*Menu com as opções a serem escolhidas pelo usuário.*/
int MenuPlaylist()            
{
	int c, es;
	system("cls");
	printf("--------------------------------------- \n");
	printf("-------------- PLAYLIST --------------- \n");
	printf("--------------------------------------- \n");
	printf("-- 1 - MOSTRAR PLAYLIST .           --- \n");      
	printf("-- 2 - INSERIR NO INICIO DA PLAYLIST. - \n");
	printf("-- 3 - INSERIR NO MEIO DA PLAYLIST.   - \n");
	printf("-- 4 - INSERIR NO FIM DA PLAYLIST.    - \n");
	printf("-- 5 - SAIR.                          - \n");
	printf("--------------------------------------- \n");
	printf("--------------------------------------- \n");
	printf("-- ESCOLHA SUA OPÇÃO : \n");
	scanf_s("%d",&es);
	while ((c = getchar()) != '\n' && c != EOF) {}
	system("Cls");      //Limpa a tela.
	return es;
}
/*Função para inserir a musica no inicio*/

void Inserir_Inicio() 
{
	int c;
	Playlist* NovoElemento;
	NovoElemento = (struct Playlist*)malloc(sizeof(struct Playlist));     //Libera espaço na memoria.

	printf("Nome da musica escolhida: \n");
	gets_s(NovoElemento->music);                //Aponta e armazena a musica dentro da Playlist.
		printf("Nome do artista da musica: \n");
	gets_s(NovoElemento->artist);              //Aponta e armazena o Artista dentro da Playlist.
	printf("qual duração da faixa: \n");
	gets_s(NovoElemento->temp);          //Aponta e armazena a duração.
	system("cls");	               
	if (Head == NULL)                 //testa se o Head é nulo . 
	{
		Head = NovoElemento;        //Adiciona NovoElemento no Head.
		Head->prox = NULL;        // faz o Head apontar para o proximo fazendo ser nulo.

	}
	else
	{
		NovoElemento->prox = Head; //Caso seja falso, Head recebe o NovoElemento apontado para o proximo.
		Head = NovoElemento;         //Head recebe NovoElemento.
	}
}
/*Função para mostrar a Playlist.*/

void Mostrar_Playlist()
{
	Playlist* ElementoVarredura;
	ElementoVarredura = (struct Playlist*)malloc(sizeof(struct Playlist));   //Libera espaço na memoria.

	ElementoVarredura = Head;
	if (Head == NULL)               //testa se o Head é nulo.
	{
		printf(" Playlist Vazia! \n");     //Imprime com um certo tempo que a playlist está vazia
		Sleep(2000);
		return;        //Retorna par ao Menu.
	}
	while (ElementoVarredura != NULL)         //Enquanto o elemento for diferente de nulo ele imprime a Playlist.

	{
		printf("Musica: %s \t", ElementoVarredura->music);
		printf("Artista: %s \t", ElementoVarredura->artist);
		printf("Duração: %s \t", ElementoVarredura->temp);
		printf("\n");
		ElementoVarredura = ElementoVarredura->prox;
	}
	printf("\n");
	system("pause");
	return;
}
/*Função para por no meio da Playlist.*/

void Inserir_Meio(int pos)
/*Declaramos 3 elementos sendo um Auxliar para fazermos a comparação.*/
{
	int c;
	Playlist* NovoElemento;
	NovoElemento = (struct Playlist*)malloc(sizeof(struct Playlist));
	Playlist* ElementoVarredura;
	ElementoVarredura = (struct Playlist*)malloc(sizeof(struct Playlist));
	Playlist* ElementoAuxiliar;
	ElementoAuxiliar = (struct Playlist*)malloc(sizeof(struct Playlist));

	printf("Nome da musica escolhida: \n");
	gets_s(NovoElemento->music);
	printf("Nome do artista da musica: \n");
	gets_s(NovoElemento->artist);
	printf("qual duração da faixa: \n");
	gets_s(NovoElemento->temp);
		system("cls");

	if (pos == 0) //Testamos a posição recebida.
	{
		Head = NovoElemento; //Se for 0 adicionamos no Head.
		Head->prox = NULL;
	}
	/*Adicionamos no Meio d Playlist.*/
	else
	{
		/*Testamos até encontrarmos a posição e adicionamos o Elemento nela.*/
		ElementoVarredura = Head;
		for (int i = 0; i < pos - 1; i++)              
		ElementoVarredura = ElementoVarredura->prox;		
		ElementoAuxiliar = ElementoVarredura->prox; 
		ElementoVarredura->prox = NovoElemento;
		NovoElemento->prox = ElementoAuxiliar;
	}
}
/*Função para adicinar no fim da lista.*/

void Inserir_Fim()
{
	int c;
	Playlist* NovoElemento;
	NovoElemento = (struct Playlist*)malloc(sizeof(struct Playlist));
	Playlist* ElementoVarredura;
	ElementoVarredura = (struct Playlist*)malloc(sizeof(struct Playlist));
	Playlist* ElementoAuxiliar;
	printf("Nome da musica escolhida: \n");
	gets_s(NovoElemento->music);
	
	printf("Nome do artista da musica: \n");
	gets_s(NovoElemento->artist);

	printf("qual duração da faixa: \n");
	gets_s(NovoElemento->temp);
	system("cls");

	if (Head == NULL)         //Testamos se Head está nulo.
	{
		Head = NovoElemento;     //Adicionar elemento no Head caso esteja nulo.
		Head->prox = NULL;
	}
	else          
	{
		ElementoVarredura = Head;
		while (ElementoVarredura->prox != NULL)          //Testamos o Elemento do proximo.
			ElementoVarredura = ElementoVarredura->prox; //Passamos para o proximo Elemento da varredura.

		ElementoVarredura->prox = NovoElemento;              //Adicionamos no final.
		NovoElemento->prox = NULL;       
	}
}
