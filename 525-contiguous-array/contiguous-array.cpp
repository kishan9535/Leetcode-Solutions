class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      int max_ans=0;
      unordered_map<int,int>mp;
      mp[0]=-1;
      int prefix_sum=0;
      int n=nums.size();
      for(int i=0;i<n;i++){
        if(nums[i]==0)prefix_sum-=1;
        else prefix_sum+=1;
        if(mp.find(prefix_sum)!=mp.end()){
            int cnt=i-mp[prefix_sum];
            max_ans=max(cnt,max_ans);
        }
        else{
            mp[prefix_sum]=i;
        }
      }
      return max_ans;  
    }
};