class Solution {
public:
    
    pair<int, int> eval(string s) {
       //  cout << s << endl;
        int len = s.size();
        int res = 0, sign = 1;
        for (int i = 0 ; i < len ; ) {
            if (isspace(s[i])) {
                i ++;
                continue;
            }
            if (i < len && isdigit(s[i])) {
                int num = 0;
                while (i < len && isdigit(s[i])) {
                    num = num * 10 + (s[i ++] - '0');
                }
                res += sign * num;
            }
            while (i < len && isspace(s[i])) {
                ++ i;
            }
            assert(i >= len || s[i] == '+' || s[i] == '-'
                            || s[i] == '(' || s[i] == ')');
            
            if (s[i] == '+' || s[i] == '-') {
                // 2 (+) 5 + 4
                sign = (s[i] == '+') ? 1 : -1;
                i ++;
            } else if (s[i] == '(') {
                string sub_exp = s.substr(i + 1, len - (i + 1));
                pair<int, int> tmp = eval(sub_exp);
                res += tmp.first * sign;
                // i should jump to the next char of ')' matched '(' =>
                // i += the number of steps of i+1 in eval()  
                // 2+(3-4) => eval("3-4)") return {-1. 3}
                //     ^ 
                
                i += tmp.second + 1;
                assert(s[i] == ')');
                ++ i;
            } else { // ')'
                // 1 + 2 + 3)
                // cout << "#" << res << ' ' << i << endl;
                return make_pair(res, i);
            }
        }
        cout << "#" << res << ' ' << -1 << endl;
        return make_pair(res, -1);
    }
    
    int calculate(string s) {
        return eval(s).first;
    }
};
