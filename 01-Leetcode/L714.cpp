class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int d = prices.size();
        int dp[d][2];
        memset(dp, 0, sizeof(dp));
        dp[0][1] = -prices[0];
        
        for(int i = 0; i < prices.size(); i++){
            if(i-1 == -1) {
                dp[i][0] = 0;
                dp[i][1] =  -prices[0];
                continue;
            }
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]-fee); //sell
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
        }
        
        return dp[d-1][0];
    }
};