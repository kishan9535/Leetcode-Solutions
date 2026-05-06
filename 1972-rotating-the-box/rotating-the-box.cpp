class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        
        int n=boxGrid[0].size();
        int m=boxGrid.size();

        vector<vector<char>>ans(n,vector<char>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=boxGrid[j][i];
            }
        }

        for(vector<char>& v :ans){
            reverse(v.begin(),v.end());
        }

        for(int i=0;i<m;i++){
            int sp=n-1;
            for(int j=n-1;j>=0;j--){
                if(ans[j][i]=='*'){
                    sp=j-1;
                    continue;
                }

                if(ans[j][i]=='#'){
                    ans[j][i]='.';
                    ans[sp][i]='#';
                    sp--;
                }
            }
        }
        return ans;
    }
};