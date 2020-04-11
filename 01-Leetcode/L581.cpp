class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> stack1;
        int l = nums.size();
        int r = 0;
        for(int i = 0; i < nums.size(); i++) {
            while(!stack1.empty() && nums[stack1.top()] > nums[i]){
                 l = min(l, stack1.top());
                 stack1.pop();
            }
          stack1.push(i);     
        }
        stack<int> stack2;
        for(int i = nums.size()-1; i >= 0; i--) {
            while(!stack2.empty() && nums[stack2.top()] < nums[i]) {
                r = max(r, stack2.top());
                stack2.pop();
            }
            stack2.push(i);
        }
        return r-l > 0 ? r-l+1 : 0;
        
    }
};