#include <stdio.h>
#include <stdlib.h> // malloc, free

struct lista{
    int valor;
    struct lista* prox;
};

typedef struct lista Lista;

Lista* lst_insereOrdenado(Lista* l, int valor){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->prox = NULL;
    novo->valor = valor;
    Lista* aux = l;
    Lista* ant = NULL;

    if(l == NULL)
    {
        l = novo;
        return l;
    }

    while(aux != NULL && aux->valor <= valor)
    {
        ant = aux;
        aux = aux->prox;
    }

    if(ant == NULL)
    {
        novo->prox = aux;
        l = novo;
    }
    else if (ant->prox == NULL)
    {
        ant->prox = novo;
        novo->prox = NULL;
    }
    else
    {
        ant->prox = novo;
        novo->prox= aux;
    }

    return l;

}

Lista* lst_imprime(Lista* l){
    Lista* aux = l;
    while(aux != NULL){
        printf("%d -> ", aux->valor);
        aux=aux->prox;
    }
    return l;
}

int menu(){
    int opcao;
    do{
        printf("Escolha uma opcao para continuar: \n");
        printf("\n 1 - Inserir");
        printf("\n 2 - Sair \n");
        scanf("%d", &opcao);
    }
    while( opcao <1 || opcao>2);
    return opcao;
}

int main(){
    Lista* listmain = NULL;
    int nsair=1;
    int num;

    while(nsair){
        int op = menu();
            switch(op){
                case 1:
                    //inserir
                    printf("Entre com um valor inteiro: \n");
                    scanf("%d",&num);
                    listmain = lst_insereOrdenado(listmain, num);
                    printf("Valor inserido: %d \n",num);
                break;
                case 2:
                    // sair
                    nsair=0;

                break;
                default:
                    // do anything
                    nsair=0;
                break;

        };
        printf("________Lista________\n");
        printf("\n");
        if(listmain != NULL){
            listmain = lst_imprime(listmain);
        }
        printf("\n");
        printf("_____________________\n");
        printf("\n");
    }
    return 0;

}