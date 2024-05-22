class Solution {
public:
     bool is_Palindrome(string st){
        int i=0;
        int j=st.length()-1;
        while(i<j){
            if(st[i]!=st[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
     }
     void solve( string s,int idx,vector<string>&curr,vector<vector<string>>&ans){
        if(idx>=s.length()){
            ans.push_back(curr);
            return;
        }
        for(int i=idx;i<s.length();i++){
            string temp=s.substr(idx,i-idx+1);
            if(is_Palindrome(temp)){
                curr.push_back(temp);
                solve(s,i+1,curr,ans);
                curr.pop_back();
            }
        }
        return;
     }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>curr;
        solve(s,0,curr,ans);
        return ans;
    }
};