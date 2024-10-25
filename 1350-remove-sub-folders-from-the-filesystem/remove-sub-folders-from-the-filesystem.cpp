class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Sort folders lexicographically
        sort(folder.begin(), folder.end());
        
        vector<string> ans;
        string prevFolder = "";

        for (const auto& f : folder) {
            // Check if `f` starts with `prevFolder` followed by `/`, meaning it is a subfolder
            if (prevFolder.empty() || f.find(prevFolder + "/") != 0) {
                ans.push_back(f);  // Add current folder since it’s not a subfolder
                prevFolder = f;    // Update `prevFolder` to the current folder
            }
        }

        return ans;
    }
};
