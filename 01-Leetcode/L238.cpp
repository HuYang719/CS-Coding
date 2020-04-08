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
        for(int i = nums.size()-2; i >= 0; i--) {
            ans_r *= nums[i+1]; 
            right[i] = ans_r;
        }
      
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = left[i]*right[i];
        }
        return nums;
        
    }
};