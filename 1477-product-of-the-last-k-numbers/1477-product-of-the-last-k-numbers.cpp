class ProductOfNumbers {
public:
    vector<int> v;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        for(int i = 0; i < v.size(); i++)
        v[i] = v[i]*num;
        v.push_back(num);
    }
    
    int getProduct(int k) {
        return v[v.size() - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */