class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
      int n=customers.size();
      double ans=0;
      int curr_Time=0;

      for(auto i:customers){
         int arrival_Time=i[0];
         int cook_time=i[1];

         if(curr_Time<arrival_Time){
            curr_Time=arrival_Time;
         }
         int wt=curr_Time+cook_time -arrival_Time;
         ans+=wt;
         curr_Time+=cook_time;
      } 
      return ans/n; 
    }
};