class Solution {
public:
   int binary_search(int key,vector<int>& potions){
       int l=0;
       int r=potions.size()-1;
       int ans=-1;
       while(l<=r){
           int mid=l+(r-l)/2;
           if(potions[mid]>=key){
               ans=mid;
               r=mid-1;
           }
           else{
               l=mid+1;
           }
       }
       return ans;
   }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
      int n=spells.size();
      int m=potions.size();
      sort(potions.begin(),potions.end());
      int max_element=potions[m-1];
       vector<int>ans;
      for(int i=0;i<n;i++){
        int spell=spells[i];

        long long min_pos=ceil((1.0*success)/spell);

        if(min_pos>max_element){
            ans.push_back(0);
            continue;
        }
        //int idx=lower_bound(potions.begin(),potions.end(),min_pos)-potions.begin();
         int idx=binary_search(min_pos,potions);

        int cnt=m-idx;
        ans.push_back(cnt);
      }  
      return ans;
    }
};