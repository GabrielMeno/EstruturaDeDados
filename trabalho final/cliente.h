
//isso aqui é um grande desastre, fiquei horas aqui tentando arrumar mas nada, ia das o tempo da entrega dai
//acabei fazendo aquele sisteminha rapido com a data de nascimento

/* #define cliente

struct clientes{
  int idade;
  char nome [40];
  char CPF [12];
  int fiadoTipo; //0 = não fiado, 1 = fiado  
};

typedef struct clientes Cliente;

struct arvorenode{
  Cliente cliente;
  struct arvorenode *left, *right;
};

typedef struct arvorenode Node;

struct tree2{
Node *raiz};

typedef struct tree2 clienteTree;

Node *searchCode2(char CPF, Node *raiz){
  if(raiz == NULL || CPF == raiz->Cliente.CPF) 
    return raiz;
  if(CPF < raiz->Cliente.CPF) //se o código for menor, pesquisa à esquerda
    return searchCode2(CPF,raiz->left);
  return searchCode2(CPF, raiz->right);
}

void initTree2(clienteTree *h){
  h->raiz = NULL;
}

void printSingleNode2(Node *u){
  setlocale(LC_ALL, "Portuguese");
  printf("IDADE: %d\nNOME: %s\nCPF %s\nTipo (fiado ou não ) ", u->Cliente.idade, u->Cliente.nome, u->Cliente.CPF);

  if(u->Cliente.fiadoTipo == 1) printf("Sim\n\n");
  else printf("Não\n\n");
}

Cliente recebeDados2(){
  setlocale(LC_ALL, "Portuguese");
  Cliente c;

  printf("\nIdade:");
  scanf("%d", &c.idade); 
  printf("Nome:");
  scanf("%s", c.nome);
  printf("insira o CPF:");
  scanf("%s", &c.CPF);
  printf("Digite 1 = fiado ou 0 = não fiado:");
  scanf("%d", &c.fiadoTipo);
  return c;
}

int validaDados2(Cliente c , Node *raiz){
  setlocale(LC_ALL, "Portuguese");
  int encontrouErro = 0;
  printf("\n");

  if(searchCode2(c.CPF, raiz)){
    printf("CPF ja existente!\n\n");
    printSingleNode2(searchCode2(c.CPF, raiz));  
    printf("\n");
    encontrouErro = 1;
  }

  if(c.fiadoTipo != 1 && c.fiadoTipo != 0){
    printf("O tipo deve ser 1 ou 0!\n");
    encontrouErro = 1;
  }
  else return encontrouErro;
}

Node *newNode2(Cliente c){
  Node *k;
  k=(Node *)malloc(sizeof(Node));
  k->Cliente = c;
  k->left = NULL;
  k->right = NULL;
  return k;
}

void cadastrarCliente(clienteTree *h){
  setlocale(LC_ALL, "Portuguese");
  printf("\n CADASTRO DE BEBIDA \n");
    
  Node *u, *aux, *previous;
  int dir;
  Cliente c = recebeDados2();
  while(validaDados2(c, h->raiz)){
    c = recebeDados2();
  }
  u = newNode2(c);
  if(h->raiz == NULL){ //árvore vazia
    h->raiz = u;
    return;
  }
  else{ //encontra um lugar na arvore para incluir
    aux=h->raiz; // começa na raiz
	  dir=0;
    while (aux!=NULL){
      previous=aux;
      if (u->Cliente.CPF < aux->Cliente.CPF){ // novo código é menor, vai para a esquerda
        aux=aux->left;
        dir=0; // new node deve ser inserido como um filho a esquerda
      }
      else{
          aux=aux->right;  //o maior vai para a direita
          dir=1; // new node deve ser inserido como um filho a direita
      }
    }
      if (dir) previous->right=u;
      else previous->left=u;
      return;
  }
}  */