int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    int N, M;
class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int row, int col, int step){
        if(row < 0 || row >= N || col < 0 || col >= M || rooms[row][col] == -1)
            return;
        
        // do not recalculate
        if(step <= rooms[row][col]) {
            rooms[row][col] = step;
            for(int i = 0; i < 4; i++){
                dfs(rooms, row+dx[i], col+dy[i], step+1);
            }
        }
        
        
    }
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.size() == 0)
            return ;
        N = rooms.size();
        M = rooms[0].size();
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(rooms[i][j] == 0)
                    dfs(rooms, i, j, 0);
            }
        }
        
    }
};