class Solution {
public:
    string processStr(string s) {

      string ans="";
      int n=s.length();

      for(int i=0;i<n;i++){
        if(s[i]=='*' || s[i]=='#' || s[i]=='%'){
            if(s[i]=='*' && !ans.empty()){
                ans.pop_back();
            }
            if(s[i]=='#' && !ans.empty()){
                ans+=ans;
            }
            if(s[i]=='%' && !ans.empty()){
                reverse(ans.begin(),ans.end());
            }
        }
        else{
            ans+=s[i];
        }
      }
      return ans;  
    }
};