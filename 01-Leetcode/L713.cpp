class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start = 0, prod = 1, count = 0;
        for(int end = 0; end < nums.size(); end++) {
            prod *= nums[end];
            while(prod >= k && start <= end) {
                prod = prod / nums[start];
                start++;
            }
            count += end - start + 1;
        }
        return count;
        
    }
};
