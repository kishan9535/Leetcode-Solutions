class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       int n=strs.size();
      unordered_map<string,vector<string>>mp;  
      for(auto i:strs){
          string t=i;
          sort(t.begin(),t.end());
          mp[t].push_back(i);
      }
      vector<vector<string>>ans;
      for(auto it:mp){
          ans.push_back(it.second);
      }
      return ans;
    }
};