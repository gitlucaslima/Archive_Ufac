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

Lista* lst_invertida(Lista *l){
    Lista *aux, *ant;
    if (l){ //if (l != NULL)
        ant = l;
        aux = l->prox;
        ant->prox = NULL;
        exit;
    }
    while (aux){// aux != NULL;
        l = aux;
        aux = aux->prox;
        l->prox = ant;
        ant = l;
    }    
    return l;
}

int menu(){
    int opcao;
    do{
        printf("Escolha uma opcao para continuar: \n");
        printf("\n 1 - Inserir");
        printf("\n 2 - Inverter");
        printf("\n 3 - Sair\n");
        scanf("%d", &opcao);
    }
    while( opcao <1 || opcao>3);
    return opcao;
}

int main(){
    Lista* listmain;
    int num = 0;
    int nsair = 1;

    listmain = inicio();

    while(nsair){
        int op = menu();
            switch(op){
                case 1:
                    //inserir
                    printf("Entre com um valor inteiro: \n");
                    scanf("%d",&num);
                    listmain = lst_insere(listmain, num);
                    printf("Valor inserido: %d \n", num);
                break;
                case 2:
                    //inverter
                    listmain = lst_invertida(listmain);
                    printf("A Lista foi invertida:\n");
                break;
                case 3:
                    //sair
                    nsair=0;
                break;
                default:
                    // do anything
                    nsair=0;
                break;

        };
        printf("________Lista________\n");
        printf("\n");
            listmain = lst_imprime(listmain);
        printf("\n");
        printf("_____________________\n");
    }
    return 0;
}