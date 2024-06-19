class Solution {
public:
   bool Can_Make_Bouque(vector<int>& bloomDay, int mid, int k,int m){
     int bouque_cnt=0;
     int consicutive_cnt=0;
      int n=bloomDay.size();
     for(int i=0;i<n;i++){
        if(bloomDay[i]<=mid){
            consicutive_cnt++;
        }
        else{
            consicutive_cnt=0;
        }
        if(consicutive_cnt==k){
            bouque_cnt++;
            consicutive_cnt=0;
        }
     }
     return true?bouque_cnt>=m :false;
   }
    int minDays(vector<int>& bloomDay, int m, int k) {
      
      int n=bloomDay.size();
      int maxi=*max_element(bloomDay.begin(),bloomDay.end());
      int ans= -1;
      
      int l=0;
      int r=maxi;
      while(l<=r){
        int mid=l+(r-l)/2;

        if(Can_Make_Bouque(bloomDay, mid,k,m)){
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