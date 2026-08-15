class ProductOfNumbers {
private:
    std::vector<int> v;

public:
    ProductOfNumbers() 
    {}
    
    void add(int num) 
    {
        v.push_back(num);
    }
    
    int getProduct(int k) 
    {
        int idx = v.size()-1, cnt = 1;
        int res = 1;
        while (cnt <= k)
        {
            res *= v[idx--];
            cnt++;
        }
        return res;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */