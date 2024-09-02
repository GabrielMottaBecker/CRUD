#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura de dados para uma pessoa (cliente)
struct Pessoa {
    char nome[50];
    char sobrenome[50];
    int idade;
    char telefone[13];
    char cpf[11];
    char rg[9];
} cliente[10];

void cadastraCliente() {
    int i = 0;
    char opcao;

    do {
        printf("CADASTRAR CLIENTE: \n");
        printf("NOME: ");
        gets(cliente[i].nome);

        printf("SOBRENOME: ");
        gets(cliente[i].sobrenome);

        printf("IDADE: ");
        scanf("%d", &cliente[i].idade);
        getchar();

        printf("TELEFONE: ");
        gets(cliente[i].telefone);

        printf("CPF: ");
        gets(cliente[i].cpf);

        printf("RG: ");
        gets(cliente[i].rg);

        printf("DESEJA CADASTRAR OUTRO CLIENTE? (S/N): ");
        scanf(" %c", &opcao);
        getchar();

        i++;
    } while ((opcao == 'S' || opcao == 's') && i < 10);
}

void atualizaCliente() {
    int i;

    printf("DIGITE O INDICE DO CLIENTE QUE DESEJA ATUALIZAR (1-10): ");
    scanf("%d", &i);
    getchar();

    i--;

    if (i >= 0 && i < 10) {
        printf("ATUALIZANDO INFORMACOES DO CLIENTE %d\n", i + 1);
        printf("NOME: ");
        gets(cliente[i].nome);

        printf("SOBRENOME: ");
        gets(cliente[i].sobrenome);

        printf("IDADE: ");
        scanf("%d", &cliente[i].idade);
        getchar();

        printf("TELEFONE: ");
        gets(cliente[i].telefone);

        printf("CPF: ");
        gets(cliente[i].cpf);

        printf("RG: ");
        gets(cliente[i].rg);

        printf("INFORMACOES DO CLIENTE ATUALIZADAS COM SUCESSO.\n");
    } else {
        printf("INDICE INVALIDO.\n");
    }
}

void visualizaCliente() {
    int i;

    printf("CLIENTES CADASTRADOS:\n");
    for (i = 0; i < 10; i++) {
        printf("CLIENTE %d:\n", i + 1);
        printf("NOME: %s\n", cliente[i].nome);
        printf("SOBRENOME: %s\n", cliente[i].sobrenome);
        printf("IDADE: %d\n", cliente[i].idade);
        printf("TELEFONE: %s\n", cliente[i].telefone);
        printf("CPF: %s\n", cliente[i].cpf);
        printf("RG: %s\n", cliente[i].rg);
        printf("\n");
    }
}

void excluiCliente() {
    int i;

    printf("DIGITE O INDICE DO CLIENTE QUE DESEJA EXCLUIR (1-10): ");
    scanf("%d", &i);
    getchar();

    i--;

    if (i >= 0 && i < 10) {
        printf("EXCLUINDO CLIENTE %d\n", i + 1);

        int j;
        for (j = i; j < 9; j++) {
            cliente[j] = cliente[j + 1];
        }

        strcpy(cliente[9].nome, "");
        strcpy(cliente[9].sobrenome, "");
        cliente[9].idade = 0;
        strcpy(cliente[9].telefone, "");
        strcpy(cliente[9].cpf, "");
        strcpy(cliente[9].rg, "");

        printf("CLIENTE EXCLUIDO COM SUCESSO.\n");
    } else {
        printf("INDICE INVALIDO.\n");
    }
}

void loginCliente() {
    int i;

    printf("CLIENTES CADASTRADOS:\n");
    for (i = 0; i < 10; i++) {
        printf("%d. %s %s\n", i + 1, cliente[i].nome, cliente[i].sobrenome);
    }

    printf("\nSELECIONE O CLIENTE (1-10) PARA REALIZAR AS OPERACOES: ");
    scanf("%d", &i);
    getchar();

    if (i >= 1 && i <= 10) {
        struct Pessoa clienteSelecionado = cliente[i - 1];
        printf("\nCLIENTE LOGADO:\n");
        printf("NOME: %s\n", clienteSelecionado.nome);
        printf("SOBRENOME: %s\n", clienteSelecionado.sobrenome);

        FILE *arquivo;
        arquivo = fopen("compra.txt", "w");

        if (arquivo == NULL) {
            printf("ERRO AO ABRIR O ARQUIVO.\n");
            return;
        }

        fprintf(arquivo, "CLIENTE: \n");
        fprintf(arquivo, "NOME: %s %s\n", clienteSelecionado.nome, clienteSelecionado.sobrenome);
        fprintf(arquivo, "---------------------------------------------\n");

        fclose(arquivo);
    } else {
        printf("INDICE INVALIDO.\n");
    }
}
