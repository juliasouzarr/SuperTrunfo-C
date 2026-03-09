#include <stdio.h>
#include <string.h>

// Estrutura para facilitar leitura e armazenamento de dados
struct Carta
{
    char estado;
    char codigo[4];
    char nome[40];
    unsigned long int populacao;
    float area;
    float PIB;
    int pontosTuristicos;
    float densidadePopulacional;
    float PIBPerCapita;
    float superPoder;
};

// Função para ler os dados da carta
void lerCarta(struct Carta *carta, int indice)
{

    printf("\nCidade %i\n", indice + 1);

    // limpa o ENTER deixado pelo scanf anterior
    getchar();
    
    // Nome da cidade
    printf("Digite o nome da cidade: ");
    fgets(carta->nome, sizeof(carta->nome), stdin);
    carta->nome[strcspn(carta->nome, "\n")] = 0;

    // Estado
    printf("Digite o estado (A-H): ");
    scanf(" %c", &carta->estado);

    // Validação do estado
    while ((carta->estado < 'A' || carta->estado > 'H') &&
           (carta->estado < 'a' || carta->estado > 'h'))
    {

        printf("Estado invalido. Digite uma letra de A ate H: ");
        scanf(" %c", &carta->estado);
    }

    // Geração do código da carta formando a string
    sprintf(carta->codigo, "%c%02d", carta->estado, indice + 1);

    // População
    printf("Digite a populacao: ");
    scanf("%lu", &carta->populacao);

    // Área
    printf("Digite a area: ");
    scanf("%f", &carta->area);

    // PIB
    printf("Digite o PIB: ");
    scanf("%f", &carta->PIB);

    // Pontos turísticos
    printf("Digite a quantidade de pontos turisticos: ");
    scanf("%i", &carta->pontosTuristicos);
}

// Função que calcula os atributos derivados
void calcularAtributos(struct Carta *carta)
{
    carta->densidadePopulacional = (float)carta->populacao / carta->area;
    carta->PIBPerCapita = (float)carta->PIB / carta->populacao;
    carta->superPoder =
        carta->populacao +
        carta->area +
        carta->PIB +
        carta->pontosTuristicos +
        carta->PIBPerCapita +
        (1.0 / carta->densidadePopulacional);
}

// Exibe os dados da carta - não precisa de ponteiro porque não altera a carta
void mostrarCarta(struct Carta carta)
{
    printf("\n--- Carta %s ---\n", carta.codigo);
    printf("Cidade: %s\n", carta.nome);
    printf("Estado: %c\n", carta.estado);
    printf("Populacao: %lu\n", carta.populacao);
    printf("Area: %.2f\n", carta.area);
    printf("PIB: %.2f\n", carta.PIB);
    printf("Pontos Turisticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.5f\n", carta.PIBPerCapita);
    printf("Super Poder: %.2f\n", carta.superPoder);
}

// Compara duas cartas e mostra o resultado
void compararCartas(struct Carta c1, struct Carta c2)
{
    printf("\n--- Comparação de Cartas ---\n");

    printf("População: %s venceu\n", c1.populacao > c2.populacao ? "Carta 1" : "Carta 2");

    printf("Área: %s venceu\n", c1.area > c2.area ? "Carta 1" : "Carta 2");

    printf("PIB: %s venceu\n", c1.PIB > c2.PIB ? "Carta 1" : "Carta 2");

    printf("Pontos Turísticos: %s venceu\n", c1.pontosTuristicos > c2.pontosTuristicos ? "Carta 1" : "Carta 2");

    printf("Densidade Populacional: %s venceu\n",
           c1.densidadePopulacional < c2.densidadePopulacional ? "Carta 1" : "Carta 2");

    printf("PIB per Capita: %s venceu\n", c1.PIBPerCapita > c2.PIBPerCapita ? "Carta 1" : "Carta 2");

    printf("Super Poder: %s venceu\n", c1.superPoder > c2.superPoder ? "Carta 1" : "Carta 2");
}


int main()
{
    int i;

    // Vetor de duas cartas
    struct Carta cartas[2];

    for (i = 0; i < 2; i++)
    {
        lerCarta(&cartas[i], i);
        calcularAtributos(&cartas[i]);
    }

    // Mostrar cartas
    for (i = 0; i < 2; i++)
    {
        mostrarCarta(cartas[i]);
    }

    // Comparar cartas
    compararCartas(cartas[0], cartas[1]);

    return 0;
}

