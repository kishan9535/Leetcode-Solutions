class Solution {
public:
   void solve(string curr,vector<string>&ans,int n){
    if(curr.length()==n){
        ans.push_back(curr);
        return;
    }
    for(char ch='a';ch<='c';ch++){
        if(curr.empty() || curr.back() != ch){
            curr+=ch;
            solve(curr,ans,n);
            curr.pop_back();
        }
    }
   }
    string getHappyString(int n, int k) {
       vector<string>ans;
       solve("",ans,n);
       if(ans.size()<k)return "";
       return ans[k-1]; 
    }
};