class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<=2) return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() -2; i++){
            if(i == 0 ||(i>0&&nums[i] != nums[i-1])){
                int left = i+1;
                int right = nums.size()-1;
                while(left<right){
                    int tmp = nums[left] + nums[right] + nums[i];
                    if(tmp == 0){
                        ans.push_back({nums[i], nums[left], nums[right]});
                        while(left<right && nums[left] == nums[left+1]) left++;
                        while(left<right && nums[right] == nums[right-1]) right--;
                        left++;
                        right--;
                    }else if(tmp > 0){
                        right--;
                    }else {
                        left++;
                    }
                }
            }
           
        }
     
        return ans;
        
        
    }
};

