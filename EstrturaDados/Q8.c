#include <stdio.h>
#include <stdlib.h>

struct item{
    int conteudo;
    struct item* prox;
};

typedef struct item Item;

struct lista{
    Item* inicio;
    Item* fim;
};

typedef struct lista Lista;

Lista* crialista(){
    Lista* ls = (Lista*)malloc(sizeof(Lista));
    ls->inicio = NULL;
    ls->fim = NULL;

    return ls;
}


Lista* lst_insere(Lista* l, int valor){
    Item* novo = (Item*)malloc(sizeof(Item));

    novo->conteudo = valor;
    novo->prox = NULL;

    if(l->inicio == NULL)
    {
        l->inicio = novo;
        l->fim = novo;

        return l;
    }

    l->fim->prox = novo;
    l->fim = novo;

    return l;

}

Lista* lst_concatena(Lista* l1, Lista* l2){
    Lista* novo = (Item*)malloc(sizeof(Item));

    Lista* aux1;
    Lista* aux2;
    aux1 = l1;
    aux2 = l2;

    if(aux1 && aux2 != NULL){

        while(aux1 != NULL){
            novo=aux1->conteudo;
            novo=aux1->prox;
            aux1=aux1->prox;
        }
        if(aux1->prox == NULL){
            while(aux2 != NULL){
                novo=aux2->conteudo;
                novo=aux2->prox;
                aux2=aux2->prox;
            }
        }
    }

    return novo;

}

Lista* lst_imprime(Lista* l){
    Lista* aux = l;
    if (aux != NULL)
    {
        Item* no = aux->inicio;

        if(no != NULL){
            do{
                if(no->prox == aux->inicio)
                    printf("%d", no->conteudo);
                else
                    printf("%d -> ", no->conteudo);
                no = no->prox;

            }while(no != NULL);
        }
    }
    return l;
}

int menu(){
    int opcao;
    do{
        printf("Escolha uma opcao para continuar: \n");
        printf("\n 1 - Inserir lista 1");
        printf("\n 2 - Inserir lista 2");
        printf("\n 3 - Concatenar");
        printf("\n 4 - Sair \n");
        scanf("%d", &opcao);
    }
    while( opcao <1 || opcao>4);
    return opcao;
}

int main(){
    Lista* listmain = NULL;
    Lista* listmain2 = NULL;
    Lista* listmain3 = NULL;
    listmain = crialista();
    listmain2 = crialista();
    listmain3 = crialista();


    int num;
    int nsair=1;

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
                    //inserir
                    printf("Entre com um valor inteiro: \n");
                    scanf("%d",&num);
                    listmain2 = lst_insere(listmain2, num);
                    printf("Valor inserido: %d \n", num);
                break;
                case 3:
                    //inserir
                    printf("Listas cocnatenadas com sucesso!: \n");
                    listmain3 = lst_concatena(listmain, listmain2);
                    printf("________Lista________\n");
                    printf("\n");
                        listmain3 = lst_imprime(listmain3);
                    printf("\n");
                    printf("_____________________\n");
                    printf("\n");
                break;
                case 4:
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
        printf("\n");
    }
    return 0;

}
