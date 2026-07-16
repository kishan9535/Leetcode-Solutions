class Solution {
public:
    long long gcdSum(vector<int>& nums) {

      long long ans=0;
      vector<long long>prefgrid;
      int mx=0;
      int n=nums.size();

      for(int i=0;i<n;i++){
        mx=max(mx,nums[i]);
        prefgrid.push_back(__gcd(mx,nums[i])); 
      }
      sort(prefgrid.begin(),prefgrid.end());
      int i=0;
      int j=nums.size()-1;

      while(i<j){
        long long l=prefgrid[i];
        long long r=prefgrid[j];
        ans+=__gcd(l,r);
        i++;
        j--;
      }
      return ans;   
    }
};