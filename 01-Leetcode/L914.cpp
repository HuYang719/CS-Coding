
class Solution {
public:
    int gcd(int x, int y) {
        if(x == 0)
            return y;
        else return gcd(y%x, x);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        int count[10000];
        memset(count, 0, sizeof(count));
        for(auto d:deck) {
            count[d]++;
        }
        int g = -1;
        for(int i = 0; i < 10000; i++){
            if(count[i] > 0){
                if(g == -1)
                    g = count[i];
                else
                    g = gcd(g, count[i]);
                // printf("g=%d\n",g);
            }
          
        }
        return g >= 2;
    }
};


class Solution {
public:
    unordered_map<int,int> m;
    bool hasGroupsSizeX(vector<int>& deck) {
        int minv = INT_MAX;
        for(auto d:deck) {
            m[d]++;
        }
        for(auto it=m.begin(); it != m.end(); it++){
            minv = min(minv, it->second);
        }
        bool exist = false;
        for(int i = 2; i <=minv; i++){
            bool exist_i = true;
           for(auto it=m.begin(); it != m.end(); it++){
                if(it->second % i !=0){
                    exist_i = false;
                    break;
                }  
            }
            exist = exist_i || exist;
        }
       
        return exist;
        
    }
};