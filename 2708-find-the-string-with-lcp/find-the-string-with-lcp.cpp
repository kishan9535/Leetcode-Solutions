class Solution {
public:

  vector<vector<int>> longest_common_prefix(string s){
    int n=s.length();
    vector<vector<int>>ans(n,vector<int>(n,0));

    for(int j=0;j<n;j++){
        ans[n-1][j]=ans[j][n-1]=(s[j]==s[n-1])?1:0;
    }

    for(int i=n-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            ans[i][j]=(s[i]==s[j])? 1+ans[i+1][j+1] :0;
        }
    }
    return ans;
  }
   
    string findTheString(vector<vector<int>>& lcp) {
      int n=lcp.size();

      string ans(n,'a');
      
      for(int i=1;i<n;i++){
      vector<bool>not_eql(26,false);
      bool matched=false;

      for(int j=0;j<i;j++){
        if(lcp[j][i]==0){
            not_eql[ans[j]-'a']=true;
            continue;
        }
        matched=true;
        ans[i]=ans[j];
        break;
      }
      if(matched)continue;

      for(int j=0;j<26;j++){
        if(not_eql[j])continue;
        ans[i]=(char)('a'+j);
        break;
      }
      }

      if(longest_common_prefix(ans)==lcp) return ans;
      return "";

    }
};