class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int ans=0;
        unordered_map<string,int>mp;
        int n=matrix[0].size();
        int m=matrix.size();
        for(auto row: matrix){
            string temp="";
            int first=row[0];
           for(int i=0;i<n;i++){
            
            temp+=(first==row[i])?'1':'0';
           }
           cout<<temp;
           mp[temp]++;
        }
        for(auto it: mp){
            ans=max(ans,it.second);
        }
        return ans;
    }
};