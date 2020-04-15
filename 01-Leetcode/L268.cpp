class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expectedsum = (nums.size())*(nums.size()+1)/2;
        int actsum = 0;
        for(auto num:nums)
            actsum += num;
        return expectedsum - actsum;
        
    }
};