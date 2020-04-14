class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int first_large = INT_MIN;
        int second_large = INT_MIN;
        int first_index = -1;
        int second_index = -1;
        if(nums.size() == 1) return 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > first_large) {
                second_large = first_large;
                first_large = nums[i];
                second_index = first_index;
                first_index = i;
            } else if(nums[i] > second_large) {
                second_large = nums[i];
                second_index = i;
            }
        }
        // printf("first=%d,index=%d, second=%d,index=%d\n", first_large,first_index, second_large,second_index);
        return first_large >= second_large*2? first_index: -1;
        
        
    }
};