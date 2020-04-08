class Solution {
public:
    int calnums(vector<int> nums, int target) {
        auto it = upper_bound(nums.begin(),nums.end(),target);
        return it-nums.begin();
    }
    int getK(vector<int> nums1, vector<int> nums2, int k) {
        int l = -1e9;
        int r = 1e9;
        while(l<r){
            int mid = l + (r-l)/2;
            int s1 = calnums(nums1, mid);
            int s2 = calnums(nums2, mid);
            // printf("s1=%d, s2=%d, mid=%d\n", s1, s2, mid);
            if(s1+s2 >= k)
                r = mid;
            else l = mid + 1;
        }
        // printf("k=%d,r=%d\n",k,r);
        return r;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = (nums1.size() + nums2.size());
 
        int k1,k2;
        double ans = 0;
        if(sum % 2 == 0) {
            k1 = sum/2;
            k2 = k1+1;
            ans = double(getK(nums1,nums2,k1) +  getK(nums1,nums2,k2))/2;
        }else{
            k1 = sum/2+1;
            ans =getK(nums1,nums2,k1);
        }
       return ans;
        
    }
};