#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // Biblioteca de aloca��es de texto por regi�o
#include <string.h> // Biblioteca respons�vel por cuidar das strings 

int registrar() // Fun��o para registrar o usu�rio no sistema
{
	// Criando vari�veis para registrar usu�rio
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informa��o do usu�rio
	scanf("%s", cpf); // Armazenado a resposta na vari�vel cpf
	
	strcpy(arquivo, cpf); // Copiando o valor de cpf na vari�vel arquivo
	
	// Criando o arquivo 
	FILE *file;	
	file = fopen(arquivo, "w"); // Abrindo o arquivo para escrever os valores 
	fprintf(file, cpf); // Salvando o valor de cpf em file 
	fclose(file); // Fechando o arquivo
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo para fazer uma atualiza��o
	fprintf(file, ","); // Colocando uma v�rgula como separador dos valores
	fclose(file); //Fechando o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); // Armazenado a resposta na vari�vel nome
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo para fazer uma atualiza��o
	fprintf(file, nome); // Salvando o valor de nome em file 
	fclose(file); // Fechando o arquivo
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo para fazer uma atualiza��o
	fprintf(file, ","); // Colocando uma v�rgula como separador dos valores
	fclose(file); // Fechando o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome); // Armazenando a resposta na vari�vel sobrenome
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo para fazer uma atualiza��o
	fprintf(file, sobrenome); // Salvando o valor de sobrenome em file 
	fclose(file); // Fechando o arquivo
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo para fazer uma atualiza��o
	fprintf(file, ","); // Colocando uma v�rgula como separador dos valores
	fclose(file); // Fechando o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // Coletando informa��o do usu�rio
	scanf("%s", cargo); // Armazenando a resposta na vari�vel cargo
	
	file = fopen(arquivo, "a");  // Abrindo o arquivo para fazer uma atualiza��o
	fprintf(file, cargo); // Salvando o valor de cargo em file 
	fclose(file); // Fechando o arquivo

	system("pause");	
}

int consultar() // Fun��o para consultar o usu�rio no sistema
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a localidade do texto para portugu�s
	
	// Criando Vari�veis
	char cpf[40]; 
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); // // Coletando informa��o do usu�rio
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); 
	
	// Colocando condi��es
	if(file == NULL)
	{
		printf("CPF n�o localizado.\n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}
 
 int deletar()
 {
	setlocale(LC_ALL, "Portuguese"); // Definindo a localidade do texto para portugu�s
	
	// Criando vari�vel
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); // Deletando CPF escolhido	
	
	// Condi��o
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema.\n");
		system("pause");
	}
 }
 
// Fun��o principal
int main()
{
	int opcao = 0; // Definindo vari�vel para escolha do menu
	int laco = 1; // Definindo vari�vel para o la�o de repeti��o
	
	for (laco = 1; laco = 1;) // La�o de repeti��o para voltar no menu
	{
	
		system("cls"); //Limpando a tela de escolha 
		
		setlocale(LC_ALL, "Portuguese"); // Definindo a localidade do texto para portugu�s   
	
		// Menu
		printf("-+-+-+- Cart�rio da EBAC -+-+-+- \n\n");
		printf("Escolha uma das op��es do menu: \n\n");
		printf("1 - Registrar nome \n");
		printf("2 - Consultar nome \n");
		printf("3 - Deletar nome \n");
		printf("4 - Sair do sistema \n\n");
		printf("Op��o: ");
	
		scanf("%d", &opcao); // Armazenando valor na vari�vel
	
		system("cls"); //Limpando a tela do menu 
	
		// Avaliando condi��es
		switch(opcao)
		{
			case 1:
				registrar();
				break;
			
			case 2:
				consultar();
				break;
			
			case 3:
				deletar();
				break;
				
			case 4:
				printf("Obrigado por utlizar o sistema!");
				return 0;
				break;
				
			default:
				printf("Op��o inv�lida!\n");
				system("pause");
			break;	
		}
	}
}
