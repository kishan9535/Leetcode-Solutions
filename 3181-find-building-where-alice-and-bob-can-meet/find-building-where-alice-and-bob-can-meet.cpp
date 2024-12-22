class Solution {
public:
   typedef pair<int,int> P;
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
      int n=queries.size();
      int m=heights.size();
      vector<int>ans(n,-1);

      unordered_map<int,vector<pair<int,int>>>mp;

      priority_queue<P,vector<P>,greater<P>>pq;

      for(int q=0;q<n;q++){
        int i=queries[q][0];
        int j=queries[q][1];
        if(i<j && heights[i]<heights[j]){
            ans[q]=j;
        }
        else if(i>j && heights[i]>heights[j]){
            ans[q]=i;
        }
        else if(i==j){
          ans[q]=j;
        }
        else{
            mp[max(i,j)].push_back({max(heights[i],heights[j]),q});  
        }
      }
      for(int i=0;i<m;i++){
              while(!pq.empty() && pq.top().first<heights[i]){
                ans[pq.top().second]=i;
                pq.pop();
              }

              for(auto it:mp[i]){
                pq.push(it);
              }
            }
        return ans;

    }
};