
#include <stdio.h>
#include <string.h>
int main() {
    int escolha = -1;

    carregar_fila();

    while (escolha != 0) {
        printf("\n======== MENU ========\n");
        printf("[1] Entrar na fila\n");
        printf("[2] Atender pessoa\n");
        printf("[3] Mostrar fila completa\n");
        printf("[0] Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        if (escolha == 1) {
            entrar_fila();
        } else if (escolha == 2) {
            atender_fila();
        } else if (escolha == 3) {
            mostrar_fila();
        } else if (escolha == 0) {
            printf("Encerrando programa...\n");
        } else {
            printf("Opção inválida!\n");
        }
    }

    salvar_fila(); // salva no txt
    return 0;
}




char fila[10][100];
int tamanho = 0;

void entrar_fila() {
    if (tamanho < 10) {
        char nome[100];
        printf("Informe seu nome: ");
        scanf(" %[^\n]", nome);  // CORREÇÃO AQUI
        strcpy(fila[tamanho], nome);
        tamanho++;
        printf("\n-> %s entrou na fila.\n", nome);
    } else {
        printf("Fila está cheia.\n");
    }
}

void atender_fila() {
    if (tamanho > 0) {
        printf("Atendendo: %s\n", fila[0]);
        for (int cont = 0; cont < tamanho - 1; cont++) {
            strcpy(fila[cont], fila[cont + 1]);
        }
        tamanho--;
    } else {
        printf("Fila vazia.\n");
    }
}

void mostrar_fila() {
    if (tamanho == 0) {
        printf("Fila está vazia.\n");
    } else {
        printf("Pessoas na fila:\n");
        for (int cont = 0; cont < tamanho; cont++) {
            printf("[%d] %s\n", cont + 1, fila[cont]);
        }
    }
}

void salvar_fila() {
    FILE *arquivo = fopen("fila.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao salvar a fila!\n");
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%s\n", fila[i]);
    }

    fclose(arquivo);
    printf("Fila salva com sucesso!\n");
}

void carregar_fila() {
    FILE *arquivo = fopen("fila.txt", "r");
    if (arquivo == NULL) {
        printf("Nenhum arquivo de fila encontrado. Começando vazio.\n");
        return;
    }

    tamanho = 0;
    while (fgets(fila[tamanho], 100, arquivo) != NULL && tamanho < 10) {
        fila[tamanho][strcspn(fila[tamanho], "\n")] = '\0';
        tamanho++;
    }

    fclose(arquivo);
    printf("Fila carregada com sucesso!\n");
}

