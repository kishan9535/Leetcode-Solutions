class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
      vector<int>ans;
      unordered_map<int,int>color;
      unordered_map<int,int>balls;
      int n=queries.size();
      for(int i=0;i<n;i++){
        int bal=queries[i][0];
        int col=queries[i][1];
        if(balls.count(bal)){
            int prev=balls[bal];
            color[prev]--;

            if(color[prev]==0){
                color.erase(prev);
            }
        }
        balls[bal]=col;
        color[col]++;
        ans.push_back(color.size());
      }
      return ans;
    }
};