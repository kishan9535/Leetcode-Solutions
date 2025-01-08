class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
      int ans=0;
      int n=words.size();
      for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            string s1=words[i],s2=words[j];
            if(s1.length()>s2.length())continue;
            int l1=s1.length(),l2=s2.length();
            if(s2.substr(0,l1)==s1 && s2.substr(l2-l1,l1)==s1){
                ans++;
            }
        }
      }
      return ans;
        
    }
};