class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        vector<int>ans;
        set<int>st;
        int maxi=0;
        int mini=100;

       for(auto &it:nums){
        maxi=max(maxi,it);
        mini=min(mini,it);

        st.insert(it);
       }

       for(int i=mini;i<=maxi;i++){
          if(st.find(i)==st.end()){
            ans.push_back(i);
          }
       }

       return ans;

    }
};