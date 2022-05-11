#include <stdio.h>
#include<stdlib.h> // malloc, free

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
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->fim = NULL;

    return lista;
}

Lista* lst_inserir(Lista* l, int conteudo){
    Lista* aux = l;
    Item* itemnovo = (Item*)malloc(sizeof(Item));
    itemnovo->conteudo = conteudo;

    if(aux->inicio == NULL){
        aux->inicio = itemnovo;
        aux->fim = itemnovo;

        itemnovo->prox = aux->inicio;
    }
    else{
        itemnovo->prox = aux->inicio;
        aux->fim->prox = itemnovo;

        aux->fim = itemnovo;
    }
    return aux;
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
                
            }while(no != aux->inicio);
        }   
    }  
    return l;
}

Lista* lst_exclui(Lista* l, int conteudo){
    Lista* aux;
    aux = l;

    if(aux != NULL){
        if(aux->inicio != NULL)
        {   
            Item* noant = NULL;
            Item* no = aux->inicio;
            do{
                noant = no;
                no = no->prox;

            }while(no != aux->inicio && no->conteudo != conteudo);
            
            if(no->conteudo == conteudo)
            {
                if(aux->inicio == no)
                {   
                    if(no->prox == aux->inicio)
                    {
                        aux->inicio = NULL;
                        aux->fim = NULL;
                    }
                    else
                    {
                        aux->inicio = no->prox;
                        aux->fim->prox = no->prox;
                    }
                }
                else if (aux->fim == no)
                {
                    aux->fim = noant;
                    noant->prox = aux->inicio;
                }
                else
                {
                    noant->prox = no->prox;
                }
            
                free(no);
            }
        }
    }
    return l;
}

Item* lst_busca(Lista* l, int valor){
    Lista* aux = l;

    if(aux != NULL){
        Item* noaux = aux->inicio;

        if(noaux)
        {
            do{
                if(noaux->conteudo == valor)
                {
                    return noaux;
                }
                noaux = noaux->prox;
            }while (noaux != aux->inicio);
        }
    }
    return NULL;
}

int menu(){
    int opcao;
    do{
        printf("Escolha uma opcao para continuar: \n");
        printf("\n 1 - Inserir");
        printf("\n 2 - Excluir");
        printf("\n 3 - Consultar");
        printf("\n 4 - Sair \n");
        scanf("%d", &opcao);
    }
    while( opcao <1 || opcao>4);
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
                    listmain = lst_inserir(listmain, num);
                    printf("Valor inserido: %d \n", num);
                break;
                case 2:
                    //lst_exclui
                    printf("Entre com o valor a ser excluido: \n");
                    scanf("%d",&num);
                    listmain = lst_exclui(listmain, num);
                break;
                case 3:
                    printf("Entre com o valor a ser buscado: \n");
                    scanf("%d",&num);
                     Item* resul = lst_busca(listmain, num);

                    if(resul)
                        printf("Valor encontrado: %d \n", resul->conteudo);
                    else
                        printf("Valor não encontrado!! \n");
                break;
                case 4:
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


