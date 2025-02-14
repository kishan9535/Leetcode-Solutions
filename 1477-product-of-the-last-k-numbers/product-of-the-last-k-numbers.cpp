class ProductOfNumbers {
public:
     vector<int> prefixes;
    int size;
    ProductOfNumbers() {
       prefixes.push_back(1);
        size = 0;  
    }
    
    void add(int num) {
         if (num == 0) {
            prefixes.clear();
            prefixes.push_back(1);
            size = 0;
        } else {
            prefixes.push_back(prefixes[size] * num);
            size++;
        }
    }
    
    int getProduct(int k) {
       if (k > size) {
            return 0;
        }

        return prefixes[size] / prefixes[size - k]; 
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */