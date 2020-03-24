class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size() == 0) return res;
        sort(intervals.begin(), intervals.end());
        vector<int> inter_tmp = intervals[0];
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][0] <= inter_tmp[1]){
                inter_tmp[1] = max(inter_tmp[1], intervals[i][1]); 
            }else{
                res.push_back(inter_tmp);
                inter_tmp = intervals[i];
            }
        }
        //最后一个没有来得及进行比较，或者比较之后还没来得及放进去
        res.push_back(inter_tmp);
        return res;
        
    }
};