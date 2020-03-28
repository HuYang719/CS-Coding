// Error1:忘记了全覆盖的情况
// Time space = O(N^2)
class MyCalendar {
public:
    vector<pair<int, int>> calendar;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        bool ans = true;
        for(auto it:calendar){
            if((start >= it.first && start < it.second )||(end>it.first && end <= it.second)||(start<it.first&&end>=it.second)) 
            {
                // printf("F:it.S=%d,it.E=%d,s=%d,e=%d\n",it.first,it.second, start, end);
                ans = false;
                break;
                
             }  
        }
        if(ans == true){
            calendar.push_back({start, end});
            // printf("T:s=%d,e=%d\n",start,end);
        }
           
        return ans;
        
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

class MyCalendar {
public:
    map<int, int> calendar; // end to start
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = calendar.upper_bound(start);
        if(it != calendar.end() && it->second < end)
            return false;
        calendar[end] = start;
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */