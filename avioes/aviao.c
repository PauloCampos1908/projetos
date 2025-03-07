#include <stdio.h>
#include <stdlib.h>

// Declarações das funções
int cadastrar_aviao();
int visualizar_avioes();
int cadastrar_viagem();
int visualizar_viagem();

int main() {
    int op;

    while (1) {
        printf("\n");
        printf("\t---MENU---\n");
        printf("\n1 - Cadastrar aviao");
        printf("\n2 - Visualizar avioes disponiveis");
        printf("\n3 - Cadastrar viagem");
        printf("\n4 - Visualizar viagens");
        printf("\n0 - Sair");
        printf("\n\nOpcao escolhida: ");
        scanf("%d", &op);
        getchar();

        switch (op) {
            case 1:
                cadastrar_aviao();
                break;
            case 2:
                visualizar_avioes();
                break;
            case 3:
                cadastrar_viagem();
                break;

            case 4:
                visualizar_viagem();
                break;

            case 0:
                printf("\nSaindo do programa...\n");
                exit(0);
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}

int cadastrar_aviao() {
    FILE *dados_avioes = fopen("dados_dos_avioes.txt", "a");
    if (dados_avioes == NULL) {
        printf("ERRO ao abrir o arquivo de aviões!");
        return 1;
    }

    int codigo_aviao;
    char nome_aviao[100];
    char piloto[100];

    printf("\nDigite o nome do piloto que vai dirigir o aviao: ");
    fgets(piloto, 100, stdin);

    printf("\nDigite o codigo do aviao: ");
    scanf("%d", &codigo_aviao);
    getchar();

    printf("\nDigite o nome do aviao: ");
    fgets(nome_aviao, 100, stdin);

    fprintf(dados_avioes, "ID: %d\n", codigo_aviao);
    fprintf(dados_avioes, "Piloto: %s", piloto);
    fprintf(dados_avioes, "Aviao: %s", nome_aviao);
    fprintf(dados_avioes, "--------------------------\n");

    fclose(dados_avioes);

    printf("\nAviao cadastrado com sucesso!\n");
    return 0;
}

int visualizar_avioes() {
    FILE *dados_avioes = fopen("dados_dos_avioes.txt", "r");
    if (dados_avioes == NULL) {
        printf("ERRO ao abrir o arquivo de aviões!");
        return 1;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), dados_avioes) != NULL) {
        printf("%s", linha);
    }

    fclose(dados_avioes);
    printf("\n--------------------------\n");
    return 0;
}

int cadastrar_viagem() {
    FILE *dados_viagens = fopen("dados_das_viagens.txt", "a+");
    if (dados_viagens == NULL) {
        printf("ERRO ao abrir o arquivo de viagens!\n");
        return 1;
    }

    int id, id_existente;
    char partida[100], chegada[100];
    int id_ja_usado = 0;

    printf("\nDigite o ID do aviao que vai fazer a viagem: ");
    scanf("%d", &id);
    getchar();

    // Verificar se o ID já foi usado em uma viagem
    rewind(dados_viagens); // Volta ao início do arquivo para leitura
    while (fscanf(dados_viagens, "ID do aviao: %d", &id_existente) == 1) {
        if (id == id_existente) {
            id_ja_usado = 1;
            break;
        }
    }

    if (id_ja_usado) {
        printf("\nERRO: O ID do aviao %d ja foi usado em uma viagem.\n", id);
        fclose(dados_viagens);
        return 1;
    }

    // Caso o ID seja válido, solicitar dados da viagem
    printf("\nDigite o local de partida: ");
    fgets(partida, sizeof(partida), stdin);

    printf("\nDigite o local de chegada: ");
    fgets(chegada, sizeof(chegada), stdin);

    // Salvar os dados da viagem no arquivo
    fprintf(dados_viagens, "ID do aviao: %d\n", id);
    fprintf(dados_viagens, "Partida: %s", partida);
    fprintf(dados_viagens, "Chegada: %s", chegada);
    fprintf(dados_viagens, "--------------------------\n");

    printf("\nViagem cadastrada com sucesso!\n");

    fclose(dados_viagens);
    return 0;
}

int visualizar_viagem(){

     FILE *dados_viagem = fopen("dados_das_viagens.txt", "r");
    if (dados_viagem == NULL) {
        printf("ERRO ao abrir o arquivo de viagens!");
        return 1;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), dados_viagem) != NULL) {
        printf("%s", linha);
    }

    fclose(dados_viagem);
    return 0;

}
