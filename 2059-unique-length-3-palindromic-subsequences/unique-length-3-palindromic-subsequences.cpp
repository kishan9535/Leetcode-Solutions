class Solution {
public:
    int countPalindromicSubsequence(string s) {
      int n=s.length();
      int result=0;
      vector<pair<int,int>>indi(26,{-1,-1});
      for(int i=0;i<n;i++){
         char ch=s[i];
         int idx=ch-'a';
          if(indi[idx].first==-1){
              indi[idx].first=i;
          }
          indi[idx].second=i;
      }
      for(int i=0;i<26;i++){
          if(indi[i]==make_pair(-1,-1)){
              continue;
          }
          unordered_set<char>st;
          for(int count =indi[i].first+1;count<=indi[i].second-1;count++){
              st.insert(s[count]);
          }
          result+=st.size();
      }  
      return result;
    }
};