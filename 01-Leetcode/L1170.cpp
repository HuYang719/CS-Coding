//TS:O(nlogn)
class Solution {
public:
    int func_f(string s){
        map<int, int> m;
        for(auto c:s){
            m[c-'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(m[i] != 0) 
                return m[i];
        }
        return 0;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> v;
        vector<int> res;
        for(auto W:words){
            v.push_back(func_f(W));
        }
        sort(v.begin(), v.end());
        for(auto q:queries){
            int fq = func_f(q);
            auto it = upper_bound(v.begin(), v.end(), fq);
            if(it == v.end())
                res.push_back(0);
            else res.push_back(v.end() - it);
        }
        return res;
    }
};