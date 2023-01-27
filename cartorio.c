#include <stdio.h>        							// biblioteca de comunica��o com o usu�rio
#include <stdlib.h>      							// biblioteca de aloca��o de espa�os na mem�ria
#include <locale.h>									// biblioteca de aloca��o de texto por regi�o
#include <string.h>    								// biblioteca responsavel por cuidar das string



int registro()                                      //fun��o resposavel por cadastrar usuario no sistema 
{
	char arquivo	[40];                           // inicio cria��o de vari�veis / string
	char cpf		[40];
	char nome		[40];
	char sobrenome	[40];
	char cargo		[40];                           // final das variaveis 
	
	printf("Digite o CPF a ser cadastrado:  ");     //coletando informa��es do usu�rio
	scanf("%s", cpf);                               // %s refere-se as string
	
	strcpy(arquivo, cpf);                           //responsavel por copiar os valores das string
		
	FILE *file;       								// cria arquivo 
	file = fopen(arquivo, "w"); 					// cria arquivo e o W para escrever 
	fprintf(file,cpf);  							// salvo o valor da variavel 
	fclose(file); 									// fecha o arquivo

		
	file= fopen(arquivo, "a"); 						// cria o arquivo e A para atualizar
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:  ");	//coletaando informa��es do usu�rio
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:  ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);

	file= fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file, ". ");
	fclose(file);
	
	printf("\n PRONTO !!!\n\n   Usu�rio Cadastrado com Sucesso! \n\n");   		//mensagem para usu�rio
	system("pause");		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); 											// definindo a linguagem
	
	char cpf		[40];														//cria��o de vari�veis
	char conteudo	[200];
	
	printf("Digite o CPF a ser consultado:  ");
	scanf("%s",cpf);
	
	FILE *file;
	file= fopen(cpf, "r");
	fclose(file);
		
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}

	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); 										// definindo a linguagem
	
	char cpf[40];															// cria��o de variavel
	
	printf("Digite o CPF do usu�rio a ser deletado:  ");
	scanf("%s", cpf);
	
	remove(cpf); 															// fun��o remover cpf cadastrado 
	{
		printf("Cadastro deletado com Sucesso!\n");               			//mensagem de retorno da solicita��o
		system("pause");
	}
	
	FILE * file;
	file = fopen(cpf, "r"); 												//fun��o de leitura do arquivo
	fclose(file);
	
	if(file== NULL) 														// condi��o if para comparar
	{
		printf("Us�rio n�o cadastrado no Sistema!\n");
		system("pause");
  	}

}

int main()
{
	int opcao=0; 															//definido variaveis 
	int laco=1;
	char senhadigitada[10]= "a";
	int comparacao;
		
	printf("### CART�RIO DA EBAC ####\n");
	printf("Login de Administrador: \n\nDigite sua Senha:\n");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "123");
	
	if(comparacao == 0)
	{
		system("cls");
		for(laco=1;laco=1;)
		{
			system("cls"); 														// cls resposavel por limpar a tela 
	
			setlocale(LC_ALL, "Portuguese"); 									// definindo a linguagem 
			printf("### CART�RIO DA EBAC ####\n");
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Incluir novo(os) aluno(os)\n");
			printf("\t2 - Consultar aluno(os)\n");
			printf("\t3 - Deletar aluno(os)\n");
			printf("\t4 - Sair do Sistema \n");  
			printf("Opcao:  ");
	
			scanf("%d", &opcao); 												// armazenando a escolha do usu�rio
	
			system("cls");
		
			switch(opcao)
			{
				case 1:
				registro(); 													// chamada de fun��es
				break; 															// quebra
					
				case 2:
				consulta();			
				break;
			
				case 3:
				deletar();		
				break;
			
				case 4:
				printf("Obrigado por utilizar o Sistema!\n\n");
				return 0;
				break;
			
				default:
				printf("\n\nEssa op��o n�o est� dispon�vel!\n\n");
				system("pause");
				break;	
			}	 																//fim da sess�o
		}
	}	
	else
		printf("SENHA INCORRETA!\n");
}		
