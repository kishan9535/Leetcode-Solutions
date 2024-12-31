class Solution {
public:
    string answerString(string word, int numFriends) {
     string ans="";
     int n=word.size();
     int window_size=n-numFriends+1;
     int j=0;
     if(numFriends==1)return word;
     for(int i=0;i<n;i++){
        ans=max(ans,word.substr(i,window_size));
     }
      return ans;
    }
};