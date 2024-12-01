class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
       unordered_map<string,int>mp1,mp2;
       int l=s.length()/k;
       cout<<l<<endl;
       int n=s.length();
       for(int i=0;i<n;i+=l){
        string temp=s.substr(i,l);
        cout<<temp<<endl;
        mp1[temp]++;
       }
       for(int i=0;i<n;i+=l){
        string temp=t.substr(i,l);
        cout<<temp<<endl;
        mp2[temp]++;
       }
       for(auto it: mp1){
        string substring=it.first;
        if(mp1.count(substring) != mp2.count(substring) || mp1[substring] != mp2[substring]){
            return false;
        }
       }
       return true;
    }
};