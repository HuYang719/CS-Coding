class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int a,b;
        int ca = 0;
        int cb = 0;
         
        for (int i=0;i<nums.size();i++){
            if (nums[i] == a || ca == 0 && nums[i] != b){
                a = nums[i];
                ca += 1;
            }else if(nums[i] == b  || cb == 0){
                b = nums[i];
                cb += 1;
            }else{
                ca --;
                cb --;
            }
        }
         
        printf("a=%d, b=%d\n", a, b);
        ca = 0;
        cb = 0;
        for (int i=0;i<nums.size();i++){
            if (nums[i] == a){ ++ca; }
            else if (nums[i] == b){ ++cb; }
        }
         
        if (ca > floor(nums.size()/3) ){ res.push_back(a);}
        if (cb > floor(nums.size()/3)){ res.push_back(b);}
         
        return res;
        
    }
};