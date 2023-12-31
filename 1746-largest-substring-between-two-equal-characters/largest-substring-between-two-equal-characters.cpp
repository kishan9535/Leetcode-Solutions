class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
      vector<int>a(26,-1);
      int n=s.length(),ans=-1;
      for(int i=0;i<n;i++){
          int ch=s[i]-'a';
          if(a[ch]==-1){
              a[ch]=i;
          }
          else if(a[ch]!=-1){
              ans=max(ans,(i-a[ch]-1));
          }
      }
      return ans; 
    }
};