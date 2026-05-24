class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> steps(n, 1);
        vector<int> stack;
        for (int i = 0; i <= n; i++) {
            while (!stack.empty() && (i == n || arr[stack.back()] < arr[i])) {
                vector<int> pop_indices;
                pop_indices.push_back(stack.back());
                stack.pop_back();
                while (!stack.empty() && arr[stack.back()] == arr[pop_indices[0]]) {
                    pop_indices.push_back(stack.back());
                    stack.pop_back();
                }
                for (int j : pop_indices) {
                    if (i < n && i - j <= d) {
                        steps[i] = max(steps[i], steps[j] + 1);
                    }
                    if (!stack.empty() && j - stack.back() <= d) {
                        steps[stack.back()] = max(steps[stack.back()], steps[j] + 1);
                    }
                }
            }
            if (i < n) {
                stack.push_back(i);
            }
        }
        return *max_element(steps.begin(), steps.end());
    }
};