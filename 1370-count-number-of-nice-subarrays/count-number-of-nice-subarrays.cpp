class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
     int ans=0;
     int odd_count=0;
     int n=nums.size();
     int i=0,j=0;
     int count=0;

     while(j<n){

        if(nums[j]%2!=0){
            odd_count++;
            count=0;
        }
        while(odd_count==k){
            count++;
            if(i<n && nums[i]%2!=0){
                odd_count--;
            }
            i++;
        }
        j++;
        ans+=count;
     } 
     return ans;  
    }
};