class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        double ans = 0;
        int n = quality.size();
        vector<pair<double, int>> wr(n); // wr -> means workers ratio.
        for (int i = 0; i < n; i++) {
            double r = (double)wage[i] / quality[i];
            wr[i] = make_pair(r, quality[i]);
        }
        sort(wr.begin(), wr.end());
        priority_queue<int, vector<int>> pq;
        double prefix_sum = 0;
        for (int i = 0; i < k; i++) {
            prefix_sum += wr[i].second;
            pq.push(wr[i].second);
        }
        double man_ratio = wr[k - 1].first;
        ans = man_ratio * prefix_sum;

        for (int i = k; i < n; i++) {
            man_ratio = wr[i].first;
            pq.push(wr[i].second);
            prefix_sum += wr[i].second;

            if (pq.size() > k) {
                prefix_sum -= pq.top();
                pq.pop();
            }
            ans = min(ans, man_ratio * prefix_sum);
        }
        return ans;
    }
};
