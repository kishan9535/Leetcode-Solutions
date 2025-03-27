class Solution {
public:
    int minimumIndex(vector<int>& nums) {
     unordered_map<int,int>mp;
     int n=nums.size();
     for(int i=0;i<nums.size();i++)
     {
         mp[nums[i]]++;
     }
     int me=INT_MIN;
     int cnt=0;
     for(auto t:mp)
     {
         if(t.second*2>n)
         {
         me=t.first;
         cnt=t.second;
         break;
         }
     }
     int l=0;
     for(int i=0;i<n;i++)
     {
         if(nums[i]==me)l++;
         int r=cnt-l;
         if(l*2>i+1 &&r*2>n-1-i) return i;
     }
     

return -1;

    }
};