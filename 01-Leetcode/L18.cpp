class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        for(int fix1=0;fix1<int(nums.size()-3);fix1++){
            for(int fix2=fix1+1;fix2<int(nums.size()-2);fix2++){
                int l=fix2+1,r=int(nums.size()-1);
                while(l<r){
                    if((nums[l]+nums[r]+nums[fix1]+nums[fix2])==target){
                        vector<int> ansi;
                        ansi.push_back(nums[fix1]);
                        ansi.push_back(nums[fix2]);
                        ansi.push_back(nums[l]);
                        ansi.push_back(nums[r]);
                        ans.push_back(ansi);
                        while(l<r&&nums[l+1]==nums[l]) l++;
                        while(l<r&&nums[r-1]==nums[r]) r--;
                        l++;
                        r--;
                        
                    }else if((nums[l]+nums[r]+nums[fix1]+nums[fix2])<target){
                        l++;
                    }else{
                        r--;
                    }
                }
                while(fix2<int(nums.size()-3)&&nums[fix2+1]==nums[fix2]) fix2++;
            }
            while(fix1<int(nums.size()-4)&&nums[fix1+1]==nums[fix1]) fix1++;
        }
        return ans;
    }
};