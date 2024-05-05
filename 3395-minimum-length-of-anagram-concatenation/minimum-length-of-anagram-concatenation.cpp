class Solution {
public:
    bool Check(string s ,int k){
        int d;
       /* unordered_map<int,int>mp;
        for(int i=0;i<k;k++){
            mp[s[i]]++;
        }*/
        string st=s.substr(0,k);
        sort(st.begin(),st.end());
        
        for(int i=k;i<s.length();i+=k){
            string temp=s.substr(i,k);
            sort(temp.begin(),temp.end());
            if(st!=temp)return false;
        }
        return true;
    }
    int minAnagramLength(string s) {
      int n=s.length();
      for(int i=1;i<=n;i++){
        if(n%i==0 && Check(s,i)){
            return i;
        }
      }
      return n;  
    }
};