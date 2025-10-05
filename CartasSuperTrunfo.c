#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para a primeira carta:
struct Carta {
    // Declarando as variáveis da carta:
    char estado[50], cidade[50];
    int pontos_turisticos;
    long int populacao;
    double superPoder, densidade, pib, area, pib_per_capita;
};

double calcularSuperPoder(struct Carta carta);


void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrarCarta(struct Carta *carta) {
    printf("Digite o Estado:\n");
    fgets(carta->estado, sizeof(carta->estado), stdin);
    carta->estado[strcspn(carta->estado, "\n")] = 0; // Remove '\n'

    printf("Digite a Cidade:\n");
    fgets(carta->cidade, sizeof(carta->cidade), stdin);
    carta->cidade[strcspn(carta->cidade, "\n")] = 0; // Remove '\n'

    printf("Digite a quantidade de pontos turísticos:\n");
    scanf("%d", &carta->pontos_turisticos);

    printf("Digite o número de habitantes:\n");
    scanf("%ld", &carta->populacao);

    printf("Digite a área em km²:\n");
    scanf("%lf", &carta->area); // Use %lf para double

    printf("Digite o PIB:\n");
    scanf("%lf", &carta->pib);

    // Limpa o buffer do teclado
    limparBuffer();

    // Cálculos
    if(carta->area > 0) carta->densidade = carta->populacao / carta->area;
    else carta->densidade = 0;

    if(carta->populacao > 0) carta->pib_per_capita = carta->pib / carta->populacao;
    else carta->pib_per_capita = 0;
}

void mostrarCarta(struct Carta carta, int num) {
    printf("\n### DADOS DA %s CARTA ###\n", (num == 1) ? "PRIMEIRA" : "SEGUNDA");
    printf("ESTADO: %s - CIDADE: %s\n", carta.estado, carta.cidade);
    printf("PONTOS TURÍSTICOS: %d\n", carta.pontos_turisticos);
    printf("POPULAÇÃO: %ld\n", carta.populacao);
    printf("ÁREA DA CIDADE: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f\n", carta.pib);
    printf("DENSIDADE POPULACIONAL: %.2f hab/km²\n", carta.densidade);
    printf("PIB PER CAPITA: R$ %.2f\n", carta.pib_per_capita);
    printf("SUPER PODER: %.2f\n", calcularSuperPoder(carta));
    printf("-----------------------------------------------------\n");
}

double calcularSuperPoder(struct Carta carta) {
    return carta.area + carta.pib + carta.densidade + carta.pib_per_capita + 
           (double)carta.pontos_turisticos + (double)carta.populacao;
}

void compararCartas(struct Carta c1, struct Carta c2, int tipo) {
    double v1 = 0, v2 = 0;

    switch(tipo) {
        case 1: v1 = calcularSuperPoder(c1); v2 = calcularSuperPoder(c2); break;
        case 2: v1 = c1.densidade; v2 = c2.densidade; break;
        case 3: v1 = c1.pontos_turisticos; v2 = c2.pontos_turisticos; break;
        case 4: v1 = c1.area; v2 = c2.area; break;
        case 5: v1 = c1.pib; v2 = c2.pib; break;
    }

    printf("Carta 1: %.2f x Carta 2: %.2f\n", v1, v2);

    if (v1 == v2)
        printf("Empate!\n\n");
    else if ((tipo == 2 && v1 < v2) || (tipo != 2 && v1 > v2))
        printf("CARTA 1 VENCEU!\n\n");
    else
        printf("CARTA 2 VENCEU!\n\n");
}


void menu1(){
    printf("\n========== MENU ==========\n");
    printf("1. Cadastrar cartas \n");
    printf("2. Sair do jogo\n");
    printf("=================================\n");
    printf("Opção: ");
}

void menu2(){
    printf("=== MENU DE COMPARAÇÕES ===\n");
    printf("1 - Super Poder\n");
    printf("2 - Densidade Populacional\n");
    printf("3 - Pontos Turísticos\n");
    printf("4 - Área\n");
    printf("5 - PIB\n");
    printf("6 - Voltar ao Menu Principal\n");
    printf("============================\n");
    printf("Escolha uma opção: ");
}

int main () {
    struct Carta carta1, carta2;

    int option;//Para a funçao do-while usada no menu
do{ 
    printf("\n=====================================\n");
    printf("      JOGO DE CARTAS SUPER TRUNFO     \n");
    printf("=====================================\n");
  
    int escolha;//Para a segunda funçao de escolha das comparações
    // Iniciando pelo menu
    menu1();
    if (scanf("%d", &option) != 1) {
    printf("Entrada inválida! Digite um número.\n");
    limparBuffer();
    continue;
}

    limparBuffer();

    switch(option){
        case 1:
            
            // Cadastrando os dados da primeira carta
            printf("\nCadastrando a primeira carta:\n");
            cadastrarCarta(&carta1);

           
            // Exibição dos dados da primeira carta
            mostrarCarta(carta1, 1);    


            printf("\nCadastrando a segunda carta:\n");
            cadastrarCarta(&carta2);

            
            // Exibição dos dados da segunda carta
            mostrarCarta(carta2, 2);
            
        do {
            mostrarCarta(carta1, 1);
            mostrarCarta(carta2, 2);
            menu2();
            if (scanf("%d", &escolha) != 1) {
            printf("Entrada inválida! Digite um número.\n");
            limparBuffer();
            continue;
            }
            limparBuffer();
            printf("\n");

            if (escolha >= 1 && escolha <= 5) {
                compararCartas(carta1, carta2, escolha);
            } else if (escolha == 6) {
                printf("Voltando ao menu...\n\n");
            } else {
                printf("Opção inválida!\n\n");
            }
        } while (escolha != 6);

         
        break;
        case 2:
            printf("Saindo do jogo...\n");
            printf("\n");
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
    }       printf("\n");
        
} while (option != 2); 


    return 0;
}
