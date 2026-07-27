#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas (Nível Aventureiro)

int main() {
    // Variáveis para a Carta 1
    char nomeA[50];
    int populacaoA, turisticosA;
    float areaA, pibA, densidadeA;

    // Variáveis para a Carta 2
    char nomeB[50];
    int populacaoB, turisticosB;
    float areaB, pibB, densidadeB;

    // --- Cadastro das Cartas ---
    
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Nome do pais: ");
    scanf(" %49[^\n]", nomeA); // Lê a string com espaços
    printf("Populacao: ");
    scanf("%d", &populacaoA);
    printf("Area (km2): ");
    scanf("%f", &areaA);
    printf("PIB: ");
    scanf("%f", &pibA);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &turisticosA);
    
    // Cálculo da densidade demográfica (Carta 1)
    densidadeA = populacaoA / areaA;

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Nome do pais: ");
    scanf(" %49[^\n]", nomeB);
    printf("Populacao: ");
    scanf("%d", &populacaoB);
    printf("Area (km2): ");
    scanf("%f", &areaB);
    printf("PIB: ");
    scanf("%f", &pibB);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &turisticosB);
    
    // Cálculo da densidade demográfica (Carta 2)
    densidadeB = populacaoB / areaB;

    // --- Menu Interativo ---
    int opcao;
    printf("\n==================================\n");
    printf("   MENU DE COMBATE - SUPER TRUNFO   \n");
    printf("==================================\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Pontos Turisticos\n");
    printf("5. Densidade Demografica (Menor vence!)\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    printf("\n--- RESULTADO DA BATALHA ---\n");

    // --- Comparação de Cartas com Switch e If-Else ---
    switch (opcao) {
        case 1: // POPULAÇÃO
            printf("Atributo: Populacao\n");
            printf("%s: %d\n", nomeA, populacaoA);
            printf("%s: %d\n", nomeB, populacaoB);
            
            if (populacaoA > populacaoB) {
                printf("Vencedor: %s!\n", nomeA);
            } else if (populacaoB > populacaoA) {
                printf("Vencedor: %s!\n", nomeB);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2: // ÁREA
            printf("Atributo: Area\n");
            printf("%s: %.2f km2\n", nomeA, areaA);
            printf("%s: %.2f km2\n", nomeB, areaB);
            
            if (areaA > areaB) {
                printf("Vencedor: %s!\n", nomeA);
            } else if (areaB > areaA) {
                printf("Vencedor: %s!\n", nomeB);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2f\n", nomeA, pibA);
            printf("%s: %.2f\n", nomeB, pibB);
            
            if (pibA > pibB) {
                printf("Vencedor: %s!\n", nomeA);
            } else if (pibB > pibA) {
                printf("Vencedor: %s!\n", nomeB);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // PONTOS TURÍSTICOS
            printf("Atributo: Pontos Turisticos\n");
            printf("%s: %d\n", nomeA, turisticosA);
            printf("%s: %d\n", nomeB, turisticosB);
            
            if (turisticosA > turisticosB) {
                printf("Vencedor: %s!\n", nomeA);
            } else if (turisticosB > turisticosA) {
                printf("Vencedor: %s!\n", nomeB);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5: // DENSIDADE DEMOGRÁFICA (REGRA INVERTIDA)
            printf("Atributo: Densidade Demografica\n");
            printf("%s: %.2f hab/km2\n", nomeA, densidadeA);
            printf("%s: %.2f hab/km2\n", nomeB, densidadeB);
            
            // Note que aqui o sinal é de MENOR (<), pois a menor densidade vence
            if (densidadeA < densidadeB) {
                printf("Vencedor: %s!\n", nomeA);
            } else if (densidadeB < densidadeA) {
                printf("Vencedor: %s!\n", nomeB);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default: // TRATAMENTO DE ERRO (Opção inválida)
            printf("Erro: Opcao invalida! Escolha um numero de 1 a 5.\n");
            break;
    }

    return 0;
}
