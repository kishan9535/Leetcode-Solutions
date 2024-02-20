class Solution {
public:
    int missingNumber(vector<int>& nums) {
     int n=nums.size();
     set<int>st;
     for(auto i:nums){
         st.insert(i);
     }
     for(int i=0;i<=n;i++){
         if(st.find(i)==st.end()){
             return i;
         }
     }
     return -1;   
    }
};