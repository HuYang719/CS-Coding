class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> ans_i;
        dfs(ans_i, candidates, 0, target);
        return ans;
    }
    
    void dfs(vector<int>& ans_i, const vector<int>& candidates, int level, int target){
        if(target == 0) {
            ans.push_back(ans_i);
            return;
        }
        for(int i = level; i < candidates.size(); i++){
            if(candidates[i] > target)
                break;
            ans_i.push_back(candidates[i]);
            dfs(ans_i, candidates, i, target-candidates[i]);
            ans_i.pop_back();
        }
        return;
    }
};