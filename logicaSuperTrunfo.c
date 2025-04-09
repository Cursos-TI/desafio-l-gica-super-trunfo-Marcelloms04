#include <stdio.h>

int main() {
    // Definindo os paises
    char nomepais1[30] = "Alemanha", nomepais2[30] = "Japao";
    unsigned long populacao1 = 83129285, populacao2 = 125410000;
    double area1 = 357022.0, area2 = 377975.0;
    double pib1 = 4.5, pib2 = 5.1; // PIB em tri
    int pontosTuristicos1 = 20, pontosTuristicos2 = 30;
    // Calculo da densidade e PIB per capita
    double densidadePop1 = populacao1 / area1, densidadePop2 = populacao2 / area2;
    double pibPerCapita1 = (pib1 * 1e12) / populacao1, pibPerCapita2 = (pib2 * 1e12) / populacao2;

    // Vetor para armazenar os valores dos atributos
    double valores1[7] = {populacao1, area1, pib1, pontosTuristicos1, densidadePop1, pibPerCapita1};
    double valores2[7] = {populacao2, area2, pib2, pontosTuristicos2, densidadePop2, pibPerCapita2};
    
    char *nomesAtributos[7] = {"Populaçao", "Area", "PIB", "Pontos Turisticos", 
                                "Densidade Populacional (menor vence)", "PIB Per Capita"};

    int opcao1, opcao2;
    
    // Menu para escolha do primeiro atributo
    printf("\nEscolha o primeiro atributo para comparaçao:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d - %s\n", i + 1, nomesAtributos[i]);
    }
    printf("Opçao: ");
    scanf("%d", &opcao1);
    opcao1--; // Ajustar indice do vetor

    // Menu dinamico para escolha do segundo atributo 
    printf("\nEscolha o segundo atributo para comparaçao:\n");
    for (int i = 0; i < 6; i++) {
        if (i != opcao1) {
            printf("%d - %s\n", i + 1, nomesAtributos[i]);
        }
    }
    printf("Opçao: ");
    scanf("%d", &opcao2);
    opcao2--; // Ajustar para indice do vetor

    // Comparaçao individual 
    int vencedor1 = (opcao1 == 4) ? (valores1[opcao1] < valores2[opcao1]) : (valores1[opcao1] > valores2[opcao1]);
    int vencedor2 = (opcao2 == 4) ? (valores1[opcao2] < valores2[opcao2]) : (valores1[opcao2] > valores2[opcao2]);

    // Soma dos valores atributos
    double soma1 = valores1[opcao1] + valores1[opcao2];
    double soma2 = valores2[opcao1] + valores2[opcao2];

    // Exibiçao do resultado
    printf("\n===== Resultado =====\n");
    printf("%s vs %s\n", nomepais1, nomepais2);
    printf("%s: %.2f vs %.2f\n", nomesAtributos[opcao1], valores1[opcao1], valores2[opcao1]);
    printf("%s: %.2f vs %.2f\n", nomesAtributos[opcao2], valores1[opcao2], valores2[opcao2]);
    printf("Soma dos Atributos: %.2f vs %.2f\n", soma1, soma2);

    // Determinaçâo do vencedor
    if (soma1 > soma2) {
        printf("Vencedor: %s!\n", nomepais1);
    } else if (soma2 > soma1) {
        printf("Vencedor: %s!\n", nomepais2);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
