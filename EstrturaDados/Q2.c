#include <stdio.h>
#include<stdlib.h> // malloc, free

struct lista{
    int valor;
    struct lista* ant;
    struct lista* prox;
};

typedef struct lista Lista;

Lista* lst_insere(Lista* l, int valor){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->valor = valor;
    novo->prox = l;
    novo->ant = NULL;

    if(l != NULL){
        l->ant = novo;
    }

    return novo;

}

Lista* busca(Lista* l, int valor){
    Lista* aux = l;
    if( aux != NULL){
        while(aux != NULL && aux->valor != valor){
            aux = aux->prox;
        }
        return aux;
    }
    return NULL;
}

Lista* lst_exclui(Lista* l, int valor){
    Lista* aux = l;
    while(aux != NULL && aux->valor != valor){
        aux = aux->prox;
    }

    if(aux != NULL){
        if(aux->ant == NULL && aux->prox ==NULL)
        {
            free(aux);
            return NULL;
        }
        if(aux->ant == NULL){
            l = aux->prox;
            l->ant = NULL;
        }
        else{
            if(aux->prox == NULL){
                (aux->ant)->prox = NULL;
            }
            else{
                Lista* anterior = aux->ant;
                Lista* proximo = aux->prox;

                anterior->prox = proximo;
                proximo->ant = anterior;
            }
            
        }
        
        free(aux);
    }
    else{
         printf("\n Chave %d não encontrada!!\n", valor);
    }
    return l;
}

Lista*imprime(Lista* l){
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
        printf("\n 2 - Excluir");
        printf("\n 3 - Consultar");
        printf("\n 4 - Sair \n");
        scanf("%d", &opcao);
    }
    while( opcao <1 || opcao>4);
    return opcao;
}

int main(){
    Lista* lmain = NULL;
    Lista* resul;
    int num;
    int nsair=1;

    while(nsair){
        int op = menu();
            switch(op){
                case 1:
                    //inserir
                    printf("Entre com um valor inteiro: \n");
                    scanf("%d",&num);
                    lmain = lst_insere(lmain, num);
                    printf("Valor inserido: %d \n",num);
                break;
                case 2:
                    //lst_exclui
                    printf("Entre com o valor a ser excluido: \n");
                    scanf("%d",&num);
                    lmain = lst_exclui(lmain, num);
                break;
                case 3:
                    printf("Entre com o valor a ser buscado: \n");
                    scanf("%d",&num);
                     resul =busca(lmain, num);
                    if(resul)
                        printf("Valor encontrado: %d \n", resul->valor);
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
        if(lmain != NULL){
            lmain = imprime(lmain);
        }
        printf("\n");
        printf("_____________________\n");
        printf("\n");
    }
    return 0;
}






