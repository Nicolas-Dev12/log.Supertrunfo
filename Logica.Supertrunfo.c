#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
} Carta;

void calcular_densidade(Carta *c) {
    c->densidade = (float)c->populacao / c->area;
}

void exibir_atributo(int escolha) {
    switch (escolha) {
        case 1: printf("População"); break;
        case 2: printf("Área"); break;
        case 3: printf("PIB"); break;
        case 4: printf("Pontos Turísticos"); break;
        case 5: printf("Densidade Demográfica"); break;
    }
}

float obter_valor(Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontos_turisticos;
        case 5: return c.densidade;
        default: return 0;
    }
}

int comparar_atributo(Carta c1, Carta c2, int atributo) {
    float v1 = obter_valor(c1, atributo);
    float v2 = obter_valor(c2, atributo);
    if (atributo == 5)  // Densidade: menor vence
        return v1 < v2 ? 1 : 0;
    else
        return v1 > v2 ? 1 : 0;
}

int main() {
    // Cartas já cadastradas
    Carta c1 = {"Brasil", 214000000, 8515767.0, 1800000.0, 20};
    Carta c2 = {"Japão", 125000000, 377975.0, 5000000.0, 50};

    calcular_densidade(&c1);
    calcular_densidade(&c2);

    int atributo1 = 0, atributo2 = 0;

  
    printf("Escolha o primeiro atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n> ");
    scanf("%d", &atributo1);

    
    printf("\nEscolha o segundo atributo para comparar (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != atributo1) {
            printf("%d - ", i);
            exibir_atributo(i);
            printf("\n");
        }
    }
    printf("> ");
    scanf("%d", &atributo2);

  
    if (atributo1 < 1 || atributo1 > 5 || atributo2 < 1 || atributo2 > 5 || atributo1 == atributo2) {
        printf("\nErro: seleção de atributos inválida!\n");
        return 1;
    }

    float valor1_attr1 = obter_valor(c1, atributo1);
    float valor2_attr1 = obter_valor(c2, atributo1);
    float valor1_attr2 = obter_valor(c1, atributo2);
    float valor2_attr2 = obter_valor(c2, atributo2);

    float soma_c1 = valor1_attr1 + valor1_attr2;
    float soma_c2 = valor2_attr1 + valor2_attr2;

    int resultado_attr1 = comparar_atributo(c1, c2, atributo1);
    int resultado_attr2 = comparar_atributo(c1, c2, atributo2);

    printf("\nComparação entre %s e %s\n", c1.nome, c2.nome);

    printf("\nAtributo 1: ");
    exibir_atributo(atributo1);
    printf("\n%s: %.2f\n", c1.nome, valor1_attr1);
    printf("%s: %.2f\n", c2.nome, valor2_attr1);
    printf("Vencedor: %s\n", resultado_attr1 ? c1.nome : c2.nome);

    printf("\nAtributo 2: ");
    exibir_atributo(atributo2);
    printf("\n%s: %.2f\n", c1.nome, valor1_attr2);
    printf("%s: %.2f\n", c2.nome, valor2_attr2);
    printf("Vencedor: %s\n", resultado_attr2 ? c1.nome : c2.nome);

    printf("\nSoma dos atributos:\n%s: %.2f\n%s: %.2f\n", c1.nome, soma_c1, c2.nome, soma_c2);

   
    printf("\nResultado final: ");
    if (soma_c1 > soma_c2)
        printf("%s venceu a rodada!\n", c1.nome);
    else if (soma_c2 > soma_c1)
        printf("%s venceu a rodada!\n", c2.nome);
    else
        printf("Empate!\n");

    return 0;
}
