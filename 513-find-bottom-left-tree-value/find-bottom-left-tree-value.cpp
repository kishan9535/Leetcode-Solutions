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
   int ans=0;
   int rootn0=-1;
    void dfs(TreeNode* root, int num){
        if(!root)return;
       
       if(num>rootn0){
           rootn0=num;
           ans=root->val;
       }
       dfs(root->left,num+1);
       dfs(root->right,num+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return -1;
        dfs(root,0);
        return ans;
    }
};