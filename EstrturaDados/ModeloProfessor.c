#include <stdio.h>
#include<stdlib.h> // malloc, free

typedef struct lista{
    int chave;
    // próximo elemento da lista
    struct lista *prox; 
} Lista;

Lista *lst_cria(){
    return (Lista*)NULL;
}

Lista *lst_exclui(Lista *l,int valor){
    Lista *aux,*ant;
    ant = aux = l;
    while (aux!=NULL && aux->chave != valor){
        ant = aux;
        aux = aux->prox;
    }
    if (aux){ // if (aux != NULL)
        if (aux == l) // testa se é o primeiro nó
           l = aux->prox; 
        else
            ant->prox = aux->prox;
        free(aux); // exclui aux  da memória
    }else{
        printf("\nChave %d não encontrada!!\n", valor);
    }
    return l;
}

Lista *lst_insere(Lista *l, int valor){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if (novo == NULL){
        printf("\nFALHA DE ALOCAÇÃO DE MEMÓRIA");
        exit(1); // término com falha
    }
    novo->chave = valor;
    novo->prox = l;
    l = novo;
    return l; // lista atualizada
}

void imprime(Lista *l){
    Lista* aux = l;
    printf("\n");
    if (!aux)
        printf("Lista vazia\n");
    while (aux!=NULL){
        printf(" %d -> ", aux->chave);
        aux = aux->prox;
    }
}
int main()
{   
    Lista *inicio = lst_cria();
    inicio = lst_insere(inicio,10);
    inicio = lst_insere(inicio,7);    
    inicio = lst_insere(inicio,4);    
    inicio = lst_insere(inicio,6);    
    inicio = lst_exclui(inicio,9);
    imprime(inicio);    
    inicio = lst_exclui(inicio,4);
    imprime(inicio);    
    inicio = lst_exclui(inicio,6);
    imprime(inicio);
    inicio = lst_exclui(inicio,7);
    imprime(inicio);
    inicio = lst_exclui(inicio,10);
    imprime(inicio);    
    return 0;
}