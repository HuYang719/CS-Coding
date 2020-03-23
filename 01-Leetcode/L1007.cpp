class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> o_A(7), t_A(7), o_B(7), t_B(7);
        for(int i = 0; i < A.size(); i++){
            t_A[A[i]]++;
            t_B[B[i]]++;
            if(A[i] == B[i]){
                o_A[A[i]]++;
            }else{
                o_A[A[i]]++;
                o_A[B[i]]++;
            }
        }
        int res = INT_MAX;
        for(int i = 1; i <=6; i++){
            if(o_A[i] == A.size()){
                res = min(o_A[i]-t_A[i], o_A[i]-t_B[i]);
            }
        }
        return res == INT_MAX? -1 : res;
        
        
    }
};


class Solution {
public:
    int check(int x, vector<int> A, vector<int> B){
        int rotation_A = 0;
        int rotation_B = 0;
        for(int i = 0; i < A.size(); i++){
            if(A[i] != x && B[i] != x)
                return -1;
            else if(A[i] != x) rotation_A++;
            else if(B[i] != x) rotation_B++;
        }
        return min(rotation_A, rotation_B);
    }
    
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int rotations = check(A[0], A, B);
        if(rotations != -1) return rotations;
        else return check(B[0], A, B);
        
    }
};