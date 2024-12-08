class Solution {
public:
   int n;
   int t[100001][3];
      int binary_search(vector<vector<int>>& events,int target){
        int l=0;
        int r=n-1;
        int ans=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(events[mid][0]>target){
                r=mid-1;
                ans=mid;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
      }
      int solve(vector<vector<int>>& events,int idx,int cnt){
        if(idx>=n || cnt>=2){
            return 0;
        }
        if(t[idx][cnt]!=-1)return t[idx][cnt];
        int next_idx=binary_search(events,events[idx][1]);
        int take=events[idx][2]+solve(events,next_idx,cnt+1);
        int skip=solve(events,idx+1,cnt);

        return t[idx][cnt]= max(take,skip);
      }
    int maxTwoEvents(vector<vector<int>>& events) {
        n=events.size();
        sort(events.begin(),events.end());
        memset(t,-1,sizeof(t));
        return solve(events,0,0);
    }
};