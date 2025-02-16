class Solution {
public:
    bool solve(int i, int n, vector<int> &res, vector<bool> &used) {
        if(i == res.size())
            return true;
        
        if(res[i] != -1)
            return solve(i + 1, n, res, used);

        for(int num = n; num >= 1; num--) {
            if(used[num]) continue;
            used[num] = true;
            res[i] = num;
            if(num == 1) {
                if(solve(i + 1, n, res, used)) 
                    return true;
            } else {
                int j = i + num; 
                if(j < res.size() && res[j] == -1) {
                    res[j] = num;
                    if(solve(i + 1, n, res, used))
                        return true;
                    res[j] = -1;
                }
            }
            used[num] = false;
            res[i] = -1;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> res(n * 2 - 1, -1);
        vector<bool> used(n + 1, false);
        solve(0, n, res, used);
        return res;
    } 
};