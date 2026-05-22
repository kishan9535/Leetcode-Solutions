class Solution {
public:

 int findPivot(vector<int>&nums,int &n)
 {
   int l=0,r=n-1;
   while(l<r)
   {
     int m=l+(r-l)/2;
     if(nums[m]>nums[r])
     {
       l=m+1;
     }
     else r=m;
   }
   return r;
 }






    int binary_s(vector<int>&nums,int target,int s,int e)
    {
      int idx=-1;
      while(s<=e)
      {
        int m=s+(e-s)/2;
        if(nums[m]==target)
        {
          idx=m;
          break;

        } 
        else if(nums[m]<target)
        {
          s=m+1;
        }
        else e=m-1;
      }
      return idx;
    }
    int search(vector<int>& nums, int target) {
     int n=nums.size();
     int p=findPivot(nums,n);
      int idx=binary_s(nums,target,0,p-1);
      if(idx!=-1) return idx;
      idx=binary_s(nums,target,p,n-1);


     return idx;
    }
};