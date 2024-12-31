class Solution {
public:
    bool ispossible(vector<int>cnt){
        for(int i=1;i<=100;i++){
            if(cnt[i]>1)return false;
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
     vector<int>cnt(101,0);
     for(auto it: nums){
        cnt[it]++;
     }
     if(ispossible(cnt))return 0;
     int ans=0;
     int n=nums.size();
     for(int i=0;i<nums.size();i+=3){
          for(int j=i;j<i+3&&j<n;j++){
            cnt[nums[j]]--;
          }
          ans++;
          if(ispossible(cnt))return ans;
     }
     return ans;
    }
};