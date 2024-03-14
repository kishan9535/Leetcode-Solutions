class Solution {
public:
    int longestContinuousSubstring(string s) {
     int n=s.length();
     vector<int>nums(n,0);
     for(int i=0;i<n;i++){
        nums[i]=s[i]-'0';
     }
     int ans=0;
     int i=0;
       while (i < n) {
        int cnt = 1; // Initialize count for the current substring
        while (i < n - 1 && nums[i]+1 == nums[i + 1]) {
            cnt++; // Extend the current substring
            i++;
        }
        ans = max(ans,cnt); // Update the maximum length
        i++;
    }
     return ans;    
    }
};