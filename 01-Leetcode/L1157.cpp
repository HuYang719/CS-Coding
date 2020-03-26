class MajorityChecker {
    public:
    unordered_map<int, vector<int>> pos;
    vector<int> seg;
    vector<int> arr;
    int seg_size;
    int n;
    
    int nextPower_2( unsigned int x) {
        int  value = 1 ;
        while( value <= x) {
            value = value << 1;
        }
        return value;
    }
    
    int get_occurrence(int num, int l, int r) {
        auto iter = pos.find(num);
        if (iter == pos.end()) {
            return 0;
        }
        auto& vec = iter->second;
        auto iter_l = lower_bound(vec.begin(), vec.end(), l);
        if (iter_l == vec.end()) {
            return 0;
        }
        auto iter_r = upper_bound(vec.begin(), vec.end(), r);
        return iter_r - iter_l;
    }
    
    void buildTree(int pos, int low, int high) {
        if(low == high){
            seg[pos] = arr[high];
            return;
        }
        int mid = (low + high)/2;
        buildTree(2*pos+1, low, mid);
        buildTree(2*pos+2, mid+1, high);
        
        if(seg[2*pos + 1] != -1 && get_occurrence(seg[2*pos + 1], low, high) * 2 > high - low + 1)
            seg[pos] = seg[2*pos + 1];
         if(seg[2*pos + 2] != -1 && get_occurrence(seg[2*pos + 2], low, high) * 2 > high - low + 1)
            seg[pos] = seg[2*pos + 2];
    }
    
    pair<int, int> rangeMinQuery(int low, int high, int qLow, int qHigh, int pos) {
        if(qLow <= low && qHigh >= high) {
            int count = get_occurrence(seg[pos], qLow, qHigh);
            if (count * 2 > qHigh - qLow + 1) {
                return make_pair(seg[pos], count);
            }
            else {
                return make_pair(-1, -1);
            }
        }     
        if(qLow > high || qHigh < low)
            return {-1, -1};
        int mid = (low + high)/2;
        pair<int,int> l =  rangeMinQuery(low, mid, qLow, qHigh, 2*pos+1);
        pair<int,int> r = rangeMinQuery(mid+1, high, qLow, qHigh, 2*pos+2);
        if(l.first != -1) return l;
        if(r.first != -1) return r;
        return {-1, -1};
    }   
    
    MajorityChecker(vector<int>& a) {
        n = a.size();
        for (int i = 0; i < a.size(); ++i) {
            pos[a[i]].push_back(i);
            arr.push_back(a[i]);
        }
        seg_size = nextPower_2(n);
        seg = vector<int>(2 * seg_size - 1, -1);
        buildTree(0, 0, n - 1);
    }
    

    
    int query(int left, int right, int threshold) {
        pair<int, int> temp = rangeMinQuery(0, n-1, left, right, 0);
        if(temp.second >= threshold) return temp.first;
        return -1;
    }
};