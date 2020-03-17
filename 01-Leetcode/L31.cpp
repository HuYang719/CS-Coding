class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        for (i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] < nums[i+1]) {
                int swap_index = i + 1;
                for (int j = swap_index + 1; j < nums.size(); ++j) {
                    // you must get the last element nums[j] <= nums[swap_index]
                    // to guarantee the list is ordered in descending order in
                    // the interval [i + 1, nums.size()) after the swap
                    if (nums[j] > nums[i] && nums[j] <= nums[swap_index]) {
                        swap_index = j;
                    }
                }
                swap(nums[i], nums[swap_index]);
                break;
            }
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};