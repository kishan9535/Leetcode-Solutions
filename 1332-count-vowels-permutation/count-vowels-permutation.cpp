class Solution {
public:
int MOD=1e9+7;
int a=0,e=1,i=2,o=3,u=4;
    int countVowelPermutation(int n) {
        long long t[5][n+1];
        t[a][1]=1;
        t[e][1]=1;
        t[i][1]=1;
        t[o][1]=1;
        t[u][1]=1;

        for(int len=2;len<=n;len++){
            t[a][len]=(t[e][len-1]+t[i][len-1]+t[u][len-1])%MOD;
            t[e][len]=(t[a][len-1]+t[i][len-1])%MOD;
            t[i][len]=(t[e][len-1]+t[o][len-1])%MOD;
            t[o][len]=(t[i][len-1])%MOD;
            t[u][len]=(t[o][len-1]+t[i][len-1])%MOD;



        }
        long long result=0;
        for(int vov=0;vov<=4;vov++){
            result=(result+t[vov][n])%MOD;
        }
       return  result;
    }
};