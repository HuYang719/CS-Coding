class Solution {
public:
    bool canTransform(string start, string end) {
        int i = 0, j = 0;
        int N = start.length();
        while(i < N && j < N){
            while(i < N && start[i]=='X') i++;
            while(j < N && end[j] == 'X') j++;
            if(start[i] != end[j]) return false;
            if((start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)) return false;
            i++;
            j++;
        }
        return true;
        
    }
};
