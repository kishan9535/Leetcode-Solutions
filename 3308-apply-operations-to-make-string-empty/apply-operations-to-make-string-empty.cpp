class Solution {
public:
    string lastNonEmptyString(string s) {
       unordered_map<char,int>mp;
       int max_freq=0;
       for(auto i:s){
           max_freq=max(max_freq,++mp[i]);
       }
       string ans="";
       unordered_map<char,int>cur;
       for(int i=0;i<s.length();i++){
           cur[s[i]]++;
           if(cur[s[i]]==max_freq)ans+=s[i];
       }
       return ans; 
    }
};