class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> v1,v2,v3;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<pivot)
            v1.push_back(nums[i]);
            else if(nums[i]==pivot)
            v3.push_back(nums[i]);
            else if(nums[i]>pivot)
            v2.push_back(nums[i]);

        }
        nums.clear();
        nums.insert(nums.begin(),v1.begin(),v1.end());
        nums.insert(nums.end(),v3.begin(),v3.end());
        nums.insert(nums.end(),v2.begin(),v2.end());
        return nums;
    }
};