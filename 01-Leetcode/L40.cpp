class Solution {
public:
    std::vector<std::vector<int> > combinationSum2(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > ans;
        std::vector<int> combination;
        set<vector<int>> res;
        combinationSum(candidates, target, res, combination, 0);
        for (auto i:res) {
            ans.push_back(i);
        }
        return ans;
    }
private:
    void combinationSum(std::vector<int> &candidates, int target, std::set<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if (!target) {
            res.insert(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i+1);
            combination.pop_back();
            
        }
    }
};
