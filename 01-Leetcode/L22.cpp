class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(ans, "", 0, 0, n);
        return ans;
    }
    void dfs(vector<string>& ans, string cur, int open, int close, int maxsize) {
        if(cur.size() == maxsize*2) {
            ans.push_back(cur);
            return;
        }
        
        if(open < maxsize)
            dfs(ans, cur+"(", open+1, close, maxsize);
        if(close < open && close < maxsize)
            dfs(ans, cur+")", open, close+1, maxsize);
    }
};