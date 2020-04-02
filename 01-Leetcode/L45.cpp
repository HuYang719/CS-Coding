class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size());
        int N = nums.size()-1;
        for(int i = 0; i < N; i++){
            int farest = min(N, nums[i]+i);
            for(int j = farest; j > i; j--){
                if(dp[j] != 0) break;
                if(dp[j] == 0)
                    dp[j] = dp[i] + 1;
                // else dp[j] = min(dp[j], dp[i]+1);
            }
        }
        return dp[N];
        
    }
};