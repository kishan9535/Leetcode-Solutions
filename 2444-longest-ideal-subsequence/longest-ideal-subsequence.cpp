class Solution {
public:
    int longestIdealString(string s, int k) {
       vector<int>lis(26,0);
       int n=s.length();
        int ans=0;
       for(int i=0;i<n;i++){
         int idx=s[i]-'a';
         int left=max(0,idx-k);
         int right=min(25,idx+k);
         int maxi=0;
         for(int j=left;j<=right;j++){
            maxi=max(maxi,lis[j]);
         }
         lis[idx]=max(lis[idx],maxi+1);
         ans=max(ans,lis[idx]);
       }
     
       return ans; 
    }
};