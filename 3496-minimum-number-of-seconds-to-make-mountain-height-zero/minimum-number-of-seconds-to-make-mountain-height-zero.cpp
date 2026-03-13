class Solution {
public:
  typedef long long ll;

   bool check(int mountainHeight,vector<int>&workerTimes,ll mid){
     ll  h=0;

     for(auto &it:workerTimes){
        h+=(ll)(sqrt(2.0*mid/it +0.25)-0.5);

        if(h>=mountainHeight)return true;
     }
     return h>=mountainHeight;
   }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

      ll maxi=*max_element(workerTimes.begin(),workerTimes.end());
      ll l=1;
      ll r=(ll)maxi*mountainHeight*(mountainHeight+1)/2;
      ll ans=0;

      while(l<=r){
        ll mid=l+(r-l)/2;
        if(check(mountainHeight,workerTimes,mid)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
      }
    return ans;
    }
};