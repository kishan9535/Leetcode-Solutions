class Solution {
public:
    int numberOfSpecialChars(string word) {
     unordered_map<char,int>mp;
     for(int i=0;i<word.size();i++){
      char ch = word[i];
            if(ch>='A' && ch<='Z' ){
                if(!mp.count(ch)){
                    mp[ch] = i;
                }
            }
        else
        mp[word[i]]=i;
     }
     int ans=0;
     for(auto i:mp){
        char c=i.first;
        int idx=i.second;
        if(islower(c) && mp.find(toupper(c))!=mp.end()){
            int Li=mp[toupper(c)];
            if(Li-idx>0)ans++;
        }
     }
     return ans;   
    }
};