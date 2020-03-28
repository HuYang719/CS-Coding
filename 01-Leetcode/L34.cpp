class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }
        auto lower = lower_bound(nums.begin() , nums.end(), target);
        auto upper = upper_bound(nums.begin() , nums.end(), target);
        int l = lower != nums.end() && *lower == target ? lower - nums.begin() : -1;
        int r = (upper--) != nums.begin() && *upper == target ? upper - nums.begin() : -1;
        return {l, r};
    }
};