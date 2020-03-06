int N, M;
// int dx[] = {1, 0, -1, 0};
// int dy[] = {0, 1, 0, -1};
bool visited[51][51];
class Solution {
public:
    
    int dfs(vector<vector<int>>& grid, int row, int col) {
       if(row < 0 || row >= N || col < 0 || col >= M ||visited[row][col]==true|| grid[row][col] == 0)
           return 0;
        visited[row][col] = true;
        
        // int ans = 1;
        // for(int i = 0; i < 4; i++) {
        //     ans += dfs(grid, row+dx[i], col+dy[i]);
        //     cout<<ans<<endl;
        // }
        return (1+dfs(grid, row+1, col)+dfs(grid, row-1, col)+dfs(grid, row, col+1)+dfs(grid, row, col-1));
       
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();
        memset(visited, 0 ,sizeof(visited));
       
        int ans = 0;
        for(int r = 0; r < N; r++) {
            for(int c = 0; c < M; c++) {
                ans = max(ans, dfs(grid, r,c));
            }
        }
        return ans;
        
        
    }
};

// Time space O(R*C)