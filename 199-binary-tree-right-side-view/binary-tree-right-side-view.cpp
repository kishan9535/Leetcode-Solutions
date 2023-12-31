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
    vector<int> rightSideView(TreeNode* root) {
     vector<int> ans;
     queue<TreeNode*>qu;
     if(!root) return ans;
     qu.push(root);
     while(!qu.empty()){
         ans.push_back(qu.back()->val);
         for(int i=qu.size();i>0;i--){
             TreeNode* nod=qu.front();
             qu.pop();
             if(nod->left)qu.push(nod->left);
             if(nod->right)qu.push(nod->right);
         }
     } 
     return ans;
    }
};