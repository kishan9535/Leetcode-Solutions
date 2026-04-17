class Solution {
public:
   
  void reverse(int &num){
    if(num==0)return ;
    int r=0;
    while(num!=0){
        int l=num%10;
        r=(r*10)+l;
        num/=10;

    }
    num=r;
    return;
  }
  
    int minMirrorPairDistance(vector<int>& nums) {
     int n=nums.size();
     int ans=INT_MAX;
     unordered_map<int,int>mp;
     
     for(int i=0;i<n;i++){
      int rev=nums[i];
      reverse(rev);
      cout<<rev<<endl;
      
      if(i==0){
        mp[rev]=0;
        continue;
      }
      if(mp.count(nums[i])){
        ans=min(ans,(abs(mp[nums[i]]-i)));
      }
      mp[rev]=i;
     } 
     return ans==INT_MAX?-1:ans;
    }
};