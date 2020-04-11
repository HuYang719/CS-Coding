class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int left = 0;
        int right = 0;
        vector<string> res;
        bool single = false;
        if(nums.size() == 0) return {};
        while(left < nums.size()-1){
            string ans;
            if(nums[left] != nums[left+1]-1) {
                ans = to_string(nums[left]);
                res.push_back(ans);
                left++;
                single = true;
            }else{
                int t = left;
                while(left < nums.size()-1 && nums[left] == nums[left+1]-1)
                    left++;
                ans = to_string(nums[t])+"->"+to_string(nums[left]);
                res.push_back(ans);
                single = false;
                left++;
            }
        }
      // cout<<left<<endl;
     
      if(left != nums.size())
        res.push_back(to_string(nums.back()));
      return res;
    }
};