class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
      int n=spells.size();
      int m=potions.size();
      sort(potions.begin(),potions.end());
      int max_element=potions[m-1];
       vector<int>ans;
      for(int i=0;i<n;i++){
        int spell=spells[i];

        long long min_pos=ceil((1.0*success)/spell);

        if(min_pos>max_element){
            ans.push_back(0);
            continue;
        }
        int idx=lower_bound(potions.begin(),potions.end(),min_pos)-potions.begin();
        int cnt=m-idx;
        ans.push_back(cnt);
      }  
      return ans;
    }
};