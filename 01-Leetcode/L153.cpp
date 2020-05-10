class Solution {
public:
    int findMin(vector<int>& nums) {
       int size =nums.size();
       int left = 0, right = size-1;
        if(nums.size()==1){
            return nums[0];
        }
        if(nums[right]>nums[0]){
            return nums[0];
        }
        while(left < right) {
            int mid = (right + left)/2;
            if(nums[mid] > nums[right]) {
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            } else if (nums[mid] == nums[right]) {
                return nums[right];
            } 
        }
        return nums[left];
        
    }
};


// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int l=0,r=nums.size()-1;
//         if(nums.size()==1){
//             return nums[0];
//         }
//         if(nums[r]>nums[0]){
//             return nums[0];
//         }
//         while(l<r){
//             int mid=(l+r)/2;
//             if(nums[mid]<nums[0]){
//                 r=mid;
//             }else{
//                 l=mid+1;
//             }
//         }
        

//         return nums[l];
//     }
// };