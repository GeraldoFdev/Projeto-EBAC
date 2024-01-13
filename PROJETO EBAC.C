#include <stdio.h>//biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação de espaço em memória
#include <locale.h>//biblioteca de alocações de texto por região
#include <string.h>//biblioteca responsável por cuidar das strings

int registro()//função para registrar
{
 	char arquivo[40];
	char cpf[40];
 	char nome[40];
 	char sobrenome[40];
 	char cargo[40];
 	
 	printf("Digite o CPF a ser cadastrado: ");
 	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);// responsável por criar os valores das strings
	
	FILE *file;// Cria o arquivo
	file = fopen(arquivo, "w");// cria o arquivo - "w" cria o arquivo
	fprintf(file,cpf);// Salvo o valor da variável
	fclose(file);// Fecho o arquivo
	
	file = fopen(arquivo, "a");// Abrir o arquivo- "a" atualiza o arquivo
	fprintf(file,",");// Salvo o valor da variável
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

int consulta()//função para consultar
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
		printf("\nNão foi possivel abrir o arquivo, não localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usúario: \n");
		
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

int deletar()//função para deletar
{
	setlocale(LC_ALL, "portuguese");//selecionar o idioma na biblioteca
	
	char cpf[40];
	
	printf("Digite o CPF que deseja deletar: ");
	scanf("%s",cpf);	
	
	FILE *file;
	file = fopen(cpf, "r");
		
	if(file == NULL)
	{
		printf("\nO CPF digitado não se encontra no sistema!\n\n");
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
	
	for(laco=1;laco=1;)//repetição
	{
		
		setlocale(LC_ALL, "portuguese");//selecionar o idioma na biblioteca
	
	  	system("cls");//limpar tela
	
		printf("### CARTÓRIO DA EBAC ###\n\n");//titulo do programa
		printf("Escolha a opção desejada no menu: \n\n");//direção para o usuário
		printf("\t1 - Registrar nomes\n");//escolha para o usuário
		printf("\t2 - Consultar nomes\n");//escolha para o usuário
		printf("\t3 - Deletar nomes\n\n\n");//escolha para o usuário
	
		printf("Opção: ");//para ficar bonito

		scanf("%d", &opcao);//armazenar a opção escolhinda na variavel
	
		system("cls");//limpar a tela
		
		switch(opcao)//inicio da seleção
		{
			case 1://opção
			registro();//chamando a função
			break;//para encerar o case	
		
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponível\n");
			system("pause");
			break;
		}//fim da seleção
		
	}
	
}

