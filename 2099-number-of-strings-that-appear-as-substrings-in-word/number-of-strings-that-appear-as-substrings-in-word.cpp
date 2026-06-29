class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        
        set<string>st;
        int n=word.length();

        for(int i=0;i<n;i++){
            string s="";
            for(int j=i;j<n;j++){
                s+=word[j];
                st.insert(s);
            }
        }
        int ans=0;
        int m=patterns.size();

        for(int i=0;i<m;i++){
            string t=patterns[i];
            if(st.find(t)!=st.end()){
                ans++;
            }
        }
        return ans;
    }
};