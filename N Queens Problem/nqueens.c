

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int board[MAX], n;

// Function to print the board
void printSolution() {
    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

// Check if placing queen at (row, col) is safe
int isSafe(int row, int col) {
    for (int i = 1; i < row; i++) {
        // Check column and diagonals
        if (board[i] == col || abs(i - row) == abs(board[i] - col))
            return 0;
    }
    return 1;
}

// Recursive function to place queens
void solve(int row) {
    if (row > n) {
        printSolution();
        return;
    }
    for (int col = 1; col <= n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row + 1);
            // backtrack: not needed explicitly as next loop will overwrite
        }
    }
}

int main() {
    printf("Enter number of queens (n <= %d): ", MAX);
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Solutions for %d-Queens:\n\n", n);
    solve(1);

    return 0;
}






