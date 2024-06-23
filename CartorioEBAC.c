#include <stdio.h>  //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o de memoria 
#include <locale.h> //bibliotecas de aloca��es de text por regi�o
#include <string.h> //biblioteca responsavel por cuida das strings 


int registro() //Fun��o responsavel por cadastrar o usuario
{
	
	int opcao=2;//variavel escolha de saida
	
	system("cls");
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
  // inicio das variaveis strings
  char arquivo[40];
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];
  // final das variaveis strings
  printf("Digite o CPF a ser cadastrado: ");
  scanf("%s", cpf);// "%s" referece a strings
  
  strcpy(arquivo,cpf); // responsavel por copiar os valores das strings
  
  FILE *file; //cria o arquivo
  file = fopen(arquivo, "w"); //"w" quando for novo arquivo
  fprintf(file,cpf); // salvo o valor
  fclose(file); // fecha o arquivo
  
  file = fopen (arquivo, "a"); //"a" quando copiar arquivo
  fprintf(file,",");
  fclose(file);
  
  printf("Digite o nome a ser cadastrado: ");
  scanf("%s",nome);
  
  file = fopen(arquivo, "a");
  fprintf(file,nome);
  fclose(file);
  
  file = fopen (arquivo, "a");
  fprintf(file,",");
  fclose(file);
  
  printf("Digite o sobrenome a ser cadastrado: ");
  scanf("%s",sobrenome);
  
  file = fopen(arquivo, "a");
  fprintf(file,sobrenome);
  fclose(file);
  
  file = fopen (arquivo, "a");
  fprintf(file,",");
  fclose(file);
  
  printf("Digite o cargo a ser cadastrado: ");
  scanf("%s",cargo);
  
  file = fopen (arquivo, "a");
  fprintf(file,cargo);
  fclose(file);
  
  system("cls");
  
  //inicio da escolha de saida
  printf("Deseja registrar mais nomes?\n");
  printf("\t 1-Sim!\n");
  printf("\t 2-N�o!\n");
  printf("Opc�o:");
  
  
  scanf("%d",&opcao);

  switch(opcao)
  {
  	case 1:
  	registro();	
  	break;
  	
  	case 2:
  	main();	
  	break;
  
  }//fim da escolha de saida

}

int consulta()
{
  setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
  
  int opcao=3;//variavel escolha de saida
  
  system("cls");
  
  char cpf[40];
  char conteudo[200];
  
  printf("Digite o CPF a ser consultado: ");
  scanf("%s", cpf);
  
  FILE *file;
  file = fopen(cpf, "r");
  
  if(file == NULL)
  {
  	printf("N�o foi possivel encontrar o arquivo, n�o localizado! \n");
  	
  }
  
  while(fgets(conteudo, 200, file) != NULL)
  {
  	printf("\nEssas s�o as informa��es do usuario: ");
  	printf("%s", conteudo);
  	printf("\n\n");
  	
  	
  }
  
  system("pause");
  system("cls");
  
  printf("Deseja consulta outro nome?\n");//inicio da escolha de saida
  printf("\t1 - Sim!\n");
  printf("\t2 - N�o!\n");
  printf("Op��o:");
  
  scanf("%d",&opcao);
  
  switch(opcao)
  {
  	case 1:
  	consulta();
	break;
	
	case 2:
	main();	
  } //Fim da escolha de saida
  
  
}

int deletar()
{
  
  int opcao=4; //variavel escolha de saida
  
  system("cls");
  
  setlocale(LC_ALL, "Portuguese");
  
  char cpf[40];
  
  printf("Digite o CPF do usu�rio a ser deletado:");
  scanf("%s",cpf);
  
  remove(cpf);
  
  FILE *file;
  file = fopen(cpf, "r");
  
  if(file== NULL)
  {
  	printf("Usu�rio n�o se encontra no sistema!. \n");
  	system("pause");
  }
  
  system("cls");
  
  printf("Deseja deletar mais nomes?\n");//inicio da escolha de saida
  printf("\t1 - Sim!\n");
  printf("\t2 - N�o!\n");
  printf("Op��o:");
  
  scanf("%d",&opcao);
  
  switch (opcao)
  {
    case 1:
    deletar();
	break;
	
	case 2:
	main();
	break;	
  }// fim da escolha de saida
  
}


int main()
{	
	int opcao=0; //Definindo as variaveis
    int laco=1;
    
    for(laco=1;laco=1;) //loop
    { //inico do loop
    
	   system("cls");
	
	
	  setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	
	  printf("### Cart�rio EBAC ###\n\n"); //inicio do menu
	  printf("Escolha a op��o desejada do menu: \n\n");	printf("\t1 - Registrar Nomes\n");
	  printf("\t2 - Consulta Nomes\n");
	  printf("\t3 - Deletar Nomes\n");
	  printf("\t4 - Sair do Sistema\n");
	  printf("Op��o:"); //fim do menu
    
      scanf("%d", &opcao); //armazenando a escolha do usuario
    
      system("cls"); //limpa tela come�a uma nova
    
      switch(opcao)
      { //inicio sele��o menu
      	case 1: 
      	registro();
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n");
		return 0;
		break;
		
		default:
	    printf("Esta opcao nao esta disponivel!\n");
   	    system("pause");
	    break;
	  } // fim sele��o menu
    
    
    }  //fim do loop

    } 

   
