class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int i = 0;
        int j = 0;
        while(i < A.size() && A[i] < 0){ //runtime error 1 for i < size
            i++;
        }
        j = i;
        i--;
        vector<int> ans;
        while(i>=0 && j < A.size()) {
            if(abs(A[i]) < A[j]) {
                ans.push_back(A[i]*A[i]);
                i--;
            }else{
                ans.push_back(A[j]*A[j]);
                j++;
            }
        }
        
        while(j < A.size()) {
            ans.push_back(A[j]*A[j]);
            j++;
        }
        
        while(i >= 0){
            ans.push_back(A[i]*A[i]);
            i--;
        }
        return ans;
        
    }
};