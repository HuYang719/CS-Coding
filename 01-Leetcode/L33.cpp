class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() -1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] >= nums[left]) { //优先判断mid所在位置
              if(target >= nums[left] && target < nums[mid])
                  right = mid -1;
              else left = mid + 1;
            } else if (nums[mid] < nums[left]) {
                if(target <= nums[right] && target > nums[mid]) //注意取等于号
                    left = mid +1;
                else right = mid -1;
            }
        }
        return -1;
        
    }
};