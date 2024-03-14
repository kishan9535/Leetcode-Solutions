class Solution {
public:
    int longestContinuousSubstring(string s) {
       int n = s.length();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int cnt = 1; // Initialize count for the current substring
            while (i < n - 1 && s[i] + 1 == s[i + 1]) {
                cnt++; // Extend the current substring
                i++;
            }
            ans = max(ans, cnt); // Update the maximum length
        }

        return ans;  
    }
};