#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>
#include <string.h>

int MenuPlaylist();
void Inserir_Inicio();
void Mostrar_Playlist();

struct Playlist 
{
	char music[30], artist[20];
	float temp;
	struct Playlist *prox;
} *Head;

int main() 
{
	setlocale(LC_ALL, "portuguese");
	
	int play , c;
	Head = NULL;
	
	while (1)

	{
		play = MenuPlaylist();
		switch (play)
		{
		case 1:
			Mostrar_Playlist();
			
			break;
			

		case 2:
			Inserir_Inicio();
			
			break;

		case 3:


		case 4:


		case 5:


		case 6:
			printf("SAINDO EM 3...\n");
			Sleep(300);
			printf("SAINDO EM 2...\n");
			Sleep(300);
			printf("SAINDO EM 1...\n");
			return 0;

		default:
			break;
		}
	}

	return 0;
}


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
	printf("-- 5 - REMOVER MUSICA DA PLAYLIST.    - \n");
	printf("-- 6 - SAIR.                          - \n");
	printf("--------------------------------------- \n");
	printf("--------------------------------------- \n");
	printf("-- ESCOLHA SUA OPÇÃO : \n");
	scanf_s("%d",&es);
	while ((c = getchar()) != '\n' && c != EOF) {}
	system("Cls");
	return es;
}

void Inserir_Inicio() 
{
	int c;
	Playlist* NovoElemento;
	NovoElemento = (struct Playlist*)malloc(sizeof(struct Playlist));
	printf("Nome da musica escolhida: \n");
	gets_s(NovoElemento->music);
		printf("Nome do artista da musica: \n");
	gets_s(NovoElemento->artist);
	printf("qual duração da faixa: \n");
	scanf_s("%f", &NovoElemento->temp);
	while ((c = getchar()) != '\n' && c != EOF) {}
	system("cls");	
	if (Head == NULL)
	{
		Head = NovoElemento;
		Head->prox = NULL;

	}
	else
	{
		NovoElemento->prox = Head;
		Head = NovoElemento;
	}
}
void Mostrar_Playlist()
{
	Playlist* ElementoVarredura;
	ElementoVarredura = (struct Playlist*)malloc(sizeof(struct Playlist));

	ElementoVarredura = Head;
	if (Head == NULL)
	{
		printf(" Playlist Vazia! \n");
		Sleep(2000);
		return;
	}
	while (ElementoVarredura != NULL)

	{
		printf("Musica: %s \n", ElementoVarredura->music);
		printf("Artista: %s \n", ElementoVarredura->artist);
		printf("Duração: %.2f \n", ElementoVarredura->temp);
		ElementoVarredura = ElementoVarredura->prox;
	}
	printf("\n\n");
	system("pause");
	return;
}