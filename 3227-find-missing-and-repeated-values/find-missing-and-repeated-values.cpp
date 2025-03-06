class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
       vector<int>ans;
       unordered_map<int,int>mp;
       int n=grid[0].size();
       int m=grid.size();
       int maxi=n*m;
       cout<<maxi;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mp[grid[i][j]]++;
            if(mp[grid[i][j]]==2){
                ans.push_back(grid[i][j]);
            }
        }
       }

       for(int i=1;i<=maxi;i++){
           if(mp.find(i)==mp.end()){
            ans.push_back(i);
            break;
           }
       }

       return ans; 
    }
};