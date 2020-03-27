class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> elements;
        for(auto num:nums)
            elements[num] = false;
        
        int left = 0, right = 0;
        int max_len = nums.empty() ? 0 : 1;
        int curr_len = 0;
        for(auto it = elements.begin(); it != elements.end(); it++) {
            curr_len = 0;
            if(!elements[it->first]) {
                curr_len += 1;
                left = it->first -1;
                right = it->first + 1;
                auto left_it = elements.find(left);
                auto right_it = elements.find(right);
                
                while(left_it != elements.end() || right_it != elements.end()) {
                    if(left_it != elements.end()) {
                        elements[left] = true;
                        --left;
                        curr_len += 1;
                        left_it = elements.find(left);
                    }
                    
                    if(right_it != elements.end()) {
                        elements[right] = true;
                        ++right;
                        curr_len += 1;
                        right_it = elements.find(right);
                    }
                }
                max_len = max(max_len, curr_len);
            }
        }
        return max_len;
    
    }
};