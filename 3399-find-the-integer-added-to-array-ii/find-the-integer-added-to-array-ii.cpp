class Solution {
public:

     bool isPossible(vector<int>& nums1, vector<int>& nums2,int diff){
         int count=0;
         int j=0;
         for(int i=0;i<nums1.size() && j< nums2.size();i++){
            if(nums1[i]+diff!=nums2[j])count++;
            else j++;
         }
         return (count<=2);
     }

    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int ans=10000;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n1=nums1.size();

        for(int i=0;i<n1;i++){
            int diff=nums2[0]-nums1[i];
            if(isPossible(nums1,nums2,diff)){
                ans=min(ans,diff);
            }
        }
        return ans;
    }
};