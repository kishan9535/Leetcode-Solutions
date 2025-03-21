class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
       int n=recipes.size();
       unordered_set<string>st(supplies.begin(),supplies.end());
       unordered_map<string,vector<int>>mp;
       queue<int>que;
       vector<string>ans;

       vector<int>indegree(n,0);
       for(int i=0;i<n;i++){
        for(auto it: ingredients[i]){
            if(!st.count(it)){
                mp[it].push_back(i);
                indegree[i]++;
            }
        }
       }
       for(int i=0;i<n;i++){
        if(indegree[i]==0){
            que.push(i);
        }
       }
       while(!que.empty()){
         int i=que.front();
         que.pop();
         string recipie=recipes[i];
         ans.push_back(recipie);
         for(auto it: mp[recipie]){
            indegree[it]--;
            if(indegree[it]==0){
                que.push(it);
            }
         }
       }
       return ans; 
    }
};