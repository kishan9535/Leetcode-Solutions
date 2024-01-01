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
    vector<int>ans;
    void dfs(TreeNode* root){
        if(!root)return;
        ans.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
      if(!root)return 0;
      dfs(root); 
      sort(ans.begin(),ans.end());
      return ans[k-1];
    }
};