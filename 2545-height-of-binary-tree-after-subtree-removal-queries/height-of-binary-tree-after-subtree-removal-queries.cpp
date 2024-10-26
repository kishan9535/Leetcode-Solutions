/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int level[100001] = {0};
    int height[100001] = {0};
    int level_m[100001] = {0};
    int level_sm[100001] = {0};

    int find_Height(TreeNode* root, int lev) {
        if (!root) return 0;

        level[root->val] = lev;
        height[root->val] = max(find_Height(root->left, lev + 1), find_Height(root->right, lev + 1)) + 1;

        if (level_m[lev] < height[root->val]) {
            level_sm[lev] = level_m[lev];
            level_m[lev] = height[root->val];
        } else if (level_sm[lev] < height[root->val]) {
            level_sm[lev] = height[root->val];
        }

        return height[root->val];
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        find_Height(root, 0);

        vector<int> ans;
        for (auto &it : queries) {
            int node_level = level[it];
            int lev_h = level_m[node_level];

            if (lev_h == height[it]) {
                lev_h = level_sm[node_level];
            }

            int tot_h = node_level + lev_h - 1;
            ans.push_back(tot_h);
        }

        return ans;
    }
};