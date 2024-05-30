void inserir_inicio(No **lista, int num){
  No *novo = malloc(sizeof(No));

  if(novo){
    novo->valor = num;
    novo->proximo = *lista;
    novo->anterior = NULL;
    if(*lista)
      (*lista)->anterior = novo;
    *lista = novo;
  }else
    printf("Erro ao alocar memoria");
}


void inserir_fim(No **lista, int num){
  No *aux, *novo = malloc(sizeof(No));

  if(novo){
    novo->valor = num;
    novo->proximo = NULL;
    
    if(*lista == NULL){
      novo->anterior = NULL;
      *lista = novo;
      novo->anterior = NULL;
    }else{
      aux = *lista;
      while(aux->proximo)
        aux = aux->proximo;
      aux->proximo = novo;
      novo->anterior = aux;
    }
  }else
    printf("Erro ao alocar memoria");
}

void inserir_fim(No **lista, int num){
  No *aux, *novo = malloc(sizeof(No));

  if(novo){
    novo->valor = num;
    novo->proximo = NULL;

    if(*lista == NULL){
      novo->anterior = NULL;
      *lista = novo; 
    }else{
      aux = *lista;
      while(aux->proximo)
        aux = aux->proximo;
      aux->proximo = novo;
    }
  }else
    printf("Erro ao alocar memoria");
}


void inserir_meio(No **lista, int num, int ant){
  No *aux, *novo = malloc(sizeof(No));

  if(novo){
    novo->valor = num;

    if(*lista == NULL){
      novo->proximo = NULL;
      novo->anterior = NULL;
      *lista = novo;
    }else{
      aux = *lista;
      while(aux->valor != ant && aux->proximo)
        aux = aux->proximo;
      novo->proximo = aux->proximo;
      if(aux->proximo)
        aux->proximo->anterior = novo;
      novo->anterior = aux;
      aux->proximo = novo;
      }
    }else
      printf("Erro ao alocar memoria");
}

No* remover(NO **lista, int num){
  No *aux, *remover = NULL;

  if(*lista){
    if((*lista)->valor == num){
      no = *lista;
      *lista = no->proximo;
      if(*lista)
        (*lista)->anterior = NULL;
    }else{
      aux = *lista;
      while(aux->proximo && aux->proximo->valor != num)
        aux = aux->proximo;
      if(aux->proximo){
        no = aux->proximo;
        aux->proximo = no->proximo;
        if(aux->proximo)
          aux->proximo->anterior = aux;
      }
    }
  }
  return no;
}

No* buscar(No **lista, int num){
  No *aux, *no = NULL;

  aux = *lista;
  while(aux && aux->valor != num)
    aux = aux->proximo;
  if(aux)
    no = aux;
  return no;
}

No* ultimo(No **lista){
  No *aux = *lista;
  while(aux->proximo)
    aux = aux->proximo;
  return aux
}

void imprimir_if(No *no){
  printf("\nLista: ");
  while(no){
    printf("%d ", no->valor);
    no = no->proximo;
  }
  printf("\n\n");
}

void imprimir_fi(No *no){
  printf("\nListaata: ");
  while(no){
    printf("%d ", no->valor);
    no = no->anterior;
  }
  printf("\n\n");
}
