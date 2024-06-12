class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c1,c0,c2;
        c1=0,c2=0,c0=0;

       for(int i=0;i<nums.size();i++)
       {
           if(nums[i]==1)
           c1++;
          else  if(nums[i]==0)
           c0++;

           else if(nums[i]==2)
           {
           c2++;
           }

       }
        nums.clear();
       for(int i=0;i<c0;i++)
       nums.push_back(0);
        for(int i=0;i<c1;i++)
       nums.push_back(1);
        for(int i=0;i<c2;i++)
       nums.push_back(2);
        
    }
};