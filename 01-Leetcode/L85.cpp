class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int N = matrix.size();
        if(N == 0) return 0;
        int M = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(N, vector<int>(M));
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < M; j++) {
                if(matrix[i][j] == '1')
                    dp[i][j] = j == 0? 1: dp[i][j-1]+1;
                int width = dp[i][j];
                for(int k = i; k >= 0; k--) {
                    width = min(width, dp[k][j]);// 所有情况中的最小值
                    ans = max(ans, width*(i-k+1));
                }
            }
        }
        return ans;
        
    }
};