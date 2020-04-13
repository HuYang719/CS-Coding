
class ProductOfNumbers {
public:
    vector<int> prod;
    ProductOfNumbers() {  
    }
    
    void add(int num) {
        if(num == 0){
            prod.clear();
            return;
        }
        if(!prod.empty()) prod.push_back(prod.back() * num);  
         else prod.push_back(num);
        
    }
    
    int getProduct(int k) {
        if(prod.size() < k) return 0;
        int sz = prod.size();
        if(sz == k) return prod.back();
        return prod.back()/prod[sz-k-1];
    }
};
    

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */