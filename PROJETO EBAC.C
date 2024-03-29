#include <stdio.h>//biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>//biblioteca de aloca��es de texto por regi�o
#include <string.h>//biblioteca respons�vel por cuidar das strings

int registro()//fun��o para registrar
{
 	char arquivo[40];
	char cpf[40];
 	char nome[40];
 	char sobrenome[40];
 	char cargo[40];
 	
 	printf("Digite o CPF a ser cadastrado: ");
 	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);// respons�vel por criar os valores das strings
	
	FILE *file;// Cria o arquivo
	file = fopen(arquivo, "w");// cria o arquivo - "w" cria o arquivo
	fprintf(file,cpf);// Salvo o valor da vari�vel
	fclose(file);// Fecho o arquivo
	
	file = fopen(arquivo, "a");// Abrir o arquivo- "a" atualiza o arquivo
	fprintf(file,",");// Salvo o valor da vari�vel
	fclose(file);// Fecho o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consulta()//fun��o para consultar
{
	setlocale(LC_ALL, "portuguese");//selecionar o idioma na biblioteca
	
	char cpf[40];
	char conteudo[200];
	char *token;
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");// Abrir o arquivo- "r" para ler o arquivo
		
	if(file == NULL)
	{
		printf("\nN�o foi possivel abrir o arquivo, n�o localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do us�ario: \n");
		
		token = strtok(conteudo, ",");//variavel utilizada para dividir a consulta
		printf("CPF: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("Nome: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("Sobrenome: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("Cargo: %s\n", token);
		
	}
	
	system("pause");
	
		
}

int deletar()//fun��o para deletar
{
	setlocale(LC_ALL, "portuguese");//selecionar o idioma na biblioteca
	
	char cpf[40];
	
	printf("Digite o CPF que deseja deletar: ");
	scanf("%s",cpf);	
	
	FILE *file;
	file = fopen(cpf, "r");
		
	if(file == NULL)
	{
		printf("\nO CPF digitado n�o se encontra no sistema!\n\n");
		system("pause");
	}	
		else
		{
			fclose(file);
			
			if(remove(cpf) == 0)
			{
				printf("\nO CPF digitado foi deletado com sucesso!\n\n");
				system("pause");
			}
		}
}

	
	


int main()
{
	int	opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)//repeti��o
	{
		
		setlocale(LC_ALL, "portuguese");//selecionar o idioma na biblioteca
	
	  	system("cls");//limpar tela
	
		printf("### CART�RIO DA EBAC ###\n\n");//titulo do programa
		printf("Escolha a op��o desejada no menu: \n\n");//dire��o para o usu�rio
		printf("\t1 - Registrar nomes\n");//escolha para o usu�rio
		printf("\t2 - Consultar nomes\n");//escolha para o usu�rio
		printf("\t3 - Deletar nomes\n");//escolha para o usu�rio
		printf("\t4 - Sair do sistema\n\n\n");
		
		printf("Op��o: ");//para ficar bonito

		scanf("%d", &opcao);//armazenar a op��o escolhinda na variavel
	
		system("cls");//limpar a tela
		
		switch(opcao)//inicio da sele��o
		{
			case 1://op��o
			registro();//chamando a fun��o
			break;//para encerar o case	
		
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar nosso sistema\n\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel\n");
			system("pause");
			break;
		}//fim da sele��o
		
	}
	
}

