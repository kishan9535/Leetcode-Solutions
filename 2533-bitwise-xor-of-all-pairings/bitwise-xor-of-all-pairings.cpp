class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
       int ans=0;
       int n=nums1.size();
       int m=nums2.size();
       unordered_map<int,long>mp;
       for(auto it:nums1){
        mp[it]+=m;
       }
       for(auto it: nums2){
        mp[it]+=n;
       }
       for(auto it: mp){
        if(it.second%2!=0){
            ans^=it.first;
        }
       }
       return ans; 
    }
};