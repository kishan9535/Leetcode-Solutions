class Solution {
public:
int n;
int t[101];
     int solve(int idx,string &s){
         if(t[idx]!=-1) return t[idx];
         if(idx==n) return t[idx]=1;

         if(s[idx]=='0')return t[idx]= 0;
         int ans;
         ans=solve(idx+1,s);
         if(idx+1<n){
             if(s[idx]=='1'||(s[idx]=='2'&&s[idx+1]<='6')){
                 ans+=solve(idx+2,s);
             }
         }
         return t[idx]= ans;
     }
    int numDecodings(string s) {
       n=s.length();
       memset(t,-1,sizeof(t));
       return solve(0,s); 
    }
};