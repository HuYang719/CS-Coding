class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int Rows = grid.size();
        int Cols = grid[0].size();
        vector<vector<int> > dp(Rows, vector<int>(Cols, 0));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < Rows; i++){
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        
        for(int i = 1; i < Cols; i++){
            dp[0][i] = grid[0][i] + dp[0][i-1];
        }
        
        for(int i = 1; i < Rows; i++){
            for(int j = 1; j < Cols; j++){
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[Rows-1][Cols-1];
    }
};