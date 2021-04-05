/*Bibliotecas adicionadas.*/
#include <stdio.h>  
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define tamanho 10
 /*Funções usadas*/
int menu(); 
int FuncaoHashing(int numeroRu); //função para criar codigo hash.
void iniciarTabela();  
void inserir();
void mostrarAlunos(); //mostrar alunos cadastrados


struct TabelaAlunos         // estrutura de dados pedidas no exercicio.
{
	char aluno[100], email[100];
	int numeroRu;

};
TabelaAlunos tabelaHash[tamanho];  // tabela hash.

TabelaAlunos cadastrandoAlunos()     // função que le e armazena os dados dos alunos.
{
	TabelaAlunos aluno;
	int c;
	printf("Qual o numero do RU: \n");
	scanf_s("%d", &aluno.numeroRu);
	while ((c = getchar()) != '\n' && c != EOF) {}
	printf("Digite o Nome: \n");
	gets_s(aluno.aluno);
	printf("Digite o E-mail.\n");
	gets_s(aluno.email);
	system("cls");
	return aluno;
 }

TabelaAlunos* buscarAluno(int numeroRu)      //função para buscar o aluno na tabela.
{
	int pos = FuncaoHashing(numeroRu);
	while (tabelaHash[pos].numeroRu != -1)
	{
		if (tabelaHash[pos].numeroRu == numeroRu)
		{
			return &tabelaHash[pos];

		}
		else {
			pos = FuncaoHashing(pos + 1);	
		}		
	}
	return NULL; 
}

int main() {

	setlocale(LC_ALL, "Portuguese"); //usar acentuação
	int opcao,numeroRu;
	TabelaAlunos* aluno;
	iniciarTabela();      // inicia tabela com indices.

	 
	while (1) {
		opcao = menu();        //menu de opção
		switch (opcao)
		{
		case 1:
			inserir();   // inserir aluno na tabela.
			break;

		case 2:
			printf("Qual o RU do aluno a ser buscado: \n");
			scanf_s("%d", &numeroRu);
			aluno = buscarAluno(numeroRu);       //busca aluno com o numero do RU.
			if (aluno)
			{
				printf("ALUNO ENCONTRADO: \n");
				printf("RU: %d \t", aluno->numeroRu);
				printf("Nome: %s \t", aluno->aluno);
				printf("E-mail: %s \t", aluno->email);
				printf("\n");
				system("pause");
			}
			else
			{
				printf("ERRO!! NENHUM ALUNO ENCONTRADO!! \n");
				system("pause");
			}
			break;

		case 3: 
			mostrarAlunos();   //mostra alunos cadastrados.

			break;
		case 4:
			return 0;     //sair.

		default:
			break;
		}
	}

	return 0;
}

int menu() {      //menu de opção.
	int opcao, c;
	system("Cls");
	printf("----------------------------------- \n");
	printf("----------------------------------- \n");
	printf("-------- LISTA DE ALUNOS ---------- \n");
	printf("--- 1. Inserir aluno:  ------------ \n");
	printf("--- 2. Buscar aluno pelo RU:  ----- \n");
	printf("--- 3. Mostrar todos os alunos.  -- \n");
	printf("--- 4. Sair   --------------------- \n");
	printf("----------------------------------- \n");
	printf("----------------------------------- \n");
	printf("--- ESCOLHA SUA OPÇÃO :  ---------- \n");
	scanf_s("%d", &opcao);
	while ((c = getchar()) != '\n' && c != EOF) {} //limpa buffer do teclado.
	system("Cls");
	return opcao;
}

int FuncaoHashing(int numeroRu)
{
	return (numeroRu % tamanho);   //retorna o resto da divisão.
}

void iniciarTabela()
{
	for (int i = 0; i < tamanho; i++)
	{
		tabelaHash[i].numeroRu = -1;     //preenche a tabela com -1.
	}
}
void inserir()
{
	TabelaAlunos inserido = cadastrandoAlunos();   //função para adicionar os alunos na tabela.
	int pos = FuncaoHashing(inserido.numeroRu);
	while (tabelaHash[pos].numeroRu != -1)
	{
		pos = FuncaoHashing(pos + 1);
	}
	tabelaHash[pos] = inserido;
}

void mostrarAlunos()  //função para mostrar alunos ja inseridos.
{
	printf(" ----- ALUNOS CADASTRADOS ----- \n");
	for (int i = 0; i < tamanho; i++)
	{
		if (tabelaHash[i].numeroRu != -1)
		{
			printf("RU: %d \t", tabelaHash[i].numeroRu);
			printf("Nome: %s \t", tabelaHash[i].aluno);
			printf("E-mail: %s \t", tabelaHash[i].email);
			printf("\n\n");
		}
	}
	printf("\n\n");
	system("pause");
}