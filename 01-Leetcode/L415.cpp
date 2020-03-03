//Error: forgot if the last add = 1
class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        if(len1 == 0 && len2 == 0)
            return "";
        
        string ans = "";
        int add = 0;
        int i = 0;
        
        for(; i < min(len1, len2); i++) {
            int x1 = num1[len1-1-i] - '0';
            int x2 = num2[len2-1-i] - '0';
            int x = x1 + x2 + add;
            if(x>=10) {
                x = x - 10;
                add = 1;
            }else add = 0;
            ans += x+'0';
        }
        
        if(len1 != len2 && len1 > len2) {
            for(; i < len1; i++){
                int x = num1[len1-1-i] - '0' + add;
                if(x >= 10) {
                    x = x-10;
                    add = 1;
                }else add = 0;
                ans += x+'0';
            }
        }else if(len1 != len2 && len1 < len2) {
             for(; i < len2; i++){
                int x = num2[len2-1-i] - '0' + add;
                if(x >= 10) {
                    x = x-10;
                    add = 1;
                }else add = 0;
                ans += x+'0';
            }
            
        }
        
        if(add == 1)
            ans += '1';
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};