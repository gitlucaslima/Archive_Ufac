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
        printf("\n 1 - Inserir");
        printf("\n 2 - Sair \n");
        scanf("%d", &opcao);
    }
    while( opcao <1 || opcao>3);
    return opcao;
}

int main(){
    Lista* listmain = NULL;
    listmain = crialista();

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
            listmain = lst_imprime(listmain);
        printf("\n");
        printf("_____________________\n");
        printf("\n");
    }
    return 0;

}