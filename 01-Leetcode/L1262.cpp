class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        int m1_fir = 10001, m1_sec = 10001, m2_fir = 10001, m2_sec = 10001;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(nums[i] % 3 == 1) {
                if(nums[i] < m1_fir) {
                    m1_sec = m1_fir;
                    m1_fir = nums[i];
                } else if(nums[i] < m1_sec) {
                     m1_sec = nums[i];
                }
            }
            
            if(nums[i] % 3 == 2) {
                if(nums[i] < m2_fir) {
                    m2_sec = m2_fir;
                    m2_fir = nums[i];
                } else if(nums[i] < m2_sec) {
                    m2_sec = nums[i];
                }
            }
        }
        if(sum % 3 == 0) return sum;
        else if(sum % 3 == 1) return sum - min(m1_fir, m2_fir+m2_sec);
        else return sum-min(m2_fir, m1_fir+m1_sec);
        
    }
};