class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
      vector<vector<int>>ans;
      unordered_map<int,int>mp;
      int n=nums.size();
      for(int i=0;i<n;i++){
          int freq=mp[nums[i]];
          if(ans.size()==freq){
              ans.push_back({});
          }
          ans[freq].push_back(nums[i]);
          mp[nums[i]]++;
      }
      return ans;  
    }
};