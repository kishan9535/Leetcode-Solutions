class Solution {
public:
    vector<string> col_states;
    int MOD = 1e9 + 7;
    vector<vector<int>> t;
    int m;

    void generatecol_states(string curr, char prev, int l, int m) {
        if (l == m) {
            col_states.push_back(curr);
            return;
        }
        string r = "RGB";
        for (auto it : r) {
            if (prev == it) continue;
            generatecol_states(curr + it, it, l + 1, m);
        }
    }

    int solve(int remcol, int previdx) {
        if (remcol == 0) return 1;
        if (t[remcol][previdx] != -1) return t[remcol][previdx];

        int ways = 0;
        string prevstate = col_states[previdx];

        for (int i = 0; i < col_states.size(); i++) {
            if (i == previdx) continue;
            string currstate = col_states[i];
            bool valid = true;

            for (int j = 0; j < m; j++) {
                if (prevstate[j] == currstate[j]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ways = (ways + solve(remcol - 1, i)) % MOD;
            }
        }

        return t[remcol][previdx] = ways;
    }

    int colorTheGrid(int m_input, int n) {
        m = m_input;
        generatecol_states("", '#', 0, m);

        int totalstates = col_states.size();
        t = vector<vector<int>>(n, vector<int>(totalstates, -1));

        int ans = 0;
        for (int i = 0; i < totalstates; i++) {
            ans = (ans + solve(n - 1, i)) % MOD;
        }

        return ans;
    }
};
