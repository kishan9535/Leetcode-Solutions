class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
      vector<int>ans=nums;
      sort(ans.begin(),ans.end());
      int n=ans.size();
      int group_no=0;
      unordered_map<int,int>ng;
      ng[ans[0]]=group_no;

      unordered_map<int,list<int>>group_list;
      group_list[group_no].push_back(ans[group_no]);

      for(int i=1;i<n;i++){
         if(abs(ans[i]-ans[i-1])>limit){
            group_no++;

         }
         ng[ans[i]]=group_no;
         group_list[group_no].push_back(ans[i]);
      }
       for(int i=0;i<n;i++){
          int num=nums[i];
          int group=ng[num];
          nums[i]=*(group_list[group].begin());
          group_list[group].pop_front();

       }
       return nums;  
    }
};