class Solution {
public:
    int firstUniqChar(string s) {
      vector<int> a(128,0);
      for(int i=0;i<s.size();i++)
      a[s[i]]++;
      for(int i=0;i<s.size();i++)
    {
        if(a[s[i]]==1) return i;
    }
    return -1;
    }
};