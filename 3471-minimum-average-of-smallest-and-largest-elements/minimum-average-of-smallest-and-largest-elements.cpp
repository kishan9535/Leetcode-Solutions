class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i=0,j=n-1;
        double ans=INT_MAX;
        while(i<j){
            double min_ele=nums[i];
            double max_ele=nums[j];
            ans=min(ans,(min_ele+max_ele)/2);
            i++;
            j--;
        }
        return ans;
    }
};
