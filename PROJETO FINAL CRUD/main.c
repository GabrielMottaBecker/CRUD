/*
1. **PRIMEIRAMENTE DEVE SER FEITO O CADASTRO. AP�S ISSO, PODE SEGUIR AS OUTRAS OPERA��ES DO CRUD.**
2. **PARA PROSSEGUIR PARA A "VIS�O DO CLIENTE", � ESSENCIAL QUE FA�A O "LOGIN CLIENTE", NA OPERA��O 10.**
3. **AP�S SER FEITO O LOGIN, PODE PROSSEGUIR PARA A OP��O 7, PARA VISUALIZAR OS VOOS DISPON�VEIS, OU OP��O 6, PARA COMPRAR O/OS ASSENTO/S.**
4. **A ESCOLHA DO ASSENTO DEVE SER FEITA ANTES DE COMPRAR A PASSAGEM.**
5. **AP�S COMPRAR O ASSENTO, PROSSEGUIR PARA O CASE 8, E REALIZAR AS OPERA��ES DE CANCELAMENTO OU ALTERA��O.**
6. **PARA ESCOLHER O DESTINO/ORIGEM, ELE VAI SOLICITAR O N�MERO, COLOQUE O N�MERO DO AVI�O. EX: FOZ: AVI�O 05 - DIGITAR 5.**
7. **DEPOIS DE COMPRAR, O ARQUIVO COMPRA.TXT ESTAR� DEVIDAMENTE PREENCHIDO COM AS INFORMA��ES. */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "aviao.h"
#include "assentos.h"

int main() {

     // Declara��o e preenchimento do array de estruturas "avioes"
    struct Aviao avioes[5];
    preencherAvioes(avioes);

     // Declara��o de vari�veis
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
