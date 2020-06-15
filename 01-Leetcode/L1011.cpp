calass Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int min_cap = 0;
        int total_w = 0;
        for(auto w:weights) {
            total_w += w;
            min_cap = max(min_cap, w);
        }
        
        while(min_cap <total_w) {
            int mid = min_cap + (total_w - min_cap)/2;
    
            int days = 0;
            int current_w = 0;
            for(auto w:weights) {
                if(current_w + w> mid) {
                    days++;
                    current_w = 0;
                }
                current_w += w;
            }
            days++;
            
           // printf("Days = %d, l=%d, r= %d, mid = %d\n",days, min_cap, total_w, mid);
            if(days > D)
                min_cap = mid + 1;
            else total_w = mid ;
        }
        return min_cap;
        
    }
};