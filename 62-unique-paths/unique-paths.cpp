class Solution {
public:
 int a,b;
 int t[101][101];
    int solve(int i,int j){
        if(i==a-1 &&j==b-1)return 1;
        if(i>=a ||j>=b) return 0;
        if(t[i][j]!=-1)return t[i][j];

        int l=solve(i+1,j);
        int d=solve(i,j+1);

        return t[i][j]=(l+d);
    }
    int uniquePaths(int m, int n) {
        a=m;
        b=n;
        memset(t,-1,sizeof(t));
         return solve(0,0);
    }
};