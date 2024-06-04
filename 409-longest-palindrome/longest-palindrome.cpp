class Solution {
public:
    int longestPalindrome(string s) {
       int odc=0;
      unordered_map<char ,int > mp;
      for(auto i:s)
      {
      mp[i]++;
      if(mp[i]%2==1)
      odc++;
      else odc--;
      }
      if(odc>1)
       return s.length()-odc+1;
       return s.length();
    }
};