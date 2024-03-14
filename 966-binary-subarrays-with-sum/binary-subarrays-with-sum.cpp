class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
    int cnt=0;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        int s=nums[i];
        if(s==goal)cnt++;
        for(int j=i+1;j<n;j++)
        {
            s+=nums[j];
            if(s==goal)cnt++;
        }
    }
    return cnt;    
    }
};