class Solution {
public:
  int n;
      int binary_searchh(vector<pair<int,int>>inv,int tar){
         int l=0;
         int r=n-1;
          int ans=-1;
         while(l<=r){
            int mid=l+(r-l)/2;
            if(inv[mid].first>=tar){
                ans=inv[mid].second;
                r=mid-1;
                
            }
            else{
                l=mid+1;
            }
         }
         return ans;

      }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
     vector<int>ans;
     n=intervals.size();
     if(n==1){
        if(intervals[0][1]!=intervals[0][0]){
            return {-1};
        }
        return {0};
     }
        vector<pair<int, int>>inv;
        
        for(int i=0;i<intervals.size();i++){
            inv.push_back({intervals[i][0], i});
        }
         sort(inv.begin(), inv.end());
     for(auto it: intervals){
        int s=it[0];
        int e=it[1];
        int a=binary_searchh(inv,e);
        ans.push_back(a);
     }
     return ans;
    }
};