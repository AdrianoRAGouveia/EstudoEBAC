#include <stdio.h>        							// biblioteca de comunicação com o usuário
#include <stdlib.h>      							// biblioteca de alocação de espaços na memória
#include <locale.h>									// biblioteca de alocação de texto por região
#include <string.h>    								// biblioteca responsavel por cuidar das string



int registro()                                      //função resposavel por cadastrar usuario no sistema 
{
	char arquivo	[40];                           // inicio criação de variáveis / string
	char cpf		[40];
	char nome		[40];
	char sobrenome	[40];
	char cargo		[40];                           // final das variaveis 
	
	printf("Digite o CPF a ser cadastrado:  ");     //coletando informações do usuário
	scanf("%s", cpf);                               // %s refere-se as string
	
	strcpy(arquivo, cpf);                           //responsavel por copiar os valores das string
		
	FILE *file;       								// cria arquivo 
	file = fopen(arquivo, "w"); 					// cria arquivo e o W para escrever 
	fprintf(file,cpf);  							// salvo o valor da variavel 
	fclose(file); 									// fecha o arquivo

		
	file= fopen(arquivo, "a"); 						// cria o arquivo e A para atualizar
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:  ");	//coletaando informações do usuário
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
	
	printf("\n PRONTO !!!\n\n   Usuário Cadastrado com Sucesso! \n\n");   		//mensagem para usuário
	system("pause");		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); 											// definindo a linguagem
	
	char cpf		[40];														//criação de variáveis
	char conteudo	[200];
	
	printf("Digite o CPF a ser consultado:  ");
	scanf("%s",cpf);
	
	FILE *file;
	file= fopen(cpf, "r");
	fclose(file);
		
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}

	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); 										// definindo a linguagem
	
	char cpf[40];															// criação de variavel
	
	printf("Digite o CPF do usuário a ser deletado:  ");
	scanf("%s", cpf);
	
	remove(cpf); 															// função remover cpf cadastrado 
	{
		printf("Cadastro deletado com Sucesso!\n");               			//mensagem de retorno da solicitação
		system("pause");
	}
	
	FILE * file;
	file = fopen(cpf, "r"); 												//função de leitura do arquivo
	fclose(file);
	
	if(file== NULL) 														// condição if para comparar
	{
		printf("Usário não cadastrado no Sistema!\n");
		system("pause");
  	}

}

int main()
{
	int opcao=0; 															//definido variaveis 
	int laco=1;
	char senhadigitada[10]= "a";
	int comparacao;
		
	printf("### CARTÓRIO DA EBAC ####\n");
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
			printf("### CARTÓRIO DA EBAC ####\n");
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Incluir novo(os) aluno(os)\n");
			printf("\t2 - Consultar aluno(os)\n");
			printf("\t3 - Deletar aluno(os)\n");
			printf("\t4 - Sair do Sistema \n");  
			printf("Opcao:  ");
	
			scanf("%d", &opcao); 												// armazenando a escolha do usuário
	
			system("cls");
		
			switch(opcao)
			{
				case 1:
				registro(); 													// chamada de funções
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
				printf("\n\nEssa opção não está disponível!\n\n");
				system("pause");
				break;	
			}	 																//fim da sessão
		}
	}	
	else
		printf("SENHA INCORRETA!\n");
}		
