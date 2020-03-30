class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int fix=0;
        int closet=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for(;fix<int(nums.size()-2);fix++){
            int l=fix+1,r=int(nums.size()-1);
            while(l<r){
                int closi=nums[fix]+nums[l]+nums[r];
                if(closi<target){
                    if(abs(target-closi)<abs(target-closet)){
                        closet=closi;
                    }
                    l++;
                }else if(closi>target){
                    if(abs(target-closi)<abs(target-closet)){
                        closet=closi;
                    }
                    r--;
                }else{
                    return closi;
                }
                
            }
            
        }
       return closet; 
    }
};