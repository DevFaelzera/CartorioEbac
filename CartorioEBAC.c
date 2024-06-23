#include <stdio.h>  //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocação de espaço de memoria 
#include <locale.h> //bibliotecas de alocações de text por região
#include <string.h> //biblioteca responsavel por cuida das strings 


int registro() //Função responsavel por cadastrar o usuario
{
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

  system("pause");//pausa a tela ate que o usuario queira
}

int consulta()
{
  setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
  
  char cpf[40];
  char conteudo[200];
  
  printf("Digite o CPF a ser consultado: ");
  scanf("%s", cpf);
  
  FILE *file;
  file = fopen(cpf, "r");
  
  if(file == NULL)
  {
  	printf("Não foi possivel encontrar o arquivo, não localizado! \n");
  	
  }
  
  while(fgets(conteudo, 200, file) != NULL)
  {
  	printf("\nEssas são as informações do usuario: ");
  	printf("%s", conteudo);
  	printf("\n\n");
  	
  	
  }
  
  system("pause");
  
  
}

int deletar()
{
  
  setlocale(LC_ALL, "Portuguese");
  
  char cpf[40];
  
  printf("Digite o CPF do usuário a ser deletado:");
  scanf("%s",cpf);
  
  remove(cpf);
  
  FILE *file;
  file = fopen(cpf, "r");
  
  if(file== NULL)
  {
  	printf("Usuário não se encontra no sistema!. \n");
  	system("pause");
  }
  
}


int main()
{	
	int opcao=0; //Definindo as variaveis
    int laco=1;
    
    for(laco=1;laco=1;) //loop
    { //inico do loop
    
	   system("cls");
	
	
	  setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	
	  printf("### Cartório EBAC ###\n\n"); //inicio do menu
	  printf("Escolha a opção desejada do menu: \n\n");	printf("\t1 - Registrar Nomes\n");
	  printf("\t2 - Consulta Nomes\n");
	  printf("\t3 - Deletar Nomes\n");
	  printf("Opção:"); //fim do menu
    
      scanf("%d", &opcao); //armazenando a escolha do usuario
    
      system("cls"); //limpa tela começa uma nova
    
      switch(opcao)
      { //inicio seleção menu
      	case 1: 
      	registro();
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		default:
	    printf("Esta opcao nao esta disponivel!\n");
   	    system("pause");
	    break;
	  } // fim seleção menu
    
    
    }  //fim do loop

    } 

   
