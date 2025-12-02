class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
      int Mod=1e9+7;
      unordered_map<int,int>mp;
      int n=points.size();
      for(int i=0;i<n;i++){
        mp[points[i][1]]++;
      }
      long long ans=0;
      int seenpoints=0;
      for(auto it: mp){
         int point=it.second;
         long long com= (long long)point*(point-1)/2;
         ans+=seenpoints*com;
         seenpoints+=com;
      }
      return ans%Mod;  
    }
};