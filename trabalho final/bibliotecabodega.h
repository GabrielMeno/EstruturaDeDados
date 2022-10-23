#define bibliotecabodega

//structs

typedef struct empresa {
    char nomeEmpresa[50];
    int cnpj;
}Empresa;

struct bebidas{
  int code;
  char nome [30];
  int volume;
  float preco;
  int estoque;
  int tipo; //0 = não alcoólica, 1 = alcoólica  
};

typedef struct bebidas Bebida;

struct treenode{
  Bebida bebida;
  struct treenode *left, *right;

};

typedef struct treenode Node;

struct tree{
  Node *raiz;
};

typedef struct tree DrinkTree;

void initTree(DrinkTree *t){
  t->raiz = NULL;
}

void mostraMenu(){ 
  printf("\n Joãozin BODEGA'S \n");
  printf("OPÇÕES\n");
  printf("1 - Cadastrar bebida;\n2 - Lista bebidas;\n3 - Comprar bebida;\n4 - Vender bebida;\n5 - Cadastrar cliente;\n6 - Mostrar clientes;\n7 - Buscar bebida;\n8 - Excluir bebida;\n9 - Sair\n-");
} 

Node *searchCode(int code, Node *raiz){  //esse nó pesquisa o codigo na arvore e retorna os elementos cadastrados a partir do código da bebida
  if(raiz == NULL || code == raiz->bebida.code) 
    return raiz;
  if(code < raiz->bebida.code) //se o código for menor, pesquisa à esquerda
    return searchCode(code,raiz->left);
  return searchCode(code, raiz->right);
} 

void printSingleNode(Node *n){ //função que printa o nó unico
  setlocale(LC_ALL, "Portuguese");
  printf("Código: %d\nNome: %s\nVolume (em Ml): %d\nPreço: %.2f\nQuantidade em estoque: %d\nTipo (Alcoólica ou não ) ", n->bebida.code, n->bebida.nome, n->bebida.volume, 
  n->bebida.preco, n->bebida.estoque);

  if(n->bebida.tipo == 1) printf("Sim\n\n");
  else printf("Não\n\n");
}

Bebida recebeDados(){ //essa função vai receber os dados das bebidas cadastradas
  setlocale(LC_ALL, "Portuguese");
  Bebida b;

  printf("\nCódigo:"); //codigo da bebida
  scanf("%d", &b.code); 
  printf("Nome:"); //nome da bebida
  scanf("%s", b.nome); 
  printf("Volume (em ML):"); //volume expecificando que deve ser em ml
  scanf("%d", &b.volume);
  printf("Preço:R$"); //preço da bebida
  scanf("%f", &b.preco);
  printf("Quantidade de Estoque:"); //quantidade em estoque
  scanf("%d", &b.estoque);
  printf("Digite 1 = alcoólica ou 0 = não alcoólica:"); //tipo do teor alcoólico
  scanf("%d", &b.tipo);
  return b;
}

Node *newNode(Bebida b){ //função pra um novo nó
  Node *n;
  n=(Node *)malloc(sizeof(Node));
  n->bebida = b;
  n->left = NULL;
  n->right = NULL;
  return n;
}

int validaDados(Bebida b , Node *raiz){ //essa função vai validar os dados | Exemplos a baixo
  setlocale(LC_ALL, "Portuguese");
  int encontrouErro = 0;
  printf("\n");

  if(searchCode(b.code, raiz)){
    printf("Código ja existente!\n\n"); //vai verificar se o código do produto ja foi cadastrado
    printSingleNode(searchCode(b.code, raiz));  
    printf("\n");
    encontrouErro = 1;
  }
  if(b.volume < 0){
    printf("O volume deve ser positivo\n"); //verifica se o volume é positivo e printa avisando caso o dado que foi colocado seja negativo 
    encontrouErro = 1;
  }
  if(b.preco < 0){
    printf("O preço não pode ser um valor negativo!\n"); //no mesmo esquema da de cima, verifica se o preço é negativo e printa a mensagem avisando
    encontrouErro = 1;
  }
  if(b.estoque<0){
    printf("O estoque não pode ficar negativo!\n"); //essa também verifica e avisa que não pode ficar negativo
    encontrouErro = 1;
  }

  if(b.tipo != 1 && b.tipo != 0){
    printf("O tipo da bebida dever ser 1 ou 0!\n"); // verifica se o usuario inseriu os valores corretos (só é permitido 1 ou 0)
    encontrouErro = 1;
  }
  if(encontrouErro){
    printf(" Os dados listados acima estão inválidos. Tente novamente! \n");
    return encontrouErro;
  }
  else return encontrouErro;
}

