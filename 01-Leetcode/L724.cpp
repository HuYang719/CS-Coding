class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        // if(nums.size() == 1) return 0;
        vector<int> preSum(nums.size());
        preSum[0] = nums[0];
        int ans = -1;
        for(int i = 1; i < nums.size(); i++) {
            preSum[i] = preSum[i-1] + nums[i];
        }
        for(int i = 0; i < nums.size(); i++) {
            int left = i == 0? 0:preSum[i-1];
            int right = preSum[nums.size()-1] - preSum[i];
            if(left == right) {
                ans = i;
                break;
            }
        }
        return ans;
        
    }
};