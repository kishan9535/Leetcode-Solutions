class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        set<int>st;

        for(auto &it:nums){
            st.insert(it);
        }

        int i=1;

        while(1){
            if(st.find(i*k)!=st.end()){
                i++;

            }
            else{
                return i*k;
            }
        }
        return k;
    }
};