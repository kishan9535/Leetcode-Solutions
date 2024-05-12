class Solution {
public:
    int findPermutationDifference(string s, string t) {
       unordered_map<int,vector<int>>mp;
       int n=s.length();
       for(int i=0;i<n;i++){
        mp[s[i]-'a'].push_back(i);
       }
       for(int i=0;i<n;i++){
        mp[t[i]-'a'].push_back(i);
       }
       int ans=0;
       for(auto i:mp){
        int f=i.second[0];
        int s=i.second[1];
        int a=abs(f-s);
        ans+=a;
       }
       return ans; 
    }
};