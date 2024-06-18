class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        priority_queue<pair<int,int>>pq;
        int n=difficulty.size();
        for(int i=0;i<n;i++){
           int d=difficulty[i];
           int p=profit[i];
           pq.push({p,d});
        }
        sort(worker.begin(),worker.end(),greater<int>());
        int Total_profit=0;
        int i=0;
        int m=worker.size();
        while(i<m && !pq.empty()){
            if(pq.top().second>worker[i]){
                pq.pop();
            }
            else{
                Total_profit+=pq.top().first;
                i++;
            }
        }
       return Total_profit;
    }
};