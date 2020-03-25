class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        deque<pair<int, int>> tmp;
        vector<pair<int, int>> tmp1;
        vector<int> res(deck.size());
        for(int i = 0; i < deck.size(); i++) {
            tmp.push_back({deck[i], i});
        }
        while(!tmp.empty()){
            auto it = tmp.front();
            tmp.pop_front();
            tmp1.push_back(it);
            if(!tmp.empty()){
                tmp.push_back(tmp.front());
                tmp.pop_front();
            }
        }
        for(int i = 0; i < tmp1.size(); i++){
            int index = tmp1[i].second;
            res[index] = deck[i];
        }
        return res;
        
        
    }
};