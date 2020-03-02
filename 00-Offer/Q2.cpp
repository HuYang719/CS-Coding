#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
bool visit[10000][10000];
int M, N;
// int ans;

class Solution {
public:
    int calculate(int rows, int cols){
        int ans = 0;
        while(rows != 0) {
            ans += rows%10;
            rows /= 10;
        }

        while(cols != 0) {
            ans += cols%10;
            cols /= 10;
        }

        return ans;
    }


    void dfs(int threshold, int row, int col, int *ans) {
        int cur_val = calculate(row, col);
        if(row >= M || row < 0 || col >= N || col < 0 || visit[row][col] == true||cur_val>threshold){
            return;
        }
        // in
 
        visit[row][col] = true;
        (*ans)++;
        for(int i = 0; i < 4; i++){
              // printf("ans = %d, row:%d+dx[%d]=%d,col%d+dy[%d]=%d\n",*ans, row, i, row+dx[i], col, i, col+dy[i]);
              dfs(threshold, row+dx[i], col+dy[i], ans);

        }
        // visit[row][col] = false;
        return;
      

    }

    int movingCount(int threshold, int rows, int cols)
    {
        
        M = rows;
        N = cols;
        int ans = 0;
        dfs(threshold, 0, 0, &ans);
        return ans;
        
    }
};


int main(){
	
    Solution sol;
    memset(visit, 0, sizeof(visit));
    // ans = 0;
    // int ans = 0;
    int res = sol.movingCount(15,20,20);
    cout<<"ans:"<<res<<endl;
    getchar();
    return 0;
    
}

// 这道题我的ans用了全局变量，每次可以进入的时候，我才会加1，并且dfs函数不返回任何值
// 复杂度分析
// O(2^n)