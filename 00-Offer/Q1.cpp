#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
class Solution_dp {
public:
    int cutRope(int number) {
        int dp[number+1];
        memset(dp, 0, sizeof(dp));
        if(number==2)
            return 1;
        else if(number==3)
            return 2;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i = 4; i<=number; i++){
            for(int j = 1; j < i; j++){
                dp[i] = max(dp[j]*(i-j),dp[i]);
            }
        }
        return dp[number];
        
    }
};

class Solution_greedy {
public:
    int cutRope(int number) {
        int n3 = number/3;
        int n2 = (number-n3*3)/2;
        int ans = 1;
        if(number == 2)
            return 1;
        else if(number == 3)
            return 2;
        else if(number == 4)
            return 4;
        for(int i = 1;i <=n3; i++) {
            ans *= 3;
        }
        
        for(int i = 1; i <= n2; i++){
            ans *= 2;
        }
        return ans;
        
    }
};

int main(){
	
    Solution_dp sol_dp;
    Solution_greedy sol_gd;
    int ans = sol_gd.cutRope(8);
    cout<<"ans:"<<ans<<endl;
    getchar();
    return 0;
    
}

// 复杂度分析
// dp方法的复杂度为O(n)
// greedy方法复杂度为O(logn)