class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {

      int n=grid.size();
      vector<int>row(n,0);

      int ans=0;

      for(int i=0;i<n;i++){
        int j=n-1;
        int cnt=0;
        while(j>=0 && grid[i][j]==0){
            cnt++;
            j--;
        }
        row[i]=cnt;
      }

      for(int i=0;i<n;i++){
        int req=n-i-1;

       int j=i;
       if(req==row[i])continue;
       while(j<n && row[j]<req){
        j++;
       }
         if(j==n)return -1;

         ans+=(j-i);

         while(j>i){
         swap(row[j],row[j-1]);
         j--;

      }
      }
       return ans;
    }
};