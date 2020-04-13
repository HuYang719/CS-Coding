class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        bool ans = true;
        int N = matrix.size();
        int M = matrix[0].size();
        // rows
        for(int i = 0; i < M; i++) {
            int comp = matrix[0][i];
            for(int j = 1; j<N && i+j<M;j++) {
                if(matrix[j][i+j] != comp){
                    ans = false;
                    break;
                }
            }
        }
        
        // columns
        for(int i = 1; i < N; i++) {
            int comp = matrix[i][0];
            for(int j = 1,k=i+1; j < M&& k<N; j++, k++) {
                if(matrix[k][j] != comp) {
                    ans = false;
                    break;
                }
            }
        }
        return ans;
        
    }
};