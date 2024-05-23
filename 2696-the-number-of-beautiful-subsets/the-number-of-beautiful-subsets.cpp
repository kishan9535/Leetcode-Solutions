class Solution {
public:
int ans=0;
int K;
    void solve(vector<int>&nums,int idx,unordered_map<int,int>&mp){
        if(idx>=nums.size()){
            ans++;
            return;
        }
        solve(nums,idx+1,mp);

         if(!mp[nums[idx] - K] && !mp[nums[idx] + K]) {
                mp[nums[idx]]++;
                solve(nums, idx + 1, mp);
                mp[nums[idx]]--;
        }
        return;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
      K=k;
      unordered_map<int,int>mp;
      solve(nums,0,mp);
      return ans-1;  
    }
};