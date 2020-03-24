class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int sum = 0;
        unordered_map<int, int> m;
        m[0] = 1; // 注意{0, 1}表示不减去任何值时是否相等
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(m.find(sum - k) != m.end())
                res += m[sum-k];
            m[sum]++;
        }
        return res;
        
    }
};