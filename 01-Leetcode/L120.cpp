class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int Rows = triangle.size();
        int Cols_i = 2;
        if(Rows == 1)
            return triangle[0][0];
        
        for(int i = 1; i < Rows; i++){
            for(int j = 0; j <= i; j++){
                if(j == 0)
                    triangle[i][0] += triangle[i-1][0];
                else if(j == i)
                    triangle[i][j] += triangle[i-1][i-1];
                else
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i <= Rows-1; i++){
            ans = min(ans, triangle[Rows-1][i]);
        }
        return ans;
        
    }
};