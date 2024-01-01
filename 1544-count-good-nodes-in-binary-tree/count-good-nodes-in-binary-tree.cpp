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
int cnt=0;
    void dfs(TreeNode* root,int key){
        if(!root)return;
        if(root->val>=key){
         key=root->val; 
         cnt++;  
        }
        if(root->left)dfs(root->left,key);
        if(root->right)dfs(root->right,key);
        return;
    }

    int goodNodes(TreeNode* root) {
        if(!root)return 0;
      int key=root->val;    
       dfs(root,key);
       return cnt;
    }
};