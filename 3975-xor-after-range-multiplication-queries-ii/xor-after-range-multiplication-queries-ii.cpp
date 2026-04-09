class Solution {
public:
    int M=1e9+7;
     long long power(long long a, long long b){
       if(b==0)return 1;


       long long h=power(a,b/2);
       long long ans=(h*h)%M;

       if(b%2==1){
        ans=(ans*a)%M;
       }
       return ans;
     }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
       int n=nums.size();
       int bs=ceil(sqrt(n));
       int ans=0;

       unordered_map<int,vector<vector<int>>>mp;

       for(auto it: queries){
         int l=it[0];
         int r=it[1];
         int k=it[2];
         int v=it[3];

         if(k>=bs){
          for(int i=l;i<=r;i+=k){
            nums[i]=(1LL* nums[i]*v)%M;
          }
         }
         else{
            mp[k].push_back(it);
         }
       }

       for(auto& [K,aq]:mp){
          vector<long long>dif(n,1);

          for(auto q:aq){
             int l=q[0];
             int r=q[1];
             int v=q[3];

             dif[l]=(dif[l]*v)%M;

             int steps=(r-l)/K;
             int next=l+(steps+1)*K;

            if(next<n){
             dif[next]=(dif[next]*power(v,M-2))%M;
            }
          }

            for(int i=0;i<n;i++){
               if(i-K>=0){
                dif[i]=(dif[i]*dif[i-K])%M;
               }
            }

            for(int i=0;i<n;i++){
                nums[i]=(1LL*nums[i]*dif[i])%M;
            }
          
       }

       for(int i=0;i<n;i++){
        ans^=nums[i];
       }
       return ans;  
    }
};