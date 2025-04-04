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
    unordered_map<int,int>mp;
    int maxid=0;
     void depth(TreeNode* root,int d){
        if(!root)return;
        mp[root->val]=d;
        maxid=max(maxid,d);
        depth(root->left,d+1);
        depth(root->right,d+1);
     }
     TreeNode* LCA(TreeNode* root) {
        if(!root|| mp[root->val]==maxid)return root;

        TreeNode* l=LCA(root->left);
        TreeNode* r=LCA(root->right);

        if(l&& r)return root;

        return l!=NULL? l:r;
     }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth(root,0);

        return LCA(root);
    }
};