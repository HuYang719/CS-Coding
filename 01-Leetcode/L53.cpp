class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int cur_max = nums[0];
        int sum_max = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            cur_max = max(nums[i], cur_max+nums[i]);
            sum_max = max(cur_max, sum_max);
        }
        return sum_max;
        
    }
};

// 这道题方法比较巧妙，类似于dp的思想
// 如果已知n[i-1]之前元素的最大部分和，对于当前第n[i]个元素，则最大值为max(n[i-1]+n[i], n[i])
// O(n)时间复杂度
// O(1)空间复杂度
