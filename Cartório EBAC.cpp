#include <stdio.h> //comunic com usu�rio
#include <stdlib.h> //aloca espa�o na memoria
#include <locale.h> //texto por regi�o
#include <string.h> // biblioteca responsavel pelas strings

int registro() //fun��o para cadastro de usuarios
{
	//variaveis
	char arquivo [40];
	char cpf [40]; // ser� a chave prim�ria
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	printf ("Digite o CPF para cadastro: "); //pegando info do usuario
	scanf("%s", cpf); //%s o s � de string
	
	strcpy(arquivo, cpf);//� uma fun��o que copia os valores das strings , vai puxar do cpf para o arquivo; strcpy � c, std::string � c++
	
	FILE *file; // criando arquivo, 
	file = fopen(arquivo, "w"); //abre o arquivo 'w' � de write
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome para cadastro: ");
	scanf("%s",nome);
	
	
	file = fopen(arquivo, "a"); //atulizando
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome para cadastro: ");
	scanf("%s",sobrenome);
	
	file=fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo para cadastro: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
	
}
int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //tem que colocar nessa fun��o tbm para reconhecer as acentua��es
	
	char cpf [40]; //esta numa fun��o a parte, o sistema n�o sabe do arquivo cpf, entao tem que criar novamente o arq cpf
	char conteudo[200];
	
	printf("Digite o CPF para consulta: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // read para ler o arquivo cpf
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//enqt tiver conteudo no arquivo, vai armazenando dentro da variavel conteudo
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}
int excluir()
{
	setlocale(LC_ALL, "Portuguese"); //tem que colocar nessa fun��o tbm para reconhecer as acentua��es
	
	char cpf [40]; //tem que colocar aqui novamente pq � outra fun�ao
	
	printf("Digite o CPF a ser exclu�do: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o est� cadastrado: \n");
		system("pause");
	}

}
	
int main()
{
	int opcao=0;
	int x=1;
	
	for(x=1; x=1;) //queremos q o la�o comece em 1 e continue enquanto for 1, n�o precisa de incremento ++
	{
		system("cls");
	
		setlocale(LC_ALL, "Portuguese");
	
		printf("### Cart�rio EBAC ###\n\n");
		printf("Escolha a op��o desejada \n\n");
		printf("\t1 - Registro de nomes\n");
		printf("\t2 - Consulta de nomes\n");
		printf("\t3 - Exclus�o de nomes\n\n");	
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: ");
		
		scanf("%d", &opcao); //armazena na variavel opcao, o valor que o usuario digitar
		
		system("cls"); //limpar a tela, apagando as msgs digitadas
		
		switch(opcao)
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			excluir();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema");
			return 0;
			break;
				
			default:
			printf("Opc�o inv�lida, tente novamente!\n");
			system("pause");
			break;
				
		
		}
	}

}

