class Solution {
public:
int n,m;
int t[501][501];
  int solve(int i,int j,vector<int>& nums1, vector<int>& nums2){
      if(i>=n ||j>=m)return 0;
        if(t[i][j]!=-1)return t[i][j];
      if(nums1[i]==nums2[j])return 1+solve(i+1,j+1,nums1,nums2);
      int a=solve(i+1,j,nums1,nums2);
      int b=solve(i,j+1,nums1,nums2);
      return t[i][j]=max(a,b);
  }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        m=nums2.size();
        memset(t,-1,sizeof(t));
        return solve(0,0,nums1,nums2);
    }
};