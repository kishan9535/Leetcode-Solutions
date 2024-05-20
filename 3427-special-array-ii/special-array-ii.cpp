class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
       int n= nums.size();
       //if(n==1)return {true};
       vector<int>pref(n,0);
       for(int i=1;i<n;i++){
         if(nums[i-1]%2==0 == nums[i]%2==0){
            pref[i]=pref[i-1]+1;
         }
          else {
                pref[i] = pref[i-1];
            }
       }
        int m=queries.size();
       vector<bool>ans(m,true);
      
       for(int i=0;i<m;i++){
        int v=queries[i][1];
        int u=queries[i][0];

        if (u == v) {
                ans[i] = true;
            } else {
                // Check the number of non-special positions in the range
                if (pref[v] - (u > 0 ? pref[u] : 0) > 0) {
                    ans[i] = false;
                }
       }
       }
       return ans;
    }
};