class RandomizedSet {
public:
    unordered_map<int, int> index; // map of num to its index in nums array
    vector<int> nums; // storing the actual numbers inserted
    int size;
    /** Initialize your data structure here. */
    RandomizedSet() {
        size = 0;
        srand (time(NULL));
        
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(index.find(val) != index.end())
            return false;
        
        nums.push_back(val);
        index[val] = size;
        size++;
        return true;
        
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(index.find(val) == index.end())
            return false;
        int back = nums.back();
        int backId = index[back];
        int delId = index[val];
        
        swap(nums[backId], nums[delId]);
        nums.pop_back();
        
        index[back] = delId;
        index.erase(val);
        
        size--;
        return true;
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
         if (size <= 0) return -1; 
        
        /* generate secret number between 0 and size - 1: */
        int randIdx = rand() % size;
        
        return nums[randIdx];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */