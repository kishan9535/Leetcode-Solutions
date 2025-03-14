class Solution {
public:
   bool possible(int size,vector<int>& candies, long long k){
    long long sum=0;
    for(auto it:candies){
        sum+=(it/size);
    }
    return (sum>=k);
   }
    int maximumCandies(vector<int>& candies, long long k) {
      int maxi,mini;
      for(auto it: candies){
        maxi=max(maxi,it);
        mini=min(mini,it);
      }
      int ans=0;
      int l=1,r=maxi;
      while(l<=r){
        int mid=l+(r-l)/2;
        if(possible(mid,candies,k)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
      } 
      return ans; 
    }
};