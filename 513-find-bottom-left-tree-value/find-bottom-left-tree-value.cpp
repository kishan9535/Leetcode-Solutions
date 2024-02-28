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
    int findBottomLeftValue(TreeNode* root) {
     queue<TreeNode*>que;
     int ans=-1;
     que.push(root);
     while(!que.empty()){
         TreeNode* nod=que.front();
         que.pop();
         ans=nod->val;
         if(nod->right){
             que.push(nod->right);
             
         }
         if(nod->left){
             que.push(nod->left);
             
         }
     }
     return ans;   
    }
};