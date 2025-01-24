#include<stdio.h>
#include<stdlib.h>


int cadastrar_aviao();
int visualizar_avioes();
int cadastrar_viagem();



int main (){


    int op;

    printf("\n");
    printf("\t---MENU---\n");
    printf("\n1 - Cadastrar aviao: ");
    printf("\n2 - Visualizar avioes disponiveis: ");
    printf("\n3 - Cadastrar viajem: ");
    printf("\n4 - Cadastrar portao de embarque: ");
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


    case 3:
        cadastrar_viagem();
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


int cadastrar_viagem() {
    FILE *dados_viagens = fopen("dados_das_viagens.txt", "a");
    FILE *dados_avioes = fopen("dados_dos_avioes.txt", "r");
    if (dados_viagens == NULL || dados_avioes == NULL) {
        printf("ERRO ao abrir os arquivos!");
        return 1;
    }

    int id, id_existente;
    char partida[100], chegada[100];
    int id_valido = 0;

    printf("\nDigite o ID do aviao que vai fazer a viagem: ");
    scanf("%d", &id);
    getchar();

    // Verificar se o ID do avião existe
    char linha[256];
    while (fgets(linha, sizeof(linha), dados_avioes) != NULL) {
        if (sscanf(linha, "ID: %d", &id_existente) == 1) {
            if (id == id_existente) {
                id_valido = 1;
                break;
            }
        }
    }

    fclose(dados_avioes);

    if (!id_valido) {
        printf("\nERRO: O ID do aviao %d nao existe.\n", id);
        fclose(dados_viagens);
        return 1;
    }

    printf("\nDigite o local de partida: ");
    fgets(partida, 100, stdin);

    printf("\nDigite o local de chegada: ");
    fgets(chegada, 100, stdin);

    fprintf(dados_viagens, "ID do aviao: %d\n", id);
    fprintf(dados_viagens, "Partida: %s", partida);
    fprintf(dados_viagens, "Chegada: %s", chegada);
    fprintf(dados_viagens, "--------------------------\n");

    printf("\nViagem cadastrada com sucesso!\n");

    fclose(dados_viagens);
    return 0;
}

