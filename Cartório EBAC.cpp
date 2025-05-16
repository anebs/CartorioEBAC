#include <stdio.h> //comunic com usuário
#include <stdlib.h> //aloca espaço na memoria
#include <locale.h> //texto por região
#include <string.h> // biblioteca responsavel pelas strings

int registro() //função para cadastro de usuarios
{
	//variaveis
	char arquivo [40];
	char cpf [40]; // será a chave primária
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	printf ("Digite o CPF para cadastro: "); //pegando info do usuario
	scanf("%s", cpf); //%s o s é de string
	
	strcpy(arquivo, cpf);//é uma função que copia os valores das strings , vai puxar do cpf para o arquivo; strcpy é c, std::string é c++
	
	FILE *file; // criando arquivo, 
	file = fopen(arquivo, "w"); //abre o arquivo 'w' é de write
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
	setlocale(LC_ALL, "Portuguese"); //tem que colocar nessa função tbm para reconhecer as acentuações
	
	char cpf [40]; //esta numa função a parte, o sistema não sabe do arquivo cpf, entao tem que criar novamente o arq cpf
	char conteudo[200];
	
	printf("Digite o CPF para consulta: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // read para ler o arquivo cpf
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//enqt tiver conteudo no arquivo, vai armazenando dentro da variavel conteudo
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}
int excluir()
{
	setlocale(LC_ALL, "Portuguese"); //tem que colocar nessa função tbm para reconhecer as acentuações
	
	char cpf [40]; //tem que colocar aqui novamente pq é outra funçao
	
	printf("Digite o CPF a ser excluído: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não está cadastrado: \n");
		system("pause");
	}

}
	
int main()
{
	int opcao=0;
	int x=1;
	
	for(x=1; x=1;) //queremos q o laço comece em 1 e continue enquanto for 1, não precisa de incremento ++
	{
		system("cls");
	
		setlocale(LC_ALL, "Portuguese");
	
		printf("### Cartório EBAC ###\n\n");
		printf("Escolha a opção desejada \n\n");
		printf("\t1 - Registro de nomes\n");
		printf("\t2 - Consulta de nomes\n");
		printf("\t3 - Exclusão de nomes\n\n");	
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");
		
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
			printf("Opcão inválida, tente novamente!\n");
			system("pause");
			break;
				
		
		}
	}

}

