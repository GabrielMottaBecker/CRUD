#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura de dados para os assentos
struct Assentos {
    int valor;
    int numero;
    char classe;
    int status;
};

// Declaração do array de assentos
struct Assentos assento[50];

void assentosLivres() {
    printf("ASSENTOS LIVRES:\n");
    printf("FRENTE DO AVIAO:\n");

    int i; // Declaração da variável i fora do loop for
    for (i = 0; i < 50; i++) {
        if (assento[i].status == 0) {
            printf("[ ]");
        } else {
            printf("[X]");
        }

        if ((i + 1) % 2 == 0) {
            printf("  ");
        }

        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
}

void escolherAssento() {
    char resposta;
    int numeroAssento;

    do {
        printf("DIGITE O NUMERO DO ASSENTO DESEJADO (1 A 50): ");
        scanf("%d", &numeroAssento);

        // Verificar se o numero do assento e valido
        if (numeroAssento < 1 || numeroAssento > 50) {
            printf("NUMERO DE ASSENTO INVALIDO.\n");
            continue;
        }

        // Verificar se o assento ja esta ocupado
        if (assento[numeroAssento - 1].status == 1) {
            printf("O ASSENTO %d JA ESTA OCUPADO.\n", numeroAssento);
            continue;
        }

        // Vender o assento
        assento[numeroAssento - 1].status = 1;
        assento[numeroAssento - 1].numero = numeroAssento;

        printf("ASSENTO %d ESCOLHIDO COM SUCESSO.\n", numeroAssento);

        printf("DESEJA ESCOLHER OUTRO ASSENTO? (S/N): ");
        scanf(" %c", &resposta);
    } while (resposta == 'S' || resposta == 's');

    // Adicionar a secao de preco do assento
    int precoAssento;

    printf("DIGITE O PRECO DO ASSENTO: ");
    scanf("%d", &precoAssento);

    // Armazenar o preco do assento na estrutura
    assento[numeroAssento - 1].valor = precoAssento;

    FILE *arquivo;
    arquivo = fopen("compra.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "Assento Comprado: %d\n", numeroAssento);
    fprintf(arquivo, "Preco do Assento: %d\n", precoAssento);

    fclose(arquivo);
}
