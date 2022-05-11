#include <stdio.h>
#include <stdlib.h>

struct lista {
    int conteudo;
    struct lista* prox;
};
typedef struct lista Lista;

Lista* inicio (void){
    return NULL;
}

Lista* lst_insere (Lista* l, int i){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->conteudo = i;
    novo->prox = l;

 return novo;
}

Lista* lst_imprime(Lista* l){
    Lista* aux = l;
    printf("{");
    while (aux != NULL)
    {
        printf(" %d", aux->conteudo);
        aux = aux->prox;
        if(aux == NULL)
            printf(" }");
    }
    
    return l;
}

int main(){
    

}