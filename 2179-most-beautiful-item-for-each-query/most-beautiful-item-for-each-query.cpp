class Solution {
public:
   int binary_search(int key,vector<vector<int>>& items){
      int l = 0;
        int r = items.size() - 1;  // Set r to the last valid index
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;  // Corrected mid calculation

            if (items[mid][0] > key) {
                r = mid - 1;
            } else {
                ans = items[mid][1];
                l = mid + 1;
            }
        }
        return ans;
   }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
      vector<int>ans;
      sort(items.begin(),items.end());
      int maxi=0;
      for(auto &it: items){
         maxi=max(maxi,it[1]);
         it[1]=maxi;
      }
      int l=0;
      int r=items.size();
       int  m=queries.size();
      for(int i=0;i<m;i++){
         int val=binary_search(queries[i],items);
         ans.push_back(val);
      } 
      return ans;
    }
};