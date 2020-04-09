class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int a = 0;
        int b = 0;
        int x = tomatoSlices;
        int y = cheeseSlices;
        int judge1 = x -2*y;
        int judge2 = 4*y - x;
        if(judge1 < 0 || judge1%2 !=0 || judge2 < 0 || judge2%2 != 0)
            return {};
        a = judge1/2;
        b = judge2/2;
        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);
        return ans;
        
    }
};