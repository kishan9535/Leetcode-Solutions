class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

      int  n=customers.size();
      int max_grumpy=0;
      for(int i=0;i<minutes;i++){
        max_grumpy+=customers[i]*grumpy[i];
      }
      int curr=max_grumpy;
      int i=0;
      int j=minutes;

      while(j<n){
         curr+=customers[j]*grumpy[j];
         curr-=customers[i]*grumpy[i];

         max_grumpy=max(max_grumpy,curr);
         i++;
         j++;
      }
      int ans=max_grumpy;
      for(int i=0;i<n;i++){
        if(grumpy[i]==0){
            ans+=customers[i];
        }
      }
      return ans;   
    }
};