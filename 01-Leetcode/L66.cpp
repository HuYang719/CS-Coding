class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int N = digits.size();
        
        for(int idx = N-1; idx>=0; idx--) {
            if(digits[idx] == 9)
                digits[idx] = 0;
            else {
                digits[idx]++;
                return digits;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
        
    }
};