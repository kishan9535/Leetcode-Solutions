class Solution {
public:
    int dp[20001][3];
    int solve(vector<int>&nums , vector<int>&pre , int k , int ind , int cnt){
        if(cnt == 3)return 0;
        if(ind >= nums.size()){
            return INT_MIN;
        }
        if(dp[ind][cnt] != -1)return dp[ind][cnt];
        int c1 = 0 , c2 = 0;
        c1 = solve(nums , pre , k , ind+1 , cnt);
        if(ind + k <= nums.size()){
           c2 = pre[ind+k] - pre[ind] + solve(nums , pre , k , ind+k , cnt+1);
        }
        return dp[ind][cnt] = max(c1 , c2);
    }
    void solve2(vector<int>&nums , vector<int>&pre , int k , int ind , int cnt , vector<int>&ans){
        if(cnt == 3)return;
        if(ind >= nums.size())return;
        int c1 = 0 , c2 = 0;
        c1 = solve(nums , pre , k , ind+1 , cnt);
        if(ind + k <= nums.size()){
           c2 = pre[ind+k] - pre[ind] + solve(nums , pre , k , ind+k , cnt+1);
        }
        if(c2 >= c1){
            ans.push_back(ind);
            solve2(nums , pre , k , ind+k , cnt+1 , ans);
        }
        else{
            solve2(nums , pre , k , ind+1 , cnt , ans);
        }
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        memset(dp , -1 , sizeof(dp));
        vector<int>pre(n+1 , 0);
        pre[1] = nums[0];
        for(int i = 1 ; i<n ; i++){
            pre[i+1] = pre[i] + nums[i];
        }
        int mx = solve(nums , pre , k , 0 , 0);
        vector<int>ans;
        solve2(nums , pre , k , 0 , 0 , ans);
        return ans;
    }
};