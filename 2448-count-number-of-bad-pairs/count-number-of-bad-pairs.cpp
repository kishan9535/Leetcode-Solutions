class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
      long long ans=0;
      vector<int>temp;
      int n=nums.size();
      for(int i=0;i<n;i++){
        temp.push_back(nums[i]-i);
      }
      unordered_map<int,int>mp;
      mp[nums[0]]++;
      for(int i=1;i<n;i++){
         int num_cnt=mp[temp[i]];
         ans+=(i-num_cnt);
         mp[temp[i]]++;
      }
      return ans;  
    }
};