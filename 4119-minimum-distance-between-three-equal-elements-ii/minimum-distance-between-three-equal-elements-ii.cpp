class Solution {
public:
    int minimumDistance(vector<int>& nums) {
      
      int ans=INT_MAX;
      unordered_map<int,vector<int>>mp;
      int n=nums.size();

      for(int k=0;k<n;k++){
        mp[nums[k]].push_back(k);

        if(mp[nums[k]].size()>=3){
            vector<int>&vec=mp[nums[k]];
            int s=vec.size();
            int i=vec[s-3];
            ans=min(ans,2*(k-i));
        }
      }
      return (ans==INT_MAX?-1:ans);  
    }
};