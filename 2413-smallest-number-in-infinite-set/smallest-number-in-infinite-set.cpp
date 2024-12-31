class SmallestInfiniteSet {
public:
   set<int>st;
    SmallestInfiniteSet() {
      
     for(int i=1;i<=1000;i++){
       st.insert(i);
      }    
    }
    
    int popSmallest() {
        auto it=st.begin();
        int val=*it;
        st.erase(it);
       return val;
    }
    
    void addBack(int num) {
       if(st.find(num)!=st.end())return;

       st.insert(num); 
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */