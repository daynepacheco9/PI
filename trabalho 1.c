/* Biblitoecas */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/* --- Funcoes --- */
char** criarCinema    (int linhas, int colunas);
void liberarCinema    (char** matriz, int linhas);
int  BuscaFileira     (int poltrona, int colunas);
int  BuscaColuna      (int poltrona, int colunas);
void VenderPoltrona   (char **pmat, int colunas);
void imprimeOcupacao  (char **pmat, int m, int n);
void imprimePlateia   (char **pmat, int m, int n);

/* --- Codigo Principal --- */
int main(void) 
{
  /* Declaracoes das Linhas e Colunas da Matriz Cinema, juntamente com a opcao */
  int fileira = 14;
  int colunas = 10;
  char recebedor[255];
  int op;
  
  char **Cinema = criarCinema(fileira, colunas);
  
  Menu:
  system("cls");
  printf("\n---< Cinema Ciber >---\n\n"
         "0 - Sair\n"
         "1 - Vender ingresso\n" 
         "2 - Mostrar platéia\n" 
         "3 - Mostrar ocupação\n\n"
         "Qual sua opção\n> "
        );
  
  RecebeOperador:
  scanf("%s", recebedor);
  
  for (int i = 0; recebedor[i] != '\0'; i++){
    if (isalpha(recebedor[i]) != 0){
      getchar();
      printf("\nDigite Apenas Numeros de 0 até 3!!\n");
      goto RecebeOperador;
    }
  }
  
  op = atoi(recebedor);
  
  switch (op)
  {
    case 1:
    printf("\n--- Venda de Ingressos Cinema Ciber ---\n");
    imprimePlateia(Cinema, fileira, colunas);
    VenderPoltrona(Cinema, colunas);
    goto Menu;
    
    case 2:
    printf("--- Mostrar Plateia Cinema Ciber ---"); 
    imprimePlateia(Cinema, fileira, colunas);
    printf("Pressione ENTER para continuar\n");
    getchar();
    getchar();
    goto Menu;

    case 3:
    imprimeOcupacao(Cinema, fileira, colunas);
    printf("Pressione ENTER para continuar\n");
    getchar();
    getchar();
    goto Menu;

    case 0:
    liberarCinema(Cinema, fileira);
    printf("\nPrograma encerrado...");
    break;
    
    default:
    printf("Por favor, digite apenas opcoes entre 0 e 3\n");
    printf("Pressione ENTER para continuar\n");
    getchar();
    getchar();
    goto Menu;
  }
  
  return 0;
}
/* --- Fim Programa Principal */

/* --- Detalhes das Funcoes --- */
void encerra()
{
  printf("Memoria insuficiente!");
  exit(1);
}

// Função para criar uma matriz de caracteres
char** criarCinema(int linhas, int colunas) 
{
  /* Aloca espaco para as linhas */
  char** matriz = (char**) malloc(linhas * sizeof(char*));
  if (matriz == NULL) encerra();

  /* Aloca espaco para as colunas das linhas */
  for (int i = 0; i < linhas; i++) 
  {
    matriz[i] = (char*) malloc(colunas * sizeof(char));
    if (matriz[i] == NULL) encerra();

    for (int j = 0; j < colunas; j++)
      matriz[i][j] = '_';
  }

  return matriz;
}

// Função para liberar a memória alocada para a matriz de caracteres
void liberarCinema(char** matriz, int linhas)
{
  for (int i = 0; i < linhas; i++) 
    free(matriz[i]);
  
  free(matriz);
}

// Calcula a fileria
int BuscaFileira (int poltrona, int colunas)
{
  int inteiro = poltrona / colunas;
  return inteiro;
}

//Calcula a coluna 
int BuscaColuna (int poltrona, int colunas)
{
  int inteiro = poltrona % colunas;
  return inteiro - 1;
}

// Pega o numero de uma poltrona e verifica se esta ocupada, caso nao esteja, o usuario pode escolhere entre inteira ou meia
void VenderPoltrona (char **pmat, int colunas)
{
  char recebedorPoltrona[20];
  int poltrona;

  ScanPoltrona:
  printf("\nEscolha sua poltrona <1..140>\n> ");
  scanf("%s", recebedorPoltrona);

  for (int i = 0; recebedorPoltrona[i] != '\0'; i++){
    if (isalpha(recebedorPoltrona[i]) != 0 ){ 
    getchar();
    printf("\nDigite Apenas Numeros!!\n");
    goto ScanPoltrona;
    }
  }

  poltrona = atoi(recebedorPoltrona); 

  /* <---> Fim da Implementacao <---> */
  
  //verifica se a poltrona escolhida esta entre as opcoes validas
  while ((poltrona < 1) || (poltrona > 140))
  {
    printf("ERRO!\n");
    printf("Digite um valor entre 1 e 140\n> ");
    if (scanf("%d", &poltrona) != 1){ // verifica a saida do scanf, que caso nao seja %d (inteiro) da um erro
      getchar();
      printf("\nDigite Apenas Numeros!!");
      goto ScanPoltrona;
    } 
  }
  getchar(); // nao permite que a entrada \ni ou \nm aconteca
  int linha = BuscaFileira(poltrona, colunas);
  int coluna = BuscaColuna(poltrona, colunas);
  if (coluna == -1){
    coluna = colunas - 1;
    linha--;
  } 
  
  if (pmat[linha][coluna] != '_')
  {
    printf("\nPoltrona ja ocupada, tente outra!\n");
    goto ScanPoltrona;
  }
  char entrada[20];

  /* <---> implementar a validacao do char <---> */
  
  //verifica se o tipo de entrada escolhido esta entre as opcoes validas
  while (1)
  {
    printf("\nQual o tipo, <m>eia ou <i>nteira\n> ");
    scanf("%s", entrada); getchar();
    entrada[0] = tolower(entrada[0]);

    if (entrada[1] != '\0'){
      printf("\nOpção inválida!\n");
      continue;
    }

    if (entrada[0] == 'm')
      break;
    else if (entrada[0] == 'i')
      break;
    else
      printf("ERRO!\n");
  }

  /* <---> FIM da implementacao da validacao de char <---> */
  
  
  pmat[linha][coluna] = entrada[0]; // atribui a poltrona meia ou inteira
}

// Mostra a ocupacao da matriz, em meias ou inteiras
void imprimeOcupacao(char **pmat, int m, int n)
{
  int i, j;
  
  printf("\n --> Relatorio de Ocupacao <-- \n\n");
  
  for (i=0;i<m;i++)
  {
    if (i == 0) printf("│");
    if (0 < i && i < m - 1) printf("│"); 
    if (i == m - 1) printf("│"); 
    
    for (j = 0; j < n; j++) 
      printf(" %1c ", pmat[i][j]);
    
    if (i == 0) printf("│"); 
    if (0 < i && i < m - 1) printf("│"); 
    if (i == m - 1) printf("│"); 
    
    printf("\n");
  }
  printf("\n");
  
} 

// mostra o numero das poltronas disponiveis
void imprimePlateia (char **pmat, int m, int n){
  
  int i, j, 
  count = 1;
  
  printf("\n *** Plateia *** \n\n");
  
  for(i = 0; i < m; i++)
  {
    /* Caso a ocupacao ainda seja '_' imprime o numero da poltrona, caso contrario imprime espaco vazio */
    for (j = 0; j < n; j++)
    {
      
    if (j == 0) printf("│");      
      
    if (pmat[i][j] == '_')
      printf(" %3d ", count);
    else
      printf("     ");
    
    count++;
    if (j == m - 5) printf("│");
    
    }  
    printf("\n");
  }
  printf("\n");
  
}
