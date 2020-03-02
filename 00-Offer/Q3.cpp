
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
int R, C;
string str_std = "";
int dx[] = {1, 0, -1, 0};

int dy[] = {0, 1, 0, -1};

bool visited[10000][10000];

class Solution {
public:
    bool dfs(char* matrix, int row, int col, string* cur_s) {
        if(row<0 || row >= R || col < 0 || col >= C || (*cur_s).length() > str_std.length() || visited[row][col] == true)
            return false;
        if((*cur_s).length() == str_std.length()) {
            if(*cur_s == str_std)
                return true;
            else return false;
        }

        // *cur_s.length() < str_std.length()
        (*cur_s) += matrix[row*C+col];
        visited[row][col] = true;
        bool ans  = false;
        for(int i = 0; i < 4; i++){
        	bool ans_tmp = dfs(matrix, row+dx[i], col+dy[i], cur_s);
        	// printf("now[%d][%d]=%c, cur_s=%s\n",row+dx[i],col+dy[i],matrix[(row+dx[i])*C+(col+dy[i])], (*cur_s).c_str());
            if( ans_tmp == true) {
                ans = true;
                break;
            }

        }
        return ans;
    }

    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix == nullptr || str == nullptr)
            return false;
        if(rows <= 0 || cols <= 0)
            return false;
        cout<<"1";

        bool ans = false;
        R = rows;
        C = cols;
        int i = 0;
        while(str[i] != '\0') {
            str_std += str[i];
            i++;
        }
        cout<<"2";

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                string cur_s = "";
                bool ans_tmp = dfs(matrix, i, j, &cur_s);
               
                if( ans_tmp== true) {
                    ans = true;
                    break;
                }
            }
        }

        return ans;
    }


};

int main(){
	
    Solution sol;
    char matrix[16] = {'a','b','c','e','s','f','c','s','a','d','e','e','b','c','a','a'};
    char str[] = "bcced";

    bool res = sol.hasPath(matrix, 4, 4, str);
    cout<<"ans:"<<res<<endl;
    getchar();
    return 0;
    
}


// 复杂度分析
// O(2^n)