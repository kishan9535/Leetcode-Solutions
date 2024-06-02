class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
     int ans=0;
     sort(meetings.begin(),meetings.end());
     int last=1;
     if(meetings[0][0]!=1){
        ans+=(meetings[0][0]-1);
     }
     int n=meetings.size();
     int start;
     last=meetings[0][1];
     for(int i=1;i<n;i++){
        start=meetings[i][0];
        if(last>=start){

            last=max(last,meetings[i][1]);
            continue;
        }
        ans+=abs(start-last-1);
        last=meetings[i][1];
     }
     if(last!=days){
        ans+=(days-last);
     }
     return ans;   
    }
};