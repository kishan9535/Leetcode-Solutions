class Solution {
public:
    bool closeStrings(string word1, string word2) {
      vector<int>c1(26,0);
      vector<int>c2(26,0);
      int n=word1.size();
      int m=word2.size();
      if(n!=m)return false;
      for(auto i:word1){
          c1[i-'a']++;
      }  
      for(auto i:word2){
          c2[i-'a']++;
      }
      for(int i=0;i<26;i++){
          if(c1[i]==0 &&c2[i]!=0) return false;
          if(c1[i]!=0 && c2[i]==0) return false;
          

      }
      sort(c1.begin(),c1.end());
          sort(c2.begin(),c2.end());
          return c1==c2;  
    }
};