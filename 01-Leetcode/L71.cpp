class Solution {
public:
    string simplifyPath(string path) {
        vector<string> s;
        string ans;
        int N = path.length();
        int i = 0;
        while(i < N) {
            // cout<<"1:i="<<i<<endl;
            while(path[i] =='/'&& i < N) i++;
            // 也可能是直接到最后了，直接break
            if(i >= N) break;
            int start = i;
            while(path[i] != '/' && i < N) i++;
            int end = i-1;
            string tmp = path.substr(start, end-start+1);
            // cout<<"2:i="<<i<<endl;
            // cout<<tmp<<endl;
            if(tmp == "..") 
            {
                // cout<<"True"<<endl;
                if(!s.empty())//error1:注意判断是否为空
                    s.pop_back();
            }
                 
            else if(tmp != "." )
                s.push_back(tmp);
        }
        
        if(s.empty()) return "/";
        for(auto i:s){
            ans += '/'+i;
        }
        return ans;
        
    }
};