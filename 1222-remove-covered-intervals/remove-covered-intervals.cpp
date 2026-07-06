class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        int ans=0;
        sort(intervals.begin(),intervals.end());
        int l=-1,r=-1;
        int i=0;
        int n=intervals.size();

        while(i<n){
            int i_=intervals[i][0];
            int j_=intervals[i][1];

            if(i_>l && j_>r){
                ans++;
                l=i_;
            }
            r=max(r,j_);
            i++;

        }
        return ans;
    }
};