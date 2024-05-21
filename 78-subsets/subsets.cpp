class Solution {
public:
    void solve(vector<int>& nums,int idx,vector<vector<int>>&ans,vector<int>&temp){
        if(idx>=nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        solve(nums,idx+1,ans,temp);
        temp.pop_back();
        solve(nums,idx+1,ans,temp);
        return ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>>ans;
      vector<int>temp;
      solve(nums,0,ans,temp);
      return ans;  
    }
};