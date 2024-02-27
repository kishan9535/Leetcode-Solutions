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
    int solve( TreeNode* root, int & ans){
      
      if(root==NULL) return 0;
     int left=solve(root->left,ans);
     int right=solve(root->right,ans);

     ans=max(ans,left+right);

      return max(left,right)+1;
    }


    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;

        int ans=INT_MIN;
        solve(root,ans);
        return ans;
    }
};