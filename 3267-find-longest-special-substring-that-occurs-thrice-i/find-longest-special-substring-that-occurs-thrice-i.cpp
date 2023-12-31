class Solution {
public:
bool solve(string ss){
    char prev=ss[0];
    int n=ss.length();
    for(int i=1;i<n;i++){
        if(prev!=ss[i]){
            return false;
        }
    }
    return true;
}
    int maximumLength(string s) {
       unordered_map<string,int>mp;
       string st="";
       int n=s.length();
       for(int i=0;i<n;i++){
           st="";
           for(int j=i;j<n;j++){
             st+=s[j];
             mp[st]++; 
           }
       }
       int ans=-1;
       for(auto i:mp){
           if(i.second>=3){
               bool flag=solve(i.first);
               if(!flag){
                   continue;
               }
               int len=i.first.length();
            ans=max(ans,len);
           }
       }
       return ans; 
    }
};
