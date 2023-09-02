class Solution {
public:
int n;
int t[51];
unordered_set<string>st;
   int solve(int idx,string &s){
       if(idx>=n) return 0;

       if(t[idx]!=-1) return t[idx];

       string curs ="";
       int minExt =n;

       for(int i=idx;i<n;i++){
           curs.push_back(s[i]);
           int curExtra = (st.find(curs)==st.end())?curs.length():0;
          int nextext = solve(i+1,s);
          int totalext=curExtra+nextext;
          minExt=min(minExt,totalext); 

       }
       return t[idx]= minExt;

   }
    int minExtraChar(string s, vector<string>& dictionary) {
        n=s.length();
        for(auto i:dictionary)
        st.insert(i);
        memset(t,-1,sizeof(t));

        return solve(0,s);
        
    }
};