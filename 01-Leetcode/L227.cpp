class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int num = 0;
        char sign = '+';
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(isdigit(c))
                num = num*10 + (c -'0');
            if((!isdigit(c) && c!=' ')|| i == s.size()-1){ //处理前面的情况
                int x;
                switch(sign){
                    case '+':
                        stk.push(num);break;
                    case '-':
                        stk.push(-num);break;
                    case '*':
                        x = stk.top()*num;
                        stk.pop();
                        stk.push(x);
                        break;
                    case '/':
                        x = stk.top()/num;
                        stk.pop();
                        stk.push(x);
                        break;
                }
                sign = c; //开始下一轮
                num = 0;
            }
        }
        // 将栈中所有结果求和就是答案
        int res = 0;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;

        
    }
};