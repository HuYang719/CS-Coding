class Solution {
public:
    vector<int> nums;
    
    void swap(int a, int b) {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
    
    int partition(int left, int right, int pivot_index) {
        int pivot = nums[pivot_index];
        swap(pivot_index, right);
        int store_index = left;
        
        for(int i = left; i <= right; i++) {
            if(nums[i] < pivot) {
                swap(store_index, i);
                store_index++;
            }
        }
        
        swap(store_index, right); //right此时为pivot
        return store_index;
    }
    // right = pivot + store_index, right
    // 
    
    int quickselect(int left, int right, int k_smallest) {
        if (left == right)
            return nums[left];
        int pivot_index = left;
        pivot_index = partition(left, right, pivot_index);
        
        if(k_smallest == pivot_index)
            return nums[k_smallest];
        else if(k_smallest < pivot_index)
            return quickselect(left, pivot_index-1, k_smallest);
        
        return quickselect(pivot_index + 1, right, k_smallest);
    }
    int findKthLargest(vector<int>& nums, int k) {
        this->nums = nums;
        int size = nums.size();
        
        return quickselect(0, size - 1, size-k);
        
    }
};