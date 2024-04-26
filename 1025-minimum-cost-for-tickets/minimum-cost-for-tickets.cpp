class Solution {
public:
int n;
int t[366];
    
    int solve(vector<int>& days, vector<int>& costs,int idx){
        if(idx>=n)return 0;
         if(t[idx]!=-1)return t[idx];
        int d_1=costs[0]+solve(days,costs,idx+1);

        
         int m_d1=days[idx]+7;
         int j=idx;
         while(j<n && days[j]<m_d1){
            j++;
         }
          int d_2=costs[1]+solve(days,costs,j);
         int m_d2=days[idx]+30;
         int k=idx;
         while(k<n && days[k]<m_d2){
            k++;
         }
         int d_3=costs[2]+solve(days,costs,k);
        return t[idx]=min({d_1,d_2,d_3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
      n=days.size();
      memset(t,-1,sizeof(t));
      return solve(days,costs,0);  
    }
};