class Solution {
public:
    int minSteps(string s, string t) {
     unordered_map<char,int>mp;
     for(auto i:s)
     mp[i]++;
     for(auto d:t)
     mp[d]--;
      int cnt=0;
     for(auto &it:mp)
     {
         if(it.second>0)cnt+=(it.second);

     }   
     return cnt;
    }
};