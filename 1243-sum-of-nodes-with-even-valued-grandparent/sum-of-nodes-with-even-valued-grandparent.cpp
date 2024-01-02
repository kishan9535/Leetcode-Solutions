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
void dfs(TreeNode* cur,TreeNode *parent,TreeNode* grandpa){
    if(!cur) return;
    if(grandpa && grandpa->val%2==0){
        ans+=cur->val;
    }
    dfs(cur->left,cur,parent);
    dfs(cur->right,cur,parent);
}
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root,NULL,NULL);
        return ans;
        
    }
};