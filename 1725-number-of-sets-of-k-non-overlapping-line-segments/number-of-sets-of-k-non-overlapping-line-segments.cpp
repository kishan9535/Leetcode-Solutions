class Solution {
public:
  
     int Mod=1e9+7;
     int t[1001][1001];


    int numberOfSets(int n, int k) {
        
      
      for(int i=0;i<=n-1;i++){
        t[0][i]=1;
      }

      for(int r=1;r<=k;r++){

        vector<int>prev(n+1,0);

        for(int x=n-1;x>=0;x--){
            prev[x]=(prev[x+1]+t[r-1][x])%Mod;
        }

        for(int i=n-1;i>=0;i--){

            int take =prev[i+1];
            int skip=t[r][i+1]%Mod;

            t[r][i]=(take+skip)%Mod;
        }

      }
      return t[k][0];  

    }
};