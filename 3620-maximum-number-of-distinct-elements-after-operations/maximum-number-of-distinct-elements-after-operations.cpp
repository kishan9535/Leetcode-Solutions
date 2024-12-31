class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
     sort(nums.begin(),nums.end());
     int mini=INT_MIN;
     int cnt=0;
     for(auto it: nums){
        int low=it-k;
        int hig=it+k;
        if(mini+1>=low && mini+1<=hig){
            cnt++;
            mini=mini+1;
        }
        else if(low>mini){
           cnt++;
           mini=low;
        }
     }
     return cnt;
    }
};