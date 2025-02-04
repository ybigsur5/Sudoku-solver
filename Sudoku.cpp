#include <iostream>
using namespace std;

const int N = 9;

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a number can be placed at a given position
bool canPlaceNumber(int grid[N][N], int row, int col, int num) {
    // Check row
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num) return false;
    }

    // Check column
    for (int i = 0; i < N; i++) {
        if (grid[i][col] == num) return false;
    }

    // Check 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) return false;
        }
    }

    return true;
}

// Function to solve Sudoku using backtracking
bool solveSudoku(int grid[N][N]) {
    int row = -1;
    int col = -1;
    bool isEmpty = true;

    for (int i = 0; i < N && isEmpty; i++) {
        for (int j = 0; j < N && isEmpty; j++) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = false;
            }
        }
    }

    if (isEmpty) return true;

    for (int num = 1; num <= 9; num++) {
        if (canPlaceNumber(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid)) return true;

            grid[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int grid[N][N];

    cout << "Enter the Sudoku puzzle (Enter 0 for empty cells):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    if (solveSudoku(grid)) {
        cout << "Solved Sudoku:\n";
        printGrid(grid);
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}