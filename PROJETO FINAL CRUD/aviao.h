
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aviao {
    char modelo[20];
    char destino[20];
    char origem[20];
    char horarios[3][20];
};

struct Passagem {
    char origem[20];
    char destino[20];
    char modelo[20];
    char horario[20];
};

void preencherAvioes(struct Aviao* avioes) {
    strcpy(avioes[0].modelo, "AVIAO 01");
    strcpy(avioes[0].destino, "SAO PAULO");
    strcpy(avioes[0].origem, "CASCAVEL");
    strcpy(avioes[0].horarios[0], "08:00");
    strcpy(avioes[0].horarios[1], "14:00");
    strcpy(avioes[0].horarios[2], "22:00");

    strcpy(avioes[1].modelo, "AVIAO 02");
    strcpy(avioes[1].destino, "SAO PAULO");
    strcpy(avioes[1].origem, "TOLEDO");
    strcpy(avioes[1].horarios[0], "08:00");
    strcpy(avioes[1].horarios[1], "14:00");
    strcpy(avioes[1].horarios[2], "22:00");

    strcpy(avioes[2].modelo, "AVIAO 03");
    strcpy(avioes[2].destino, "CURITIBA");
    strcpy(avioes[2].origem, "TOLEDO");
    strcpy(avioes[2].horarios[0], "08:00");
    strcpy(avioes[2].horarios[1], "14:00");
    strcpy(avioes[2].horarios[2], "22:00");

    strcpy(avioes[3].modelo, "AVIAO 04");
    strcpy(avioes[3].destino, "PORTO ALEGRE");
    strcpy(avioes[3].origem, "TOLEDO");
    strcpy(avioes[3].horarios[0], "08:00");
    strcpy(avioes[3].horarios[1], "14:00");
    strcpy(avioes[3].horarios[2], "22:00");

    strcpy(avioes[4].modelo, "AVIAO 05");
    strcpy(avioes[4].destino, "FOZ DO IGUACU");
    strcpy(avioes[4].origem, "TOLEDO");
    strcpy(avioes[4].horarios[0], "08:00");
    strcpy(avioes[4].horarios[1], "14:00");
    strcpy(avioes[4].horarios[2], "22:00");
}

void mostrarOrigem(struct Aviao* avioes) {
    int i, escolha, opcao;

    printf("INFORME O LOCAL DE EMBARQUE:\n");
    printf("1: TOLEDO\n");
    printf("2: CASCAVEL\n");
    printf("OPCAO (-1 PARA SAIR): ");
    scanf("%i", &escolha);

    if (escolha == -1) {
        printf("OPERACAO CANCELADA.\n");
        return;
    }

    if (escolha != 1 && escolha != 2) {
        printf("OPCAO DE EMBARQUE INVALIDA.\n");
        return;
    }

    printf("DESTINOS DISPONIVEIS A PARTIR DOS LOCAIS DE EMBARQUE:\n");

    for (i = 0; i < 5; i++) {
        if ((escolha == 1 && strcmp(avioes[i].origem, "TOLEDO") == 0) ||
            (escolha == 2 && strcmp(avioes[i].origem, "CASCAVEL") == 0)) {
            printf("DESTINO: %s\n", avioes[i].destino);
            printf("MODELO: %s\n", avioes[i].modelo);
            printf("HORARIOS: %s, %s, %s\n", avioes[i].horarios[0], avioes[i].horarios[1], avioes[i].horarios[2]);

            printf("DESEJA VISUALIZAR OUTRO DESTINO A PARTIR DO MESMO LOCAL DE EMBARQUE? (1 - SIM / 0 - NAO): ");
            scanf("%d", &opcao);

            if (opcao == 0) {
                break;
            }
        }
    }
}

void mostrarDestino(struct Aviao* avioes) {
    int escolha, i;

    printf("INFORME O NUMERO DO DESTINO DESEJADO:\n");
    printf("1: SAO PAULO\n");
    printf("2: SAO PAULO\n");
    printf("3: CURITIBA\n");
    printf("4: PORTO ALEGRE\n");
    printf("5: FOZ DO IGUACU\n");
    scanf("%d", &escolha);

    for (i = 0; i < 5; i++) {
        if (i + 1 == escolha) {
            printf("ORIGEM: %s\n", avioes[i].origem);
            printf("DESTINO: %s\n", avioes[i].destino);
            printf("MODELO: %s\n", avioes[i].modelo);
            printf("HORARIOS: %s, %s, %s\n", avioes[i].horarios[0], avioes[i].horarios[1], avioes[i].horarios[2]);
        }
    }
}

void comprarPassagem(struct Aviao* avioes) {
    int escolha2;
    struct Passagem passagem;

    printf("COMPRA DE PASSAGEM\n");
    printf("DESEJA COMPRAR COM BASE NA ORIGEM OU DESTINO? 1 - ORIGEM, 2 - DESTINO: ");
    scanf("%d", &escolha2);

    if (escolha2 == 1) {
        mostrarOrigem(avioes);

        printf("INFORME O NUMERO DO DESTINO DESEJADO: ");
        int escolha;
        scanf("%d", &escolha);

        if (escolha >= 1 && escolha <= 5) {
            strcpy(passagem.origem, "TOLEDO");
            strcpy(passagem.destino, avioes[escolha - 1].destino);
            strcpy(passagem.modelo, avioes[escolha - 1].modelo);
            strcpy(passagem.horario, avioes[escolha - 1].horarios[0]);

            printf("PASSAGEM COMPRADA COM SUCESSO!\n");
        } else {
            printf("OPCAO DE DESTINO INVALIDA.\n");
        }
    } else if (escolha2 == 2) {
        mostrarDestino(avioes);

        printf("INFORME O NUMERO DO DESTINO DESEJADO: ");
        int escolha;
        scanf("%d", &escolha);

        if (escolha >= 1 && escolha <= 5) {
            strcpy(passagem.origem, avioes[escolha - 1].origem);
            strcpy(passagem.destino, avioes[escolha - 1].destino);
            strcpy(passagem.modelo, avioes[escolha - 1].modelo);
            strcpy(passagem.horario, avioes[escolha - 1].horarios[0]);

            printf("PASSAGEM COMPRADA COM SUCESSO!\n");
        } else {
            printf("OPCAO DE DESTINO INVALIDA.\n");
        }
    } else {
        printf("OPCAO INVALIDA.\n");
    }

    printf("DETALHES DA PASSAGEM:\n");
    printf("ORIGEM: %s\n", passagem.origem);
    printf("DESTINO: %s\n", passagem.destino);
    printf("MODELO: %s\n", passagem.modelo);
    printf("HORARIO: %s\n", passagem.horario);

    FILE *arquivo;
            arquivo = fopen("compra.txt", "a");

            if (arquivo == NULL) {
                printf("Erro ao abrir o arquivo.\n");
                return;
            }

            fprintf(arquivo, "---------------------------------------------\n");
            fprintf(arquivo, "Detalhes da passagem:\n");
            fprintf(arquivo, "Origem: %s\n", passagem.origem);
            fprintf(arquivo, "Destino: %s\n", passagem.destino);
            fprintf(arquivo, "Modelo: %s\n", passagem.modelo);
            fprintf(arquivo, "Horario: %s\n", passagem.horario);
            fprintf(arquivo, "---------------------------------------------\n");

            fclose(arquivo);
}
