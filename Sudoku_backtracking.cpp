#include <iostream>

using namespace std;

#define N 9

// int row = 0;
// int col = 0;
bool findUnassigned(int grid[N][N], int& row, int& col) {
    for(row = 0; row < N; ++row) {
        for(col = 0; col < N; ++col) {
            if(grid[row][col] == 0) return true;
        }
    }
    return false;
}

bool okay(int grid[N][N], int row, int col, int val);

bool solve(int grid[N][N]) {
    int row = 0;
    int col = 0;
    if(!findUnassigned(grid, row, col)) return true; 
        for(int k = 1; k <= 9; ++k) {
            if(okay(grid, row, col, k)) {
                grid[row][col] = k;
                if(solve(grid)) return true;
                grid[row][col] = 0;
            }
        }
    return false;
}

bool usedInRow(int grid[N][N], int val, int row) {
    for(int i = 0; i < N; ++i) {
        if(val == grid[row][i]) return true;
    }
    return false;
}

bool usedInCol(int grid[N][N], int val, int col) {
    for(int i = 0; i < N; ++i) {
        if(val == grid[i][col]) return true;
    }
    return false;
}

bool usedInSub(int grid[N][N], int val, int row, int col) {
    for(int i = (row/3)*3; i < (row/3)*3 + 3; ++i) {
        for(int j = (col/3)*3; j < (col/3)*3 + 3; ++j) {
            if(grid[i][j] == val) return true;
        } 
    }
    return false;
}

bool okay(int grid[N][N], int row, int col, int val) {
    if(val < 1 || val > 9) return false;
    if(usedInRow(grid, val, row)) return false;
    if(usedInCol(grid, val, col)) return false;
    if(usedInSub(grid, val, row, col)) return false;
    return true;
}
void print(int grid[N][N]) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cout << grid[i][j] << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
                      {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
                      {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
                      {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
                      {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
                      {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                      {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
                      {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    if(solve(grid)) print(grid); 
    else cout << "No solution exists. " << endl;
    return 0;
}
