#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
#include <locale.h>
#include <time.h>
#include "bibliotecabodega.h"

int main (){
  setlocale(LC_ALL, "Portuguese");
  /* clienteTree h; */ 
  DrinkTree t;
  initTree(&t);
  /* initTree(&h); */
  int opcao = 0;

  while(opcao != 9){ 
    mostraMenu();
    scanf("%d", &opcao);
      
    switch(opcao){ //switch do menu
      case 1:
        cadastrarBebida(&t);
        break;   
      case 2:
        printf("\n  BEBIDAS CADASTRADAS \n\n");
        imprimeTree(t.raiz);    //imprime as bebidas cadastradas na arvore
        break;  
      case 3:
        comprarBebida(t.raiz);  //menu para comprar as bebidas para a bodega
        break;      
      case 4:
        venderBebida(t.raiz); //vender bebidas para os clientes que no caso não existem pq eu não consegui fazer o castrado (não time tempo, no caso, se tivesse mais alguns meses de semestre eu claramente conseguiria kkkkkkkkkkk)
        break;                //vamos imaginar que eles mostram a identidade ao comprar e o caixa ve a data de nascimento
    /*case 5:
        cadastrarCliente(&h);
        break;  */
    /*case 6:
        printf("\n  CLIENTES CADASTRADAS \n\n");
        mostrarCliente();
        break;   */  
      case 7:
        buscaBebida(t.raiz); //essa função não foi pedida mas caso o professor pergunta-se na hora da apresentação eu ja teria ela pronta
        break;     
      case 8:
        excluirBebida(&t); //essa função não foi pedida mas caso o professor pergunta-se na hora da apresentação eu ja teria ela pronta
        break;   
      case 9:
        freeMemory(t.raiz); 
        break;
          
      default:
        printf(" Opção invalida: \n");
        break;
     }
    }
  return 0;
}


