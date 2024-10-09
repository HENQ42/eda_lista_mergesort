#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct {
    int matricula;
    char nome[15];      // 14 caracteres + caractere nulo utilizado para indicar o fim de uma string
    char telefone[11];
} Aluno;

Aluno lista[MAX];
int tamanho = 0;

void inserir();
void remover();
void consultar();
void listar();
void mergeSort(Aluno arr[], int left, int right);
void merge(Aluno arr[], int left, int mid, int right);

int main() {
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Consultar\n");
        printf("4 - Listar\n");
        printf("5 - Terminar\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserir();
                break;
            case 2:
                remover();
                break;
            case 3:
                consultar();
                break;
            case 4:
                listar();
                break;
            case 5:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 5);

    return 0;
}

void inserir() {
    if (tamanho >= MAX) {
        printf("Lista cheia.\n");
        return;
    }

    Aluno novo;
    printf("Digite o número de matrícula: ");
    scanf("%d", &novo.matricula);
    getchar();  // Limpar o buffer

    printf("Digite o nome: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';  // Remover o '\n'

    printf("Digite o telefone: ");
    fgets(novo.telefone, sizeof(novo.telefone), stdin);
    novo.telefone[strcspn(novo.telefone, "\n")] = '\0';

    lista[tamanho] = novo;
    tamanho++;

    // Ordenar a lista após a inserção
    mergeSort(lista, 0, tamanho - 1);

    printf("Aluno inserido com sucesso.\n");
}

void remover() {
    if (tamanho == 0) {
        printf("Lista vazia.\n");
        return;
    }

    int matricula_remover;
    printf("Digite o número de matrícula do aluno a ser removido: ");
    scanf("%d", &matricula_remover);

    int pos = -1;
    for (int i = 0; i < tamanho; i++) {
        if (lista[i].matricula == matricula_remover) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Matrícula não encontrada.\n");
        return;
    }

    for (int i = pos; i < tamanho - 1; i++) {
        lista[i] = lista[i + 1];
    }
    tamanho--;

    printf("Aluno removido com sucesso.\n");
}

void consultar() {
    if (tamanho == 0) {
        printf("Lista vazia.\n");
        return;
    }

    int matricula_consultar;
    printf("Digite o número de matrícula do aluno a ser consultado: ");
    scanf("%d", &matricula_consultar);

    for (int i = 0; i < tamanho; i++) {
        if (lista[i].matricula == matricula_consultar) {
            printf("\nAluno encontrado:\n");
            printf("Matrícula: %d\n", lista[i].matricula);
            printf("Nome: %s\n", lista[i].nome);
            printf("Telefone: %s\n", lista[i].telefone);
            return;
        }
    }

    printf("Matrícula não encontrada.\n");
}

void listar() {
    if (tamanho == 0) {
        printf("Lista vazia.\n");
        return;
    }

    printf("\nListagem de alunos:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Matrícula: %d\n", lista[i].matricula);
        printf("Nome: %s\n", lista[i].nome);
        printf("Telefone: %s\n", lista[i].telefone);
        printf("-------------------------\n");
    }
}

void merge(Aluno arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Aluno L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Mescla as sublistas em ordem
    while (i < n1 && j < n2) {
        if (L[i].matricula <= R[j].matricula) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Aluno arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Mescla as metades ordenadas
        merge(arr, left, mid, right);
    }
}
