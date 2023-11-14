class Solution {
public:
    int countPalindromicSubsequence(string s) {
       int result=0;
        int n=s.length();
        unordered_set<char>st;
        for(auto i:s){
            st.insert(i);
        }
        for(auto letter:st){
            int fi=-1,li=-1;
            for(int i=0;i<n;i++){
                if(s[i]==letter){
                    if(fi==-1){
                        fi=i;
                    }
                    li=i;
                }
            }
            unordered_set<char>stt;
            for(int k=fi+1;k<li;k++){
                stt.insert(s[k]);
            }
            result+=stt.size();
        }
        return result;
    }
};