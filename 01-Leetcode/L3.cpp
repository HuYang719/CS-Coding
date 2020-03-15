class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> cnt(128);
        int ans = 0;
        int n = s.length();
        for(int i=0, j=0; i<n&&j<n;){
            while(i<n&&!cnt[s[i]]) {
                cnt[s[i]]++;
                i++;
                ans = max(ans, i-j);
            }
            cnt[s[j]]--;
            j++;
        }
        return ans;
        
    }
};