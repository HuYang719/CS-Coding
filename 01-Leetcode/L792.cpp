class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int size = S.length();
        int next[size+1][26];
        int ans = 0;
        int pos = 0;
        memset(next, -1, sizeof(next));
        for(int i = S.length()-1; i >= 0; i--){
            for(int j = 0; j < 26; j++){
                if(S[i]-'a' == j){
                    next[i][j] = i+1; 
                }else next[i][j] = next[i+1][j];
            }
        }
   
        for(auto w:words){
            pos = 0;
            bool isSub = true;
            for(int i = 0; i < w.length(); i++) {
                if(next[pos][w[i]-'a'] != -1){
                    auto it = next[pos][w[i]-'a'];
                    pos = it;
                }else{
                    isSub = false;
                    break;
                }
            }
            if(isSub == true) ans++;
        }
        return ans;
    }
};