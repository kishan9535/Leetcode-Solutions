class Solution {
public:
    bool solve(string s,set<string>&st){
       int n=s.length();
        while(s.length()>0){
        size_t position = s.find_last_of('/');
        s=s.substr(0,position);
        if(st.find(s)!=st.end())return false;

        }
      return true;
    }

    vector<string> removeSubfolders(vector<string>& folder) {
       vector<string>ans;
       set<string>st(folder.begin(),folder.end());

       for(auto &it :folder){

        if(solve(it,st)){
            ans.push_back(it);
        }
       }
       return ans; 
    }
};