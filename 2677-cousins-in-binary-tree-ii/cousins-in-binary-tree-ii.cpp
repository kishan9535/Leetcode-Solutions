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
    TreeNode* replaceValueInTree(TreeNode* root) {
      if(!root)return root;

      queue<TreeNode*>que;
      que.push(root);
      int level_sum=root->val;

      while(!que.empty()){
          int n=que.size();
          int next_level_sum=0;
          while(n--){
            TreeNode* curr=que.front();
            que.pop();
            curr->val=level_sum-curr->val;

            int sib_sum=(curr->left!=NULL ?curr->left->val:0);
            sib_sum+=(curr->right!=NULL ? curr->right->val:0);
            
            if(curr->left){
                 next_level_sum+=curr->left->val;
                curr->left->val=sib_sum;
                
                que.push(curr->left);
            }
            if(curr->right){
                  next_level_sum+=curr->right->val;
                curr->right->val=sib_sum;
                
                que.push(curr->right);
            }
            
          }
          level_sum=next_level_sum;
      }
      return root;  
    }
};