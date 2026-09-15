class Solution {
public:
     
     int n;


     bool ispalindrome(string &s, int k, int i, int j){
        
        while(i<j){
            if(s[i]!=s[j])return false;

            i++;
            j--;
        }

        return true;

     }

     int solve(string &s, int k, int i, int j,vector<vector<int>>&t){

        if(i>=n ||j>=n)return 0;

        if(t[i][j]!=-1)return t[i][j];

        if(ispalindrome(s,k,i,j)){

            int ti=1 + solve(s,k,j+1,j+k,t);
            int g=solve(s,k,i,j+1,t);
            int slide=solve(s,k,i+1,j+1,t);

            return t[i][j]= max({ti,g,slide});
        }

        int g=solve(s,k,i,j+1,t);
        int slide=solve(s,k,i+1,j+1,t);

        return t[i][j]= max(g,slide);

     }

    int maxPalindromes(string s, int k) {

        n=s.length();
        
        vector<vector<int>>t(n+1,vector<int>(n+1,-1));

        if(k==1)return n;

        return solve(s,k,0,k-1,t);
        
    }
};