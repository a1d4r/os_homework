#include <stdio.h>

#define N_PROCESSES 5
#define N_RESOURCES 3

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    // Read vectors E and A
    int E[N_RESOURCES], A[N_RESOURCES];
    for (int i = 0; i < N_RESOURCES; i++)
        fscanf(input, "%d", &E[i]);
    for (int i = 0; i < N_RESOURCES; i++)
        fscanf(input, "%d", &A[i]);

    // Read matrices C and R
    int C[N_PROCESSES][N_RESOURCES], R[N_PROCESSES][N_RESOURCES];
    for (int i = 0; i < N_PROCESSES; i++)
        for (int j = 0; j < N_RESOURCES; j++)
            fscanf(input, "%d", &C[i][j]);
    for (int i = 0; i < N_PROCESSES; i++)
        for (int j = 0; j < N_RESOURCES; j++)
            fscanf(input, "%d", &R[i][j]);

    // 1 if the process is able to complete
    int F[N_PROCESSES];
    for (int i = 0; i < N_PROCESSES; i++)
        F[i] = 0;

    while (1) {
        // Search for a process P_k with R[k] <= A
        int k = -1;
        for (int i = 0; i < N_PROCESSES; i++) {
            if (!F[i]) {
                int flag = 1;
                for (int j = 0; j < N_RESOURCES; j++)
                    if (R[i][j] > A[j])
                        flag = 0;
                if (flag) {
                    k = i;
                    F[k] = 1;
                    break;
                }
            }
        }
        if (k == -1) // No such process exists
            break;
        else {
            for (int j = 0; j < N_RESOURCES; j++)
                A[j] += C[k][j];
        }
    }

    int n_dl = 0;
    for (int i = 0; i < N_PROCESSES; i++)
        if (!F[i])
            n_dl++;

    if (n_dl == 0)
        fprintf(output, "No deadlock is detected");
    else if (n_dl == 1)
        fprintf(output, "%d process is deadlocked", n_dl);
    else
        fprintf(output, "%d processes are deadlocked", n_dl);
    return 0;
}