#include <stdio.h>
#include <string.h>

int main() {
    // --- CARTAS PRÉ-CADASTRADAS ---
    char nomePais1[] = "Brasil";
    unsigned long int populacao1 = 214300000;
    float area1 = 8515767.0;
    float pib1 = 1608.0; // Em bilhões
    int pontosTuristicos1 = 150;
    float densidade1 = (float)populacao1 / area1;
    float pibPerCapita1 = (pib1 * 1000000000.0) / (float)populacao1;

    char nomePais2[] = "Argentina";
    unsigned long int populacao2 = 45810000;
    float area2 = 2780400.0;
    float pib2 = 487.2; // Em bilhões
    int pontosTuristicos2 = 80;
    float densidade2 = (float)populacao2 / area2;
    float pibPerCapita2 = (pib2 * 1000000000.0) / (float)populacao2;

    // Variáveis para armazenar as escolhas e os valores selecionados
    int escolha1, escolha2;
    float valor1_carta1, valor1_carta2;
    float valor2_carta1, valor2_carta2;
    char nome_attr1[40], nome_attr2[40];

    printf("========================================\n");
    printf("   SUPER TRUNFO - CONFRONTO DE PAISES   \n");
    printf("========================================\n\n");

    // --- MENU 1 ---
    printf("Escolha o PRIMEIRO atributo para comparacao:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("Digite a opcao: ");
    scanf("%d", &escolha1);

    // Processando a primeira escolha
    switch(escolha1) {
        case 1:
            valor1_carta1 = (float)populacao1; valor1_carta2 = (float)populacao2;
            strcpy(nome_attr1, "Populacao"); break;
        case 2:
            valor1_carta1 = area1; valor1_carta2 = area2;
            strcpy(nome_attr1, "Area"); break;
        case 3:
            valor1_carta1 = pib1; valor1_carta2 = pib2;
            strcpy(nome_attr1, "PIB"); break;
        case 4:
            valor1_carta1 = (float)pontosTuristicos1; valor1_carta2 = (float)pontosTuristicos2;
            strcpy(nome_attr1, "Pontos Turisticos"); break;
        case 5:
            valor1_carta1 = densidade1; valor1_carta2 = densidade2;
            strcpy(nome_attr1, "Densidade Demografica"); break;
        default:
            printf("\nOpcao invalida! O jogo sera encerrado.\n");
            return 1;
    }

    // --- MENU 2 (DINÂMICO) ---
    printf("\nEscolha o SEGUNDO atributo para comparacao:\n");
    // O menu só exibe as opções que NÃO foram escolhidas no Menu 1
    if(escolha1 != 1) printf("1 - Populacao\n");
    if(escolha1 != 2) printf("2 - Area\n");
    if(escolha1 != 3) printf("3 - PIB\n");
    if(escolha1 != 4) printf("4 - Pontos Turisticos\n");
    if(escolha1 != 5) printf("5 - Densidade Demografica\n");
    printf("Digite a opcao: ");
    scanf("%d", &escolha2);

    // Validação para impedir atributos iguais
    if(escolha1 == escolha2) {
        printf("\nErro: Voce escolheu o mesmo atributo duas vezes. O jogo sera encerrado.\n");
        return 1;
    }

    // Processando a segunda escolha
    switch(escolha2) {
        case 1:
            valor2_carta1 = (float)populacao1; valor2_carta2 = (float)populacao2;
            strcpy(nome_attr2, "Populacao"); break;
        case 2:
            valor2_carta1 = area1; valor2_carta2 = area2;
            strcpy(nome_attr2, "Area"); break;
        case 3:
            valor2_carta1 = pib1; valor2_carta2 = pib2;
            strcpy(nome_attr2, "PIB"); break;
        case 4:
            valor2_carta1 = (float)pontosTuristicos1; valor2_carta2 = (float)pontosTuristicos2;
            strcpy(nome_attr2, "Pontos Turisticos"); break;
        case 5:
            valor2_carta1 = densidade1; valor2_carta2 = densidade2;
            strcpy(nome_attr2, "Densidade Demografica"); break;
        default:
            printf("\nOpcao invalida! O jogo sera encerrado.\n");
            return 1;
    }

    // --- CÁLCULO DAS SOMAS ---
    float soma_carta1 = valor1_carta1 + valor2_carta1;
    float soma_carta2 = valor1_carta2 + valor2_carta2;

    // --- EXIBIÇÃO DOS RESULTADOS ---
    printf("\n========================================\n");
    printf("          RESULTADO DO CONFRONTO          \n");
    printf("========================================\n\n");
    
    printf("Cartas:\n");
    printf("Carta 1: %s\n", nomePais1);
    printf("Carta 2: %s\n\n", nomePais2);

    // Comparação do Atributo 1 (Uso de Operador Ternário)
    printf("--- Atributo 1: %s ---\n", nome_attr1);
    printf("%s: %.2f\n", nomePais1, valor1_carta1);
    printf("%s: %.2f\n", nomePais2, valor1_carta2);
    
    // Regra da Densidade (Menor vence), outros (Maior vence) aplicados no Operador Ternário
    int vencedor_attr1;
    if (escolha1 == 5) {
        vencedor_attr1 = (valor1_carta1 < valor1_carta2) ? 1 : (valor1_carta1 > valor1_carta2) ? 2 : 0;
    } else {
        vencedor_attr1 = (valor1_carta1 > valor1_carta2) ? 1 : (valor1_carta1 < valor1_carta2) ? 2 : 0;
    }
    printf("Vencedor (%s): %s\n\n", nome_attr1, (vencedor_attr1 == 1) ? nomePais1 : (vencedor_attr1 == 2) ? nomePais2 : "Empate");

    // Comparação do Atributo 2
    printf("--- Atributo 2: %s ---\n", nome_attr2);
    printf("%s: %.2f\n", nomePais1, valor2_carta1);
    printf("%s: %.2f\n", nomePais2, valor2_carta2);
    
    int vencedor_attr2;
    if (escolha2 == 5) {
        vencedor_attr2 = (valor2_carta1 < valor2_carta2) ? 1 : (valor2_carta1 > valor2_carta2) ? 2 : 0;
    } else {
        vencedor_attr2 = (valor2_carta1 > valor2_carta2) ? 1 : (valor2_carta1 < valor2_carta2) ? 2 : 0;
    }
    printf("Vencedor (%s): %s\n\n", nome_attr2, (vencedor_attr2 == 1) ? nomePais1 : (vencedor_attr2 == 2) ? nomePais2 : "Empate");

    // SOMA DOS ATRIBUTOS E VENCEDOR FINAL
    printf("--- SOMA DOS ATRIBUTOS ---\n");
    printf("%s: %.2f\n", nomePais1, soma_carta1);
    printf("%s: %.2f\n", nomePais2, soma_carta2);

    // Comparação final para a soma
    printf("\n>>> RESULTADO FINAL <<<\n");
    if (soma_carta1 > soma_carta2) {
        printf("A carta 1 (%s) VENCEU o jogo!\n", nomePais1);
    } else if (soma_carta2 > soma_carta1) {
        printf("A carta 2 (%s) VENCEU o jogo!\n", nomePais2);
    } else {
        printf("O jogo terminou em EMPATE!\n");
    }
    printf("========================================\n");

    return 0;
}
