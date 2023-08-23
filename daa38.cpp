#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define N 4 // Number of workers and tasks

int costMatrix[N][N] = {
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}
};

int minCost = INT_MAX;

bool isAssigned(int assignment[N], int task) {
    for (int i = 0; i < N; i++) {
        if (assignment[i] == task)
            return true;
    }
    return false;
}

void branchAndBound(int assignment[N], int worker, int cost) {
    if (worker == N) {
        if (cost < minCost)
            minCost = cost;
        return;
    }
    
    for (int task = 0; task < N; task++) {
        if (!isAssigned(assignment, task)) {
            int newCost = cost + costMatrix[worker][task];
            if (newCost < minCost) {
                assignment[worker] = task;
                branchAndBound(assignment, worker + 1, newCost);
                assignment[worker] = -1;
            }
        }
    }
}

int main() {
    int assignment[N];
    for (int i = 0; i < N; i++)
        assignment[i] = -1;

    branchAndBound(assignment, 0, 0);

    printf("Optimal Assignment:\n");
    for (int i = 0; i < N; i++)
        printf("Worker %d -> Task %d\n", i, assignment[i]);

    printf("Minimum Cost: %d\n", minCost);

    return 0;
}

