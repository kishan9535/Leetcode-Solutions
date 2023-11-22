class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
     vector<int>ans;
     unordered_map<int,vector<int>>mp;
     int col=nums.size();
     for(int c=col-1;c>=0;c--){
         for(int r=0;r<nums[c].size();r++){
              int d=c+r;
              mp[d].push_back(nums[c][r]);
         }
     }
     int i=0;
     while(mp.find(i)!=mp.end()){
         for(auto a:mp[i]){
             ans.push_back(a);
         }
         i++;
     }   
     return ans;
    }
};