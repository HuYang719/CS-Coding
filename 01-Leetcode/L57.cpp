class Solution {
public:
    int findend(vector<vector<int>>& intervals, int &i, vector<int>& newInterval){
        int end_val = newInterval[1];
        for(; i < intervals.size(); i++){
            // printf("In i= %d\n", i);
            if(end_val >= intervals[i][0] && end_val >= intervals[i][1])
                continue;
            else if (end_val < intervals[i][0]){
                  // printf("R-1 i= %d\n", i);
                 return end_val;
            }
            else if(end_val < intervals[i][1]){
                // printf("R-2 i= %d\n", i);
                return intervals[i][1];
            }
              
        }
        return end_val; // > the last one; 
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int pre = 0;
        int i = 0;
        bool has_push = false;
        for(; i < intervals.size(); i++) {
            if(intervals[i][0] < newInterval[0] && intervals[i][1] < newInterval[0]) {
                res.push_back(intervals[i]);
            } else if (intervals[i][0] <= newInterval[0] && newInterval[0] <= intervals[i][1]) {
                int front = intervals[i][0];
                int end = findend(intervals, i, newInterval);
                // cout<<"i="<<i<<endl;
                if(end ==  newInterval[1])
                    res.push_back({front, end});
                else{
                    res.push_back({front, end});
                    i++;
                }
                has_push = true;
                // cout<<"1-i="<<i<<endl;
                break;
            } else if (newInterval[0] < intervals[i][0]){
                int front = newInterval[0];
                int  end = findend(intervals, i, newInterval);
                if(end == newInterval[1])
                    res.push_back({front, end});
                else{
                    res.push_back({front, end});
                    i++;
                }
                has_push = true;
                // cout<<"2-i="<<i<<endl;
                break;
            }
        }
     for(; i < intervals.size(); i++) {
         res.push_back(intervals[i]);
     }
    
     if(has_push == false)
          res.push_back(newInterval);
        return res;
    }
};