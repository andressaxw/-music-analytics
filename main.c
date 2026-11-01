
#include <stdio.h>

typedef struct {
    char nome[30];
    int reproducoes;
} Musica;

// Funcao para exibir as musicas
void exibirMusicas(Musica musicas[], int tamanho) {
    int i;

    for (i = 0; i < tamanho; i++) {
        printf("%s: %d reproducoes\n",
               musicas[i].nome,
               musicas[i].reproducoes);
    }
}

// Funcao para ordenar as musicas
void ordenarMusicas(Musica musicas[], int tamanho, int crescente) {
    int i, j;
    Musica temporaria;

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - 1 - i; j++) {

            if ((crescente == 1 &&
                 musicas[j].reproducoes > musicas[j + 1].reproducoes) ||
                (crescente == 0 &&
                 musicas[j].reproducoes < musicas[j + 1].reproducoes)) {

                temporaria = musicas[j];
                musicas[j] = musicas[j + 1];
                musicas[j + 1] = temporaria;
            }
        }
    }
}

int main() {

    Musica original[10] = {
        {"Musica 1", 1500},
        {"Musica 2", 2300},
        {"Musica 3", 1800},
        {"Musica 4", 4500},
        {"Musica 5", 3200},
        {"Musica 6", 900},
        {"Musica 7", 5100},
        {"Musica 8", 2700},
        {"Musica 9", 3900},
        {"Musica 10", 1200}
    };

    Musica crescente[10];
    Musica decrescente[10];

    int i;

    // Copiando os dados originais
    for (i = 0; i < 10; i++) {
        crescente[i] = original[i];
        decrescente[i] = original[i];
    }

    printf("\n===== MUSIC ANALYTICS =====\n");

    printf("\nAUDIENCIA ORIGINAL:\n");
    exibirMusicas(original, 10);

    ordenarMusicas(crescente, 10, 1);

    printf("\nRANKING CRESCENTE:\n");
    exibirMusicas(crescente, 10);

    ordenarMusicas(decrescente, 10, 0);

    printf("\nRANKING DECRESCENTE:\n");
    exibirMusicas(decrescente, 10);

    printf("\nFim do Music Analytics!\n");

    return 0;
}

