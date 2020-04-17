class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> heights_copy = heights;
        int res = 0;
        sort(heights.begin(), heights.end());
        for(int i = 0; i < heights.size(); i++) {
            if(heights[i] != heights_copy[i])
                res++;
        }
        return res;
    }
};