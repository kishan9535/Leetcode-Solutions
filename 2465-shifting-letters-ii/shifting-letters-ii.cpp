class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
      int n=s.length();
      vector<int>count(n,0);
      for(auto it: shifts){
         int l=it[0];
         int r=it[1];
         int val=(it[2]==0?-1:1);
         count[l]+=val;
         if(r+1>=n)continue;
         count[r+1]-=val;
      }
      for(int i=1;i<n;i++){
         count[i]+=count[i-1];
      }
      for(int i=0;i<n;i++){
        char ch=s[i];
        int val=ch-'a';
        int has_to_add=count[i]%26;
        if(has_to_add<0){
            has_to_add+=26;
        }
        val=(val+has_to_add)%26;
        s[i]=val+'a';
      }
      return s;
    }
};