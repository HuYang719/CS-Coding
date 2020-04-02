class Solution {
public:
    int dfs(const vector<int>& arr,int start, int ans, vector<bool>& visited){
        if(start >= arr.size() || start < 0 || visited[start]==true)
            return 0;
        if(arr[start] == 0)
            ans++;
        visited[start] = true;
        int left = dfs(arr, start-arr[start], ans, visited);
        int right = dfs(arr, start+arr[start], ans, visited);
        return ans + left + right;
        
    }
    bool canReach(vector<int>& arr, int start) {
        int N = arr.size();
        vector<bool>visited(N);
        int com_0 = dfs(arr, start, 0, visited);
        return com_0>=1;
        
        
    }
};