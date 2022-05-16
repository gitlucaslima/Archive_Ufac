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

//Resposta questão 7

Lista* lst_mergelista(Lista* l1, Lista* l2){
    Lista* novo, *aux1, *aux2, *aux3, *l3 = (Lista*)malloc(sizeof(Lista));

    aux1 = l1;
    aux2 = l2;
    aux3 = NULL;

    if (aux3 == NULL){
        if (aux1->valor <= aux2->valor)
        {
            aux3 = aux1;
            aux1 = aux1->prox;
        }
        else{
            aux3 = aux2;
            aux2 = aux2->prox;
        }
        l3 = aux3;
    }
    while (aux1 != NULL && aux2 != NULL){
        if (aux1 -> valor <= aux2 -> valor){
            aux3->prox = aux1;
            aux1 = aux1->prox;
            aux3 = aux3->prox;

        }
        else{
            aux3->prox = aux2;
            aux2 = aux2->prox;
            aux3 = aux3->prox;
        }
    }
    if (aux1 == NULL){
        while (aux2 != NULL){
            aux3->prox = aux2;
            aux2 = aux2->prox;
            aux3 = aux3->prox;
        }
    }
    else{
        while (aux1 != NULL){
            aux3->prox = aux1;
            aux1 = aux1->prox;
            aux3 = aux3->prox;
        }
    }
    return l3;
}

Lista* lst_imprime(Lista* l){
    Lista* aux = l;
    while(aux != NULL){
        printf("%d -> ", aux->valor);
        aux=aux->prox;
    }
    return l;
}

int lst_tam(Lista* l){
    Lista* aux = l;
    int tam = 0;
    while(aux != NULL){
        tam++;
        aux=aux->prox;
    }
    return tam;
}

int menu(){
    int opcao;
    do{
        printf("Escolha uma opcao para continuar: \n");
        printf("\n 1 - Inserir na lista 1:");
        printf("\n 2 - Inserir na lista 2:");
        printf("\n 3 - Merge de listas");
        printf("\n 4 - Sair \n");
        scanf("%d", &opcao);
    }
    while( opcao <1 || opcao>4);
    return opcao;
}

int main(){
    Lista* listmain1 = NULL;
    Lista* listmain2 = NULL;
    Lista* listmain3 = NULL;
    int nsair = 1;
    int num = 1;

    // listmain1 = lst_insereOrdenado(listmain1,1);
    // listmain1 = lst_insereOrdenado(listmain1,9);
    // listmain1 = lst_insereOrdenado(listmain1,0); 

    // listmain2 = lst_insereOrdenado(listmain2,6);
    // listmain2 = lst_insereOrdenado(listmain2,2);
    // listmain2 = lst_insereOrdenado(listmain2,4);
    // listmain2 = lst_insereOrdenado(listmain2,4);

    // listmain1 = lst_imprime(listmain1);
    // printf("\n");
    // listmain2 = lst_imprime(listmain2);
    // printf("\n");
    // listmain3 = lst_imprime(listmain3);

    // listmain3 = lst_mergelista(listmain1,listmain2);
    // listmain3 = lst_imprime(listmain3);

        while(nsair){
        int op = menu();
            switch(op){
                case 1:
                    //inserir lista 1
                    printf("Entre com um valor inteiro: \n");
                    scanf("%d",&num);
                    listmain1 = lst_insereOrdenado(listmain1, num);
                    printf("Valor inserido: %d \n", num);
                    printf("________Lista__1_______\n");
                    printf("\n");
                        listmain1 = lst_imprime(listmain1);
                    printf("\n");
                    printf("_____________________\n");
                    printf("\n");
                break;
                case 2:
                    //inserir lista 2
                    printf("Entre com um valor inteiro: \n");
                    scanf("%d",&num);
                    listmain2 = lst_insereOrdenado(listmain2, num);
                    printf("Valor inserido: %d \n", num);
                    printf("________Lista__2_______\n");
                    printf("\n");
                        listmain2 = lst_imprime(listmain2);
                    printf("\n");
                    printf("_____________________\n");
                    printf("\n");

                break;
                case 3:
                    //merge
                    printf("Merge de Listas Feito com Sucesso! \n");
                    listmain3 = lst_mergelista(listmain1, listmain2);
                    printf("________Listas__Unidas___\n");
                    printf("\n");
                        listmain3 = lst_imprime(listmain3);
                    printf("\n");
                    printf("_____________________\n");
                    printf("\n");

                break;
                case 4:
                    //sair
                    nsair=0;

                break;
                default:
                    // do anything
                    nsair=0;
                break;

        };
    }
    return 0;

}