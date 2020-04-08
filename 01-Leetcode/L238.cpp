class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left, right(nums.size());
        left.push_back(1);
        right[nums.size()-1]=1;
        int ans_l = 1;
        int ans_r = 1;
        for(auto n: nums){
            ans_l *= n;
            left.push_back(ans_l);
        }
        left.pop_back();
        for(int i = nums.size()-1; i >= 0; i--) {
            left[i] = left[i]*ans_r;
            ans_r *= nums[i]; 
        }
      
      
        return left;
        
    }
};