void cadastrarBebida(DrinkTree *t){  //essa função é que vai utilizar das outras funções para cadastrar as bebidas
  setlocale(LC_ALL, "Portuguese");
  printf("\n CADASTRO DE BEBIDA \n");
    
  Node *n, *aux, *previous;
  int dir;
  Bebida b = recebeDados();
  while(validaDados(b, t->raiz)){
    b = recebeDados();
  }
  n = newNode(b);
  if(t->raiz == NULL){ //árvore vazia
    t->raiz = n;
    return;
  }
  else{ //encontra um lugar na arvore para incluir
    aux=t->raiz; // começa na raiz
	  dir=0;
    while (aux!=NULL){
      previous=aux;
      if (n->bebida.code < aux->bebida.code){ // novo código é menor, vai para a esquerda
        aux=aux->left;
        dir=0; // new node deve ser inserido como um filho a esquerda
      }
      else{
          aux=aux->right;  //o maior vai para a direita
          dir=1; // new node deve ser inserido como um filho a direita
      }
    }
      if (dir) previous->right=n;
      else previous->left=n;
      return;
  }
}

void imprimeTree(Node *raiz){ //essa função vai ler os dados cadastrados na arvore e vai printar como uma "lista de bebidas kk "
  if (raiz==NULL) 
	{
		printf("\n");
	  return;
	}
	imprimeTree(raiz->left);
  printSingleNode(raiz);
	imprimeTree(raiz->right); 
}

void buscaBebida(Node *raiz){ //essa é uma função extra que vai buscar dados especificos (por tal codigo cadastrado ) na arvore 
  setlocale(LC_ALL, "Portuguese");
  int code;
  Node *aux;
  printf("\n  PROCURAR BEBIDA \n\n");
  printf("Digite o código: \n");
  scanf("%d", &code);
  aux = searchCode(code, raiz); //vai procurar pelo codigo
  if(aux == NULL) 
  printf("Bebida não encontrada\n");  // não achou
  else
  {
    printf("\n Bebida encontrada: \n\n"); // achou
    printSingleNode(aux); //printou a bebida e seu demais dados cadastrados
  }
}

Node *doisnode(Node *raiz){ // dois filhos
  Node *promoted;
  if (raiz->right->right == NULL)
  {
    promoted = raiz->right;
    raiz->right = promoted->left;
    promoted->left =NULL;
    return raiz;
  }
  return doisnode(raiz->right);
} 

Node *deleteNode(Node *raiz, int code){ //função para deleta
  setlocale(LC_ALL, "Portuguese");
  Node *newRaiz;
  if (raiz == NULL){
    printf("Bebida não encontrada\n");
    return raiz;
  }
  if (raiz->bebida.code == code) { //Se for folha;
    if (raiz->left == NULL && raiz->right == NULL){
      free(raiz);
      return NULL;
    } //SE TEM UM FILHO
      if (raiz->left == NULL || raiz->right == NULL) {
        newRaiz = (raiz->left == NULL) ? raiz->right : raiz->left; 
        free(raiz);
        return newRaiz;
      } 
        //SE TEM DOIS FILHOS
      if (raiz->left->right == NULL){
        newRaiz = raiz->left;
        } 
      else {
        newRaiz = doisnode(raiz->left);
        newRaiz->left = raiz->left;
      }

      //acima ela verifica se é folha, se tem um filho, se tem dois filhos e aqui a baixo ele vai deletar a raiz
      newRaiz->right = raiz->right;
      free(raiz);
      return newRaiz;
     } else {
        if (raiz->bebida.code < code) {
        raiz->right = deleteNode(raiz->right, code);
      } 
      else {
        raiz->left = deleteNode(raiz->left, code);
      }
    }
  return raiz;
} 

void excluirBebida(DrinkTree *t){  //função extra para excluir um elemento
  setlocale(LC_ALL, "Portuguese");
  int code;
  Node *aux;
  printf("\n EXCLUIR BEBIDA\n\n");
  printf("Insira o codigo da bebida que deseja excluir\n");
  scanf("%d", &code);
  t->raiz = deleteNode(t->raiz, code); //chama a função que deleta a raiz e deleta o elemento do código que o usuario colocou
} 

