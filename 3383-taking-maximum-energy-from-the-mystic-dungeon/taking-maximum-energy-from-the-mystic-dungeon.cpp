class Solution {
public:
    int n;
    vector<int> dp;

    int solve(int idx, vector<int>& energy, int k) {
        if (idx >= n) return 0;
        if (dp[idx] != -1) return dp[idx]; // Return stored result if available
        int pick = energy[idx] + solve(idx + k, energy, k);
        return dp[idx] = pick; // Store result before returning
    }

    int maximumEnergy(vector<int>& energy, int k) {
        n = energy.size();
        dp = vector<int>(n, -1); // Initialize dp vector with -1
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) { // Loop through all starting points
            maxi = max(maxi, solve(i, energy, k));
        }
        return maxi;
    }
};
