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

    int maxLevelSum(TreeNode* root) {
     int ans=0,level=0,max_sum=INT_MIN;
     if(!root)return 0;
     queue<TreeNode*> qu;
     qu.push(root);
     while(!qu.empty()){
         int cnt=qu.size(),tmp_sum=0;
         while(cnt--){
             TreeNode* t=qu.front();
             qu.pop();
             tmp_sum+=t->val;
             if(t->left)qu.push(t->left);
             if(t->right)qu.push(t->right);
         }
         level++;
         if(tmp_sum>max_sum)ans=level;
         max_sum=max(max_sum,tmp_sum);
     }
     return ans;
    }
};