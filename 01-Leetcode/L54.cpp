int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
class Solution {

   
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dir = 0;
        int n = matrix.size();
        if(n == 0)
            return vector<int>();
        int m = matrix[0].size();
        vector<int> res;
        int row = 0, col = 0;
        
        for(int x = 0; x <m*n; x++) {
            // printf("row=%d, col=%d\n",row,col);
            if(row<n&&row>=0&&col<m&&col>=0&&matrix[row][col] != INT_MAX){
                 res.push_back(matrix[row][col]);
                 matrix[row][col] = INT_MAX;
            }
            int trow = row + dx[dir];
            int tcol = col + dy[dir];
            if(trow>=n||trow<0||tcol>=m||tcol<0||matrix[trow][tcol]==INT_MAX){
                dir++;
                if(dir == 4) dir = 0;
            }
            row += dx[dir];
            col += dy[dir];
        }
        return res;
        
    }
};