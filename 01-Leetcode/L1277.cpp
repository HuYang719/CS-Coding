class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i < m; i++){
            dp[i][0] = matrix[i][0];
        }
        
        for(int j = 0; j < n; j++){
            dp[0][j] = matrix[0][j];
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0)
                    continue;
                else
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans += dp[i][j];
            }
        }
        
        return ans;
    }
};

/********************/
//Error1: 忘记了matrix[i][j] == 0时dp[i][j]直接置0