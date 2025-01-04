class Solution {
public:
    int countPalindromicSubsequence(string s) {
       int ans=0;
       unordered_map<char,pair<int,int>>mp;
       int n=s.length();
       for(char ch='a';ch<='z';ch++){
         int first=-1,last=-1;
         for (int i = 0; i < n; i++) {
                if (s[i] == ch) {
                    if (first == -1) {
                        first = i; 
                    }
                    last = i;  
                }
            }
            mp[ch] = {first, last};
       }
       for(auto it:mp){
        char c=it.first;
         int f = it.second.first;
         int l = it.second.second;
        if(f==-1||l==-1 || f==l)continue;
        unordered_set<char>st;
        for(int i=f+1;i<l;i++){
            st.insert(s[i]);
        }
        ans+=st.size();
       }
       return ans;
    }
};