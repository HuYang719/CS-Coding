class Solution {
public:
    int judge(vector<int> array, int threshold, int row) {
        int left = 0;
        int right = left+row-1;
        int sum = 0;
        int ans = 0;
        for(int k = 1; k < array.size(); k++){
            array[k] += array[k-1];
        }
        while( right < array.size()) {
           if(left == 0){
               sum = array[right];
           }else sum = array[right] - array[left-1];
           if(sum <= threshold){
               ans = max(ans, row);
                // printf("ans = %d\n",ans);
               break;
           }else{
               left++;
               right++;
           }
        }
        return ans;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int ans = 0;
        int N = mat.size();
        if(N == 0)
            return 0;
        int M = mat[0].size();
        vector<int> array(N);
       
        for(int left = 0; left < M;left++) {
            vector<int> array(N);
            for(int right = left; right < M; right++) {
                for(int i = 0; i < N; i++) {
                    array[i] += mat[i][right];
                }
                // printf("left = %d, right=%d,ans=%d\n",left,right,ans);
                ans = max(ans,judge(array, threshold, right-left+1));
                // printf("left = %d, right=%d,ans=%d\n",left,right,ans);
            }
                
        }
        return ans;
    }
};