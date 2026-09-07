class Solution {
public:

   int M=1e9+7;
   vector<int>prev;

   int t[2001];

   int solve(int n){
     
     if(n==0)return 1;

     if(t[n]!=-1)return t[n];

     long long total=2*solve(n-1);
     int d=0;

     if(prev[n]!=0){
        d=solve(prev[n]-1)%M;
     }
     total=(total-d+M)%M;

     return t[n]= (total)%M;

   }
  
    
    int distinctSubseqII(string s) {

        int n=s.length();
        vector<int>lastseen(26,0);
        prev.assign(n+1,0);

        memset(t,-1,sizeof(t));

        for(int i=1;i<=n;i++){
            int c=s[i-1]-'a';
            prev[i]=lastseen[c];
            lastseen[c]=i;
        }

        return (solve(n)-1+M)%M;

        
    }
};