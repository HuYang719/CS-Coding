int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
class Solution {
public:
    bool dfs(vector<vector<char>>& board, int index, string word, int row, int col){
        // printf("row = %d, col=%d, index=%d\n", row, col,index);
        if(index >= word.size()) return true;
        
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index])
            return false;
        board[row][col] = '#';
        for(int i = 0; i < 4; i++) {
            if(dfs(board, index+1, word, row+dx[i], col+dy[i]))
                return true;
        }
        board[row][col] = word[index];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int N = board.size();
        if(N == 0) return false;
        int M = board[0].size();
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                // printf("In i=%d, j=%d\n", i, j);
                if(dfs(board, 0, word, i, j))
                    return true;
            }
        }
        return false;
        
        
    }
};