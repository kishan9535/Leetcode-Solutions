class Solution {
public:
    int minimumCost(vector<int>& cost) {

        int n=cost.size();
        sort(cost.begin(),cost.end(),greater<int>());
        int ans=0;

        for(int i=0;i<n;i++){
            if(i%3!=2){
                ans+=cost[i];
            }
        }
        return ans;
    }
};