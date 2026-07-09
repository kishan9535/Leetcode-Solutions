class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<bool>ans;
        vector<int>comp(n,-1);
        comp[0]=0;
        int cmpid=0;

        for(int i=1;i<n;i++){
          if(nums[i]-nums[i-1]>maxDiff){
            cmpid++;
          }
          comp[i]=cmpid;
        }

        for(auto &it:queries){
            int u=it[0];
            int v=it[1];

            if(comp[u]==comp[v]){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans; 
    }
};