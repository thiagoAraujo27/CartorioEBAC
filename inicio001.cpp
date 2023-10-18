#include <stdio.h>  //biblioteca de comunicação com o usuario 
#include <stdlib.h>  // bliblioteca pra alocação de memoria
#include <locale.h>  // biblioteca de alocação de texto por região 
#include <string.h>  // biblioteca respondavel por caudar das string


int registro() // função responsavel por cadastrar os usuarios.
{
	// inicio criação de variaveis/string
	char arquivo[50];
	char cpf[50];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf);  //%s referice a string
	
	strcpy(arquivo, cpf);  // responsavel por copiar os valores das string

	FILE * file;  // cria o arquivo 
	file = fopen(arquivo,"w");  // cria o arquivo e o "w" é de escrever
	
	fprintf(file, cpf); // salva o valor da variavel
	fclose(file);  // fecha o arquivo
	
	file=fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf(" Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file=fopen(arquivo,"a");
	fprintf(file, nome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser consultado: ");
	scanf("%s", sobrenome);
	
	file=fopen(arquivo,"a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite qual seu cargo: ");
	scanf("%s", cargo);
	
	file=fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	system("pause");


}
int consultar()
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[50];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	printf("\n\n");
	
	FILE *file;
	
	file= fopen(cpf,"r" );
	
	if (file== NULL)
	{
		printf(" Não foi possivel abrir o arquivo \n ");
	
	}
	while(fgets(conteudo,200, file) != NULL)
	{
		printf("\n Essas são as informaçoes do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause"); // final do programa 
}
int deletar()
{  // inicio do programa 
	char cpf[50];
	
	printf("Digite qual cpf deseja deletar: \n");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file= fopen(cpf, "r");
	
	if(file == NULL);
	{
	printf(" Usuario deletado do sistema!. \n");
	system("pause");// fim do programa 
	}
}

int main() 
{  // inicio do programa 
	int opcao=0; // Definindo variaveis
	int laco=1;
	char senhadigitada[10]="a";
	
	printf("### Cartio da EBAC ### \n\n ");
	printf("Login, de administrador! \n\n Digite a senha: ");
	scanf("%s", senhadigitada);
	
	if(senhadigitada[10] == "1234")
	{
		for (laco=1;laco=1;)
		{

			system ("cls");// por limpar a tela 
	
			setlocale(LC_ALL, "Portuguese");  // inicio do menu
	
			printf("cartorio da ebac\n\n");
			printf("Escolha a opção desejada no menu \n\n ");
			printf("\t 1 Registrar nomes \n");
			printf("\t 2 Consultar nomes \n");
			printf("\t 3 Deletar nome \n\n");  // fim do menu
			printf("\t 4 Sair do sistema \n\n");
			printf("Opção: ");
			scanf("%d", &opcao);
		
		switch (opcao)
		{
			case 1:
			registro(); // chamada de funções
			break;
		
			case 2:
			consultar();
			break;
		
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema.\n");
			return 0;
			break;
		
		
			default:
			printf("Essa opção não está disponivel \n"); // fim da seleção	
			system ("pause");
			break;
		
				}
			}
		}
		else
		printf("senha incorreta \n");
	}




