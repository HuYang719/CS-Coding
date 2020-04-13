class Solution {
public:
    //nums: distance <= value
    int calculate(const vector<int>& nums, int value) {
        int ans = 0;
        int j = 1;
        for(int i = 0; i < nums.size()-1; i++) {
            while(j < nums.size() && nums[j] - nums[i] <= value){
                j++;
            }
            ans += j - i -1;
        }
        return ans;
        
        
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> v;
        int l = 0;
        int r = 1000000;
        // for(int i = 0; i < nums.size()-1; i++) {
        //     for(int j = i+1; j < nums.size(); j++) {
        //         v.push_back(abs(nums[j]-nums[i]));
        //     }
        // }
        
    
        sort(nums.begin(), nums.end());
        while(l<r) {
            int mid = l + (r-l)/2;
            int ans = calculate(nums, mid);
            if(ans >= k)
                r = mid ;
            else l = mid + 1;
        }
        return r;
        
    }
};