class Solution {
public:
    int calarray(vector<int> matrix, int target) {
        int sum = 0;
        int res = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for(int i = 0; i < matrix.size(); i++) {
            sum += matrix[i];
            if(m.find(sum-target) != m.end()) {
                res += m[sum-target];
            }
            m[sum]++; //应该是将当前值装入
        }
        return res;
        
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int res = 0;
        if(matrix.size() == 0)
            return res;
        
        for(int l = 0; l < matrix[0].size(); l++) {
            vector<int> array(matrix.size());
            for(int r = l; r < matrix[0].size(); r++) {
                for(int k = 0; k < matrix.size(); k++) {
                    // printf("matrix[%d][%d]=%d\n",k, right)
                    array[k] += matrix[k][r];
                }
                // printf("l=%d,r=%d,val=%d\n", l, r, calarray(array, target));
                res += calarray(array, target);
            }
        }
        return res;
        
    }
};