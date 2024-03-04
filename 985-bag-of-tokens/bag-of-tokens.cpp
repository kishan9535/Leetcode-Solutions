class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
      int n=tokens.size();
      sort(tokens.begin(),tokens.end());
      int i=0,j=n-1;
      int ans=0,maxi=0;
      while(i<=j)
      {
          if(power>=tokens[i])
          {
              ans+=1;
              power-=tokens[i];
             
              i++;
               maxi=max(maxi,ans);
          }
          else if(ans>=1)
          {
              ans-=1;
              power+=tokens[j];
              j--;
          }
          else
          return maxi;
      }
      return maxi;  
    }
};