void comprarBebida(Node *raiz){
  setlocale(LC_ALL, "Portuguese");
  int code;
  Node *aux;
  printf("\n COMPRAR BEBIDA \n\n");
  printf("Insira o Código da bebida desejada\n");
  scanf("%d", &code);
  aux = searchCode(code, raiz);
  if(aux == NULL) 
  printf("Bebida não cadastrada \n");
  //função para comprar bebidas para o estoque da bodega
  //ja sabendo o codigo das bebidas que foram cadastrada 
  //no sistema + preço = estoque | ela encontra o cadastro 
  // e o usuario insere os dados pedidos
  // pra testar voce pode antes de comprar, dar um lista e verificar o estoque, apos a compra, dar um lista e verificar que o estoque novo ja esta em vigor na lista
  else{
    int qtd;
    printf("\n Cadastro Encontrado \n\n");
    printf("Insira quantas unidades deseja comprar\n?");
    scanf("%d", &qtd);
    aux->bebida.estoque = aux->bebida.estoque + qtd;
    printf("\n Compra realizada! Cadastro Atualizado!\n\n");
    printSingleNode(aux);
  }
}

void venderBebida(Node *raiz){
  //aqui a função pede o codigo e verifica se a um produto cadastrado com o mesmo no sistema//
  setlocale(LC_ALL, "Portuguese");
  int code, idade = 18, qtd, mes, dia, ano;
  Node *aux;
  printf("\n VENDER BEBIDA \n\n");
  printf("Insira o código da Bebida\n?");
  scanf("%d", &code);
  aux = searchCode(code, raiz);
  if(aux == NULL)
  {
    printf("Bebida não cadastrada\n");
    return;
  }
/*esta função deveria contar com o cpf do cliente que seria cadastrado mas 
por motivos explicados na apresentação eu não consegui terminar, então pra 
não ficar vaga essa função, implementei um sistema para verificar a  
data de nascimento do cliente para saber se o sujeito é maior ou menor de
idade utilizando a biblioteca time*/ 
  printf("Digite a data de nascimento do cliente\n?");
  scanf("%d/%d/%d", &dia, &mes, &ano);

  struct tm *data_atual; 
  time_t segundos;
  time(&segundos); 
  data_atual = localtime(&segundos);
  
  if(aux->bebida.tipo == 1){
    if ((data_atual->tm_year+1900 - ano) < 18){
      printf("\n Não é permitido a venda de bebidas alcoólicas para menores de 18 anos!\n\n");
      return; /*aqui o joaozin vai pedir a identidade do cliente, como é uma bodega de bairro (porem a maior do sul),
      joaozin, dono da bodega é uma pessoa muito humilde e bastante vivida(termo para não chamar as pessoas de velhas kkk), 
      ele não saberia fazer a conta de cabeça pra verificar se o sujeito e maior de idade ou não, 
      então ele vai inserir a data de nascimento do cliente e a função vai retornar se o cara 
      pode ou não tomar um gorozinho.*/ 
    }
    
    if (data_atual->tm_year+1900 - ano == 18){
      if(data_atual->tm_mon+1 - mes < 0){
        printf("\nNão é permitido a venda de bebidas alcoólicas para menores de 18 anos!\n\n");
        return;
      }
      if(data_atual->tm_mday-1 - dia < 0){
        printf("\nNão é permitido a venda de bebidas alcoólicas para menores de 18 anos!\n\n");
        return;
      }
    }
  }
/*apos o sistema verificar se o cliente é maior ou menor. Se for maior, a venda continua, pedindo a quantidade à comprar
e verificando se tem no estoque*/
  printf("Quantidade à comprar\n?");
  scanf("%d", &qtd);
  if(qtd > aux->bebida.estoque){
    printf("\n Não à estoque suficiente!\n\n");
    return;
  }
  aux->bebida.estoque = aux->bebida.estoque - qtd;  
  printf("\n Venda finalizada \n\n");
}

void freeMemory(Node *raiz){ /* aqui ele vai limpar a memoria e finaliza o programa :) */
  if (raiz==NULL) return;
	freeMemory(raiz->left);
	freeMemory(raiz->right);
  free(raiz);  
}

