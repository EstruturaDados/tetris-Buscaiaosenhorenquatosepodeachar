#include <stdio.h>

// Desafio Tetris Stack
// Tema 3 - Integração de Fila e Pilha
// Este código inicial serve como base para o desenvolvimento do sistema de controle de peças.
// Use as instruções de cada nível para desenvolver o desafio.

int main() {

    // 🧩 Nível Novato: Fila de Peças Futuras
    //
    // - Crie uma struct Peca com os campos: tipo (char) e id (int).
    // - Implemente uma fila circular com capacidade para 5 peças.
    // - Crie funções como inicializarFila(), enqueue(), dequeue(), filaCheia(), filaVazia().
    // - Cada peça deve ser gerada automaticamente com um tipo aleatório e id sequencial.
    // - Exiba a fila após cada ação com uma função mostrarFila().
    // - Use um menu com opções como:
    //      1 - Jogar peça (remover da frente)
    //      0 - Sair
    // - A cada remoção, insira uma nova peça ao final da fila.



    // 🧠 Nível Aventureiro: Adição da Pilha de Reserva
    //
    // - Implemente uma pilha linear com capacidade para 3 peças.
    // - Crie funções como inicializarPilha(), push(), pop(), pilhaCheia(), pilhaVazia().
    // - Permita enviar uma peça da fila para a pilha (reserva).
    // - Crie um menu com opção:
    //      2 - Enviar peça da fila para a reserva (pilha)
    //      3 - Usar peça da reserva (remover do topo da pilha)
    // - Exiba a pilha junto com a fila após cada ação com mostrarPilha().
    // - Mantenha a fila sempre com 5 peças (repondo com gerarPeca()).


    // 🔄 Nível Mestre: Integração Estratégica entre Fila e Pilha
    //
    // - Implemente interações avançadas entre as estruturas:
    //      4 - Trocar a peça da frente da fila com o topo da pilha
    //      5 - Trocar os 3 primeiros da fila com as 3 peças da pilha
    // - Para a opção 4:
    //      Verifique se a fila não está vazia e a pilha tem ao menos 1 peça.
    //      Troque os elementos diretamente nos arrays.
    // - Para a opção 5:
    //      Verifique se a pilha tem exatamente 3 peças e a fila ao menos 3.
    //      Use a lógica de índice circular para acessar os primeiros da fila.
    // - Sempre valide as condições antes da troca e informe mensagens claras ao usuário.
    // - Use funções auxiliares, se quiser, para modularizar a lógica de troca.
    // - O menu deve ficar assim:
    //      4 - Trocar peça da frente com topo da pilha
    //      5 - Trocar 3 primeiros da fila com os 3 da pilha

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Estrutura da fila
typedef struct {
    char pecas[MAX];  // Armazena tipos: 'I', 'O', 'T', 'L'
    int frente;
    int tras;
    int tamanho;
} Fila;

// Inicializa a fila
void inicializarFila(Fila *f) {
    f->frente = 0;
    f->tras = -1;
    f->tamanho = 0;
}

// Verifica se fila está vazia
int filaVazia(Fila *f) {
    return f->tamanho == 0;
}

// Verifica se fila está cheia
int filaCheia(Fila *f) {
    return f->tamanho == MAX;
}

// Insere peça no final
void enfileirar(Fila *f, char tipo) {
    if (filaCheia(f)) {
        printf("Fila cheia! Não é possível adicionar mais peças.\n");
        return;
    }
    f->tras = (f->tras + 1) % MAX;
    f->pecas[f->tras] = tipo;
    f->tamanho++;
}

// Remove peça da frente
char desenfileirar(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia! Não há peça para jogar.\n");
        return '\0';
    }
    char removido = f->pecas[f->frente];
    f->frente = (f->frente + 1) % MAX;
    f->tamanho--;
    return removido;
}

// Mostra a fila atual
void mostrarFila(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Peças na fila: ");
    int i, idx = f->frente;
    for (i = 0; i < f->tamanho; i++) {
        printf("[%c] ", f->pecas[idx]);
        idx = (idx + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    int opcao;
    char tipo;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Visualizar fila\n");
        printf("2. Jogar peça (remover da frente)\n");
        printf("3. Adicionar nova peça ao final\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                mostrarFila(&fila);
                break;
            case 2: {
                char removido = desenfileirar(&fila);
                if (removido != '\0') {
                    printf("Peça jogada: %c\n", removido);
                }
                break;
            }
            case 3:
                printf("Digite o tipo da peça (I, O, T, L): ");
                scanf(" %c", &tipo);
                enfileirar(&fila, tipo);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}

