class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        int lower = 0, upper = len - 1;
        
        while(lower < upper){
            int mid = lower + (upper - lower) / 2;
            if(nums[mid] > nums[mid+1]) {
                upper = mid;
            } else {
                lower = mid + 1;
            }
        }
        if(lower == upper && lower != len) return lower;
        else return -1;
    }
};