class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        if(A.size() < L+M)
            return 0;
        vector<int> preSum = A;
        for(int i = 1; i < A.size(); i++) {
            preSum[i] += preSum[i-1];
        }
        int res = preSum[L+M-1];
        int maxL = preSum[L-1];
        int maxM = preSum[M-1];
        
        for(int i = L+M; i < A.size(); i++) {
            maxL = max(maxL, preSum[i-M] - preSum[i-M-L]);
            maxM = max(maxM, preSum[i-L]-preSum[i-M-L]);
            res = max(res, max(maxL + preSum[i] - preSum[i-M], maxM + preSum[i] - preSum[i-L]));
        }
        return res;
        
    }
};