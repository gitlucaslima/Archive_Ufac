#include <stdio.h>
#include<stdlib.h>

typedef struct lista{
    int chave;
    struct lista *prox;
} Lista;

Lista *lst_cria(){
    return (Lista*)NULL;
}

Lista *lst_insere(Lista *l, int valor){
    Lista *novo = (Lista*)malloc(sizeof(Lista));

    novo->chave = valor;
    novo->prox = l;
    l = novo;
    return l;
}

Lista *lst_posici(Lista *l, int valor, int p){
    Lista *aux1,* aux2,*tam,*novo = (Lista*)malloc(sizeof(Lista));
    int cont =0,conta2 =0;
    aux1 =l;
    tam =l;
    p = p-1;

    novo->chave = valor;
    while(tam != NULL){
        tam = tam->prox;
        conta2++;
    }
    if(p >conta2 || p<0){
        aux2 = l;
        while(aux2->prox != NULL)
            aux2 = aux2->prox;
        aux2->prox = novo;
        l = novo;
        return l;
    }
    while(cont <p-1){
        aux1 = aux1->prox;
        cont++;
    }
    aux2 = aux1->prox;
    aux1->prox = novo;
    novo->prox=aux2;
    l = novo;
    return l;
}


Lista* lst_imprime(Lista* l){
    Lista* aux = l;
    while(aux != NULL){
        printf("%d -> ", aux->chave);
        aux=aux->prox;
    }
    return l;
}

int menu(){
	int opcao;
	do{
		printf("\n1 - Inserir");
        printf("\n2 - Inserir na posicao");
		printf("\n3 - Sair\n");
		scanf("%d", &opcao);
	} while( opcao <1 || opcao>4);
	return opcao;
}

int main(){
    Lista *listmain = lst_cria();
    Lista *listmain2 = lst_cria();
    int nsair=1;
    int num;
    int p;

        while(nsair){
        int op = menu();
            switch(op){
                case 1:
                    printf("Entre com um valor inteiro: \n");
                    scanf("%d",&num);
                    listmain = lst_insere(listmain,num);
               break;
                case 2:
                   printf("Entre com um valor inteiro: \n");
                   scanf("%d",&num);
                   printf("Digite a posicao: \n");
                   scanf("%d",&p);
                   listmain2 = lst_posici(listmain,num,p);
                   printf("________Lista________\n");
                    printf("\n");
                        listmain2 = lst_imprime(listmain2);
                    printf("\n");
                    printf("_____________________\n");
                    printf("\n");
                break;
                case 3:
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
