class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int MOD = 1e9 + 7;

      
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> heights;
        unordered_set<int> widths;

        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                heights.insert(vFences[j] - vFences[i]);
            }
        }

        long long ans = -1;

        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                int diff = hFences[j] - hFences[i];
                if (heights.count(diff)) {
                    long long area = 1LL * diff * diff;
                    ans = max(ans, area);
                }
            }
        }

        if (ans == -1) return -1;
        return ans % MOD;
    }
};
