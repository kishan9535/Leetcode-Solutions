class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
      int ans=0,k=pref.size();
      for(auto it: words){
        string t=it;
        if(t.substr(0,k)==pref)ans++;
      }
      return ans;  
    }
};