class Solution {
public:
    int t[2001][4001];
    int solve(vector<int>& rewardValues,int prefix_sum,int idx){

         if(idx>=rewardValues.size()){
            return prefix_sum;
         }   
         if(t[idx][prefix_sum]!=-1)return t[idx][prefix_sum];
        int skip=solve(rewardValues,prefix_sum,idx+1);
        int take=0;
        if(rewardValues[idx]>prefix_sum){
            int total_sum=prefix_sum+rewardValues[idx];
            take=solve(rewardValues,total_sum,idx+1);
        }
        return t[idx][prefix_sum]= max(take,skip);
    }
    int maxTotalReward(vector<int>& rewardValues) {
      sort(rewardValues.begin(),rewardValues.end());
        memset(t,-1,sizeof(t));
      return solve(rewardValues,0,0);
    }
};