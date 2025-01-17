class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<int> original(n,0);

        for(int i=1; i<n; i++) {
            original[i] = derived[i-1] ^ original[i-1];
        }

        if(original[n-1] ^ original[0] == derived[n-1]) return true;

        original[0] = 1;
        for(int i=1; i<n; i++) {
            original[i] = derived[i-1] ^ original[i-1];
        }

        if(original[n-1] ^ original[0] == derived[n-1]) return true;

        return false;
    }
};