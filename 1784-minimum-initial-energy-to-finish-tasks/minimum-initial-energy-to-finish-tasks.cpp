class Solution {
public:
   
    bool solve(vector<vector<int>>& tasks, int mini){
        int n=tasks.size();

        for(int i=0;i<n;i++){
            int rem=tasks[i][0];
            int need=tasks[i][1];

            if(mini<need){
                return false;
            }

            mini-=rem;
        }
      return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {

      int n=tasks.size();
      int ans=0;
      int l=0;
      int r=INT_MAX;

      auto cmp=[](auto& t1,auto &t2){
        
        int d1=t1[1]-t1[0];
        int d2=t2[1]-t2[0];

        return d1>d2;
      };

      sort(tasks.begin(),tasks.end(),cmp);  

      while(l<=r){
        int mid=l+(r-l)/2;

        if(solve(tasks,mid)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
      }
      return ans;
    }
};