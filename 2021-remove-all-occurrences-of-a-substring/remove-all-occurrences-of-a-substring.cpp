class Solution {
public:
    string removeOccurrences(string s, string part) {
       int n=part.length();
       string ans="";
       for(int i=0;i<s.length();i++){
        ans+=s[i];
        if(ans.length()>=n && ans.substr(ans.length()-n)==part){
            ans.erase(ans.length()-n);
        }
       } 
       return ans;
    }
};