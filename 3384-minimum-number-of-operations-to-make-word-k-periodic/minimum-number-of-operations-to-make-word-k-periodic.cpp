class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
      int n=word.size();
      unordered_map<string,int>mp;
      int maxi=0;
      for(int i=0;i<n;i+=k){
        string st=word.substr(i,k);
        mp[st]++;
        maxi=max(maxi,mp[st]);
      }
      return n/k-maxi;  
    }
};