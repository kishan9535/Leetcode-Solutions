class Solution {
public:
int t[1001][1001];
    bool isPalindrome(string &s,int i,int j){
        if(i>j)return true;
        if(t[i][j]!=-1)return t[i][j];
        
        if(s[i]==s[j]){
            return isPalindrome(s,i+1,j-1);
        }
        return false;
    }
    int countSubstrings(string s) {
     int ans=0;
     memset(t,-1,sizeof(t));
        int n=s.length();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j))ans++;
            }
        }
        return ans;
    }
};