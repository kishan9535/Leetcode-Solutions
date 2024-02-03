class Solution {
public:
int n;
int t[501];
   int solve(int idx,vector<int>& arr,int k){
       if(idx>=n)return 0;
       if(t[idx]!=-1)return t[idx];
       int max_el=-1;
       int ans=0;
       for(int i=idx;i<n &&i-idx+1<=k;i++){
           max_el=max(max_el,arr[i]);
           ans=max(ans,((i-idx+1)*max_el)+solve(i+1,arr,k));
       }
       return t[idx]=ans;
   }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
      n=arr.size();
      memset(t,-1,sizeof(t));
      return solve(0,arr,k);  
    }
};