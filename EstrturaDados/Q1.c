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
    int nsair=1;

    while(nsair){
        int op = menu();
            switch(op){
                case 1:
                    //inserir
                    printf("Entre com um valor inteiro: \n");
                break;
                case 2:
                    //lst_exclui
                    printf("Entre com o valor a ser excluido: \n");
                break;
                case 3:
                    printf("Entre com o valor a ser buscado: \n");
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
    }
    return 0;
}
