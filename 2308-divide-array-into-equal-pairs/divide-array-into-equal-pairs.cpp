class Solution {
public:
    bool divideArray(vector<int>& nums) {
       int n=nums.size();
     map<int ,int> m;
     for(int i=0;i<n;i++)
     m[nums[i]]++;
     int t=0;
     for(auto it: m)
     {
         t+=it.second/2;
     }
   return (t==n/2);
    }
};