class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        dfs(nums, path, 0);
        return res;
    }
    
    void dfs(const vector<int>& nums, vector<int>& path, int level) {
        if(level == nums.size()) {
            res.push_back(path);
            return;
        }
        path.push_back(nums[level]);
        dfs(nums, path, level+1);
        path.pop_back();
        dfs(nums, path, level+1);
    }
};