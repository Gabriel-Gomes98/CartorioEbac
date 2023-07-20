#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocações de texto por região
#include <string.h> // Biblioteca responsável por cuidar das strings 

int registrar() // Função para registrar o usuário no sistema
{
	// Criando variáveis para registrar usuário
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informação do usuário
	scanf("%s", cpf); // Armazenado a resposta na variável cpf
	
	strcpy(arquivo, cpf); // Copiando o valor de cpf na variável arquivo
	
	// Criando o arquivo 
	FILE *file;	
	file = fopen(arquivo, "w"); // Abrindo o arquivo para escrever os valores 
	fprintf(file, cpf); // Salvando o valor de cpf em file 
	fclose(file); // Fechando o arquivo
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo para fazer uma atualização
	fprintf(file, ","); // Colocando uma vírgula como separador dos valores
	fclose(file); //Fechando o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); // Armazenado a resposta na variável nome
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo para fazer uma atualização
	fprintf(file, nome); // Salvando o valor de nome em file 
	fclose(file); // Fechando o arquivo
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo para fazer uma atualização
	fprintf(file, ","); // Colocando uma vírgula como separador dos valores
	fclose(file); // Fechando o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome); // Armazenando a resposta na variável sobrenome
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo para fazer uma atualização
	fprintf(file, sobrenome); // Salvando o valor de sobrenome em file 
	fclose(file); // Fechando o arquivo
	
	file = fopen(arquivo, "a"); // Abrindo o arquivo para fazer uma atualização
	fprintf(file, ","); // Colocando uma vírgula como separador dos valores
	fclose(file); // Fechando o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // Coletando informação do usuário
	scanf("%s", cargo); // Armazenando a resposta na variável cargo
	
	file = fopen(arquivo, "a");  // Abrindo o arquivo para fazer uma atualização
	fprintf(file, cargo); // Salvando o valor de cargo em file 
	fclose(file); // Fechando o arquivo

	system("pause");	
}

int consultar() // Função para consultar o usuário no sistema
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a localidade do texto para português
	
	// Criando Variáveis
	char cpf[40]; 
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); // // Coletando informação do usuário
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); 
	
	// Colocando condições
	if(file == NULL)
	{
		printf("CPF não localizado.\n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}
 
 int deletar()
 {
	setlocale(LC_ALL, "Portuguese"); // Definindo a localidade do texto para português
	
	// Criando variável
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); // Deletando CPF escolhido	
	
	// Condição
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema.\n");
		system("pause");
	}
 }
 
// Função principal
int main()
{
	int opcao = 0; // Definindo variável para escolha do menu
	int laco = 1; // Definindo variável para o laço de repetição
	
	for (laco = 1; laco = 1;) // Laço de repetição para voltar no menu
	{
	
		system("cls"); //Limpando a tela de escolha 
		
		setlocale(LC_ALL, "Portuguese"); // Definindo a localidade do texto para português   
	
		// Menu
		printf("-+-+-+- Cartório da EBAC -+-+-+- \n\n");
		printf("Escolha uma das opções do menu: \n\n");
		printf("1 - Registrar nome \n");
		printf("2 - Consultar nome \n");
		printf("3 - Deletar nome \n");
		printf("4 - Sair do sistema \n\n");
		printf("Opção: ");
	
		scanf("%d", &opcao); // Armazenando valor na variável
	
		system("cls"); //Limpando a tela do menu 
	
		// Avaliando condições
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
				printf("Opçâo inválida!\n");
				system("pause");
			break;	
		}
	}
}
