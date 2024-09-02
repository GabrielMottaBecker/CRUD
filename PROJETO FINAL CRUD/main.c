/*
1. **PRIMEIRAMENTE DEVE SER FEITO O CADASTRO. APÓS ISSO, PODE SEGUIR AS OUTRAS OPERAÇÕES DO CRUD.**
2. **PARA PROSSEGUIR PARA A "VISÃO DO CLIENTE", É ESSENCIAL QUE FAÇA O "LOGIN CLIENTE", NA OPERAÇÃO 10.**
3. **APÓS SER FEITO O LOGIN, PODE PROSSEGUIR PARA A OPÇÃO 7, PARA VISUALIZAR OS VOOS DISPONÍVEIS, OU OPÇÃO 6, PARA COMPRAR O/OS ASSENTO/S.**
4. **A ESCOLHA DO ASSENTO DEVE SER FEITA ANTES DE COMPRAR A PASSAGEM.**
5. **APÓS COMPRAR O ASSENTO, PROSSEGUIR PARA O CASE 8, E REALIZAR AS OPERAÇÕES DE CANCELAMENTO OU ALTERAÇÃO.**
6. **PARA ESCOLHER O DESTINO/ORIGEM, ELE VAI SOLICITAR O NÚMERO, COLOQUE O NÚMERO DO AVIÃO. EX: FOZ: AVIÃO 05 - DIGITAR 5.**
7. **DEPOIS DE COMPRAR, O ARQUIVO COMPRA.TXT ESTARÁ DEVIDAMENTE PREENCHIDO COM AS INFORMAÇÕES. */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "aviao.h"
#include "assentos.h"

int main() {

     // Declaração e preenchimento do array de estruturas "avioes"
    struct Aviao avioes[5];
    preencherAvioes(avioes);

     // Declaração de variáveis
    int escolha, rodando = 1;

    printf("SEJA BEM VINDO A AGENCIA DE VIAGENS VOA AVIAOZINHO\n");

    while (rodando == 1) {

        printf("\n QUAL OPERACAO DESEJA REALIZAR?                \n");
        printf(" ----------------------------------------------- \n");
        printf(" 1  - CADASTRAR CLIENTES                         \n");
        printf(" 2  - ATUALIZAR CLIENTES                         \n");
        printf(" 3  - VISUALIZAR CLIENTES                        \n");
        printf(" 4  - EXCLUIR CLIENTES                           \n");
        printf(" 10 - LOGIN DO CLIENTE                           \n");
        printf(" ----------------------------------------------- \n");
        printf(" 6  - COMPRE SEU ASSENTO                         \n");
        printf(" 7  - VEJA AS OPCOES DE EMBARQUE E DESEMBARQUE   \n");
        printf(" 8  - COMPRE SUA PASSAGEM AQUI!                  \n");
        printf(" ----------------------------------------------- \n");
        printf(" 5  - SAIR                                       \n");
        printf("\n SUA OPCAO:                                      \n");
        scanf("%d", &escolha);

        system("cls");

        switch (escolha) {
            case 1:
                cadastraCliente();
                break;
            case 2:
                atualizaCliente();
                break;
            case 3:
                visualizaCliente();
                break;
            case 4:
                excluiCliente();
                break;
            case 5:
                printf("SAINDO DO PROGRAMA...\n");
                rodando = 0;
                break;
            case 6:
                printf("VENDA DE ASSENTOS\n");
                assentosLivres();
                printf("DESEJA COMPRAR UM LUGAR?\n");
                escolherAssento();
                assentosLivres();
                break;
            case 7:
                printf("EMBARQUE E DESEMBARQUE\n");

                int opcao;

                printf("ESCOLHA UMA OPCAO:\n");
                printf("1. EMBARQUE\n");
                printf("2. DESEMBARQUE\n");
                scanf("%d", &opcao);

                if (opcao == 1) {
                    mostrarOrigem(avioes);
                } else if (opcao == 2) {
                    mostrarDestino(avioes);
                } else {
                    printf("OPCAO INVALIDA.\n");
                }
                break;
            case 8: {
                comprarPassagem(avioes);
                }
                break;
            case 10: {
                loginCliente();
                }
                break;
        }
    }
return 0;

}
