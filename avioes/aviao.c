#include<stdio.h>
#include<stdlib.h>


int cadastrar_aviao();
int visualizar_avioes();



int main (){


    int op;

    printf("\n");
    printf("\t---MENU---\n");
    printf("\n1 - Cadastrar aviao: ");
    printf("\n2 - Cadastrar portao de embarque: ");
    printf("\n3 - Cadastrar viajem: ");
    printf("\n4 - Visualizar avioes disponiveis: ");
    printf("\n5 - Visualizar todos avioes: ");
    printf("\n6 - Deletar viagens: ");
    printf("\n7 - Deletar avioes: ");
    printf("\n8 - sair");

    printf("\nopcao escolhida: ");
    scanf("%d",&op);
    getchar();

    switch(op){

    case 1:
        cadastrar_aviao();
    break;



    case 2:
        visualizar_avioes();
    break;







    default:
        printf("Opcao invalida.\n");
    }

}

int cadastrar_aviao(){

    FILE *dados_avioes;

    dados_avioes = fopen("dados_dos_avioes.txt", "a");
    if(dados_avioes == NULL){
        printf("ERRO!");
        return 1;
    }
    int codigo_aviao;
    char nome_aviao[100];
    char piloto[100];


    printf("\nDigite o nome do piloto que vai dirigir o aviao: ");
    fgets(piloto,100,stdin);

    printf("\nDigite o codigo do aviao: ");
    scanf("%d",&codigo_aviao);
    getchar();

    printf("\nDigite o nome do aviao: ");
    fgets(nome_aviao,100,stdin);


    fprintf(dados_avioes,"---MENU---");
    fprintf(dados_avioes,"\nNome do piloto: %s",piloto);
    fprintf(dados_avioes,"Id do aviao: %d\n",codigo_aviao);
    fprintf(dados_avioes,"Nome do aviao: %s",nome_aviao);
    fprintf(dados_avioes,"-------------");

    fclose(dados_avioes);

    printf("\nAviao cadastrado com sucesso!!");


return 0;

}

int visualizar_avioes(){
    FILE *dados_avioes;
    char linha[10];

    dados_avioes = fopen("dados_dos_avioes.txt","r");
     if (dados_avioes == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    while (fgets(linha, sizeof(linha), dados_avioes) != NULL) {
        printf("%s", linha); // Exibe cada linha do arquivo
    }

    fclose(dados_avioes);
    printf("\n--------------------------\n");

    return 0;

}




