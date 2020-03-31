class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0, n = arr.size();
        for (int i = 0; i < n; ++i) {
            int cur = arr[i], j = i + 1;
            for (; j <= cur; ++j) {
                cur = max(cur, arr[j]);
            }
            i = j - 1; //运行到后面还会i++，因此先减1保证取值相同
            res++;
        }
        return res;
        
    }
};