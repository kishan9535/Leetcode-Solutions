class Solution {
public:
   void solve(string tiles,string s,vector<bool>&taken,unordered_set<string>&ans){
        ans.insert(s);
        for(int i=0;i<tiles.length();i++){
            if (!taken[i]) {
                taken[i] = true; 
                solve(tiles, s + tiles[i], taken, ans); 
                taken[i] = false; 
            }
            
        }
   }
    int numTilePossibilities(string tiles) {
      
      int n=tiles.length();
      vector<bool>taken(n,false);
      unordered_set<string>ans;
      solve(tiles,"",taken,ans);

      return ans.size()-1;

    }
};