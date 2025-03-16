class Solution {
public:
      typedef long long ll;
    bool is_Possible(vector<int>& ranks, int cars,ll mid){
          ll sum = 0;
        for (int i = 0; i < ranks.size(); i++) {
            sum += (ll)sqrt(mid / (ll)ranks[i]);
            if (sum >= cars) return true;
        }
        return sum >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
     ll ans=-1;
     ll l=1;
     int n=ranks.size();
     int maxi=*max_element(ranks.begin(),ranks.end());
     ll r= 1LL*maxi*cars*cars;

     while(l<=r){
        ll mid=l+(r-l)/2;
        if(is_Possible(ranks,cars,mid)){
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