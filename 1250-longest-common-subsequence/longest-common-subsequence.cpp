class Solution {
public:int n,m;
int t[1001][1001];
     int solve(int i,int j,string &text1, string &text2){
       if(i>=n ||j>=m)return 0;
        if(t[i][j]!=-1)return t[i][j];
       if(text1[i]==text2[j])return 1+solve(i+1,j+1,text1,text2);
       int a=solve(i+1,j,text1,text2);
       int b=solve(i,j+1,text1,text2);
       return t[i][j]= max(a,b);
     }
    int longestCommonSubsequence(string text1, string text2) {
        n=text1.length();
        m=text2.length();
        memset(t,-1,sizeof(t));
     return solve(0,0,text1,text2);   
    }
};