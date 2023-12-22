class Solution {
public:
    int maximumSum(vector<int>& nums) {
      int ans=-1;
      int n=nums.size();
       vector<pair<int,int>> p;
      for(int i=0;i<n;i++){
          int d=nums[i];
          int sum=0;
          while(d!=0){
              sum=sum+(d%10);
              d/=10;
          }
          p.push_back(make_pair(sum,nums[i]));
      }
      sort(p.begin(),p.end());
      for(int i=1;i<n;i++){
          if(p[i].first ==p[i-1].first){
              ans=max(ans,(p[i].second+p[i-1].second));
          }
      }
      return ans;

    }
};