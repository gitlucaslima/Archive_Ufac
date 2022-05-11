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
        printf("\n 1 - Inserir");
        printf("\n 2 - Quantidade de nós");
        printf("\n 3 - Sair \n");
        scanf("%d", &opcao);
    }
    while( opcao <1 || opcao>3);
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

                    printf("________Lista________\n");
                    printf("\n");
                    if(listmain != NULL){
                        listmain = lst_imprime(listmain);
                    }
                    printf("\n");
                    printf("_____________________\n");
                    printf("\n");
                break;
                case 2:
                    //quantidade de nós
                    printf("A quantidade de nós é: ");
                    int a = lst_tam(listmain);
                    printf("%d",a);
                    printf("\n");
                break;
                case 3:
                    // sair
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