class Solution {
public:
  bool static cmp( pair<char,int>&a,pair<char,int>&b)
  {
      return a.second>b.second;

  }
    string frequencySort(string s) {
      
      unordered_map<char,int>mp;  
      for(auto &i:s)
      {
          mp[i]++;
      }
      vector<pair<char,int>> v;
      for(auto &it:mp)
      {
          v.push_back({it.first,it.second});
      }
      sort(v.begin(),v.end(),cmp);
      string ans="";
      for(auto &t: v)
      {
          for(int i=0;i<t.second;i++)
          {
              ans+=t.first;
          }
      }
     return ans;
    }
};