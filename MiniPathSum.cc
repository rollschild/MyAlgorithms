class Solution {
public:
 int minPathSum(vector<vector<int>>& grid) {
   if (grid.empty()) return 0;
   int row = grid.size();
   int col = grid[0].size();
   vector<vector<int>> sum(row, vector<int>(col, grid[0][0]));
   for (int i = 1; i < row; ++i) {
     sum[i][0] = sum[i - 1][0] + grid[i][0];
   }
   for (int j = 1; j < col; ++j) {
     sum[0][j] = sum[0][j - 1] + grid[0][j];
   }
   for (int k = 1; k < row; ++k) {
     for (int p = 1; p < col; ++p) {
       sum[k][p] = min(sum[k - 1][p], sum[k][p - 1]) + grid[k][p];
     }
   }
   return sum[row - 1][col - 1];
    }
};
