class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     int n=nums.size();
     int cnt=0;
     unordered_map<int,int>mp;
     mp[0]=1;
    int prefix_sum=0;
    for(int i=0;i<n;i++){
        prefix_sum+=nums[i];

        if(mp.find(prefix_sum-k)!=mp.end()){
            cnt+=mp[prefix_sum-k];
        }
        mp[prefix_sum]++;
    }
     return cnt;
    }
};