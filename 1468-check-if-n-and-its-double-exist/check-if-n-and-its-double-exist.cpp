class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
         set<int>st;
         for(auto it: arr){
            if((st.find(it/2)!=st.end()&& it%2==0) || st.find(it*2)!=st.end()){
                return true;
            }
            st.insert(it);
         }
         return false;
        
    }
};