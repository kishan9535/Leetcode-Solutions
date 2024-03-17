class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      int n=intervals.size();
      vector<vector<int>>ans;
       int i;
      for(i=0;i<n;i++){
        if(intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
        }
        else if(intervals[i][0]>newInterval[1]){
            break;
        }
        else{
            int start=min(intervals[i][0],newInterval[0]);
            int end=max(intervals[i][1],newInterval[1]);
            newInterval[0]=start;
            newInterval[1]=end;
        }
      }
      ans.push_back(newInterval);
      while(i<n){
        ans.push_back(intervals[i]);
        i++;
      }
      return ans;
    }
};