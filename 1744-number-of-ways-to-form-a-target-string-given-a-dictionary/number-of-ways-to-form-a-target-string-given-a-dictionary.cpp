class Solution {
public:
int m,k;
int Mod= 1e9+7;
 int t[1001][1001];
     int solve(int i,int j,string &target,vector<vector<long long>> &freq){
         if(j>=m)return 1;
         if(i>=k)return 0;
          if(t[i][j]!=-1) return t[i][j];
          int not_taken=solve(i+1,j,target,freq)%Mod;

          int taken= (freq[target[j]-'a'][i])*solve(i+1,j+1,target,freq)%Mod;

          return t[i][j]= (taken+not_taken)%Mod;
     }
    int numWays(vector<string>& words, string target) {
     m=target.size();
     k=words[0].size();
      vector<vector<long long>> freq(26,vector<long long>(k));
      for(int col=0;col<k;col++){
          for(string &word:words){
              char ch=word[col];
              freq[ch-'a'][col]++;
          }
      }
      memset(t,-1,sizeof(t));

     return solve(0,0,target,freq);   
    }
};