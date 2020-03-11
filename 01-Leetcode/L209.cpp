class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int N = nums.size();
        int ans = INT_MAX;
        int left = 0;
        int sum = 0;
        for(int i = 0; i < N; i++) {
            sum += nums[i];
            while(sum >= s){
                ans = min(ans, i-left+1);
                sum -= nums[left];
                left++;
            }
        }
        return (ans != INT_MAX)? ans : 0;
        
    }
};