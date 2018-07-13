class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row_size = obstacleGrid.size();
        if (row_size == 0) return 0;
        int col_size = obstacleGrid[0].size();
        vector< vector<int> > paths(row_size+1, vector<int>(col_size+1, 0));
        
        paths[0][1] = 1;
        
        for(int i = 1; i <= row_size; ++i) {
            for(int j = 1; j <= col_size; ++j) {
                if(!obstacleGrid[i-1][j-1]) {
                    // paths[i][j] = 1;
                    paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
                }
                
            }
        }
        return paths[row_size][col_size];
    }
};
