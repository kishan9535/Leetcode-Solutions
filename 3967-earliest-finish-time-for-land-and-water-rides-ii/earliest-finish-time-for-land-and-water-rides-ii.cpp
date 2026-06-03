class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

         int ans=1000001;
        int bestland=1000001;
        int bestwater=1000001;
        int n=landStartTime.size();
        int m=waterStartTime.size();

        for(int i=0;i<n;i++){
            bestland=min(bestland,(landStartTime[i]+landDuration[i]));
        }

        for(int i=0;i<m;i++){
            bestwater=min(bestwater,waterStartTime[i]+waterDuration[i]);
        }

        for(int i=0;i<n;i++){
            int curr=max(bestwater,landStartTime[i])+landDuration[i];
            ans=min(ans,curr);
        }

        for(int i=0;i<m;i++){
            int curr=max(bestland,waterStartTime[i])+waterDuration[i];
            ans=min(ans,curr);
        }

        return ans;
        
    }
};