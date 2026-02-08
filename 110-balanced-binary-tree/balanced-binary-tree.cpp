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

  int height(TreeNode* root){
    if(!root)return 0;

    int lh=height(root->left);
    int rh=height(root->right);

    return max(lh,rh)+1;
  }


class Solution {
public:
    bool isBalanced(TreeNode* root) {

       if(!root)return true;

       int l_height=height(root->left);
       int r_height=height(root->right);

       if(abs(l_height-r_height)>1) return false;

       return isBalanced(root->left)&& isBalanced(root->right);  
    }
};