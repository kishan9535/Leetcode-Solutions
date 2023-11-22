class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
     int col=mat.size();
     vector<int>ans;
     unordered_map<int,vector<int>>mp;
     for(int c=col-1;c>=0;c--){
         for(int r=0;r<mat[c].size();r++){
             int d=c+r;
             mp[d].push_back(mat[c][r]);
         }
     }
     int i=0;
     while(mp.find(i)!=mp.end()){
         vector<int>v;
         if(i%2==0){
             for(auto a:mp[i]){
                 ans.push_back(a);
             }
         }
         else{
             for(auto a: mp[i]){
                 v.push_back(a);
             }
             reverse(v.begin(),v.end());
             for(auto e:v){
                 ans.push_back(e);
             }
         }
         i++;
     }
     return ans;
    }
};