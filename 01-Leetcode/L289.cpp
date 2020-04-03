class Solution {
public:
    int calculate(const vector<vector<int>>& board, int row, int col) {
        int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
        int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
        int ans = 0;
        for(int i = 0; i < 8; i++) {
            int cur_row = row + dx[i];
            int cur_col = col + dy[i];
            if(cur_row >= 0 && cur_row < board.size() && cur_col >= 0 && cur_col < board[0].size() && (board[cur_row][cur_col] == 1 || board[cur_row][cur_col] == -1))
                ans++;
        }
        return ans;
    }
    void gameOfLife(vector<vector<int>>& board) {
       vector<vector<int>> tmp = board;
       for(int i = 0; i < board.size(); i++) {
           for(int j = 0; j < board[0].size(); j++) {
               int ans = calculate(board, i, j);
               if((ans < 2 || ans >3) && board[i][j] == 1)
                    board[i][j] = -1;
               if(board[i][j] == 0 && ans == 3)
                    board[i][j] = 2;
           }
       }
      for(int i = 0; i < board.size(); i++) {
          for(int j = 0; j < board[0].size(); j++) {
              if(board[i][j] == -1) board[i][j] = 0;
              if(board[i][j] == 2) board[i][j] = 1;
          }
      }
        
    }
};