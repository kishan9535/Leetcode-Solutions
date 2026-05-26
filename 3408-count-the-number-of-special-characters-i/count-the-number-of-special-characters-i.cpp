class Solution {
public:
   
    int numberOfSpecialChars(string word) {
      
      int ans=0;
      vector<int>up(26,0);
      vector<int>lo(26,0);
      int n=word.length();

      for(int i=0;i<n;i++){
        if(word[i]==tolower(word[i])){
            lo[word[i]-'a']++;
        }
        else{
            up[word[i]-'A']++;
        }
      }
      for(int i=0;i<26;i++){
        if(up[i]>0 && lo[i]>0){
            ans++;
        }
      }
      return ans;
    }
};