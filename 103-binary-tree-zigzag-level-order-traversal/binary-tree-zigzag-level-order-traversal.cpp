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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>qu;
        if(!root)return {};
        vector<vector<int>>ans;
        qu.push(root);
        int flag=0;
        while(!qu.empty()){
            int sz=qu.size();
            vector<int>v(sz);
          for(int i=0;i<sz;i++){
              TreeNode* tmp=qu.front();
              qu.pop();
              if(flag==0){
                  v[i]=tmp->val;
              }
              else{
                  v[sz-i-1]=tmp->val;
              }
            if(tmp->left)qu.push(tmp->left);
            if(tmp->right)qu.push(tmp->right);

          }
          ans.push_back(v);
          flag=!flag;
         }
         return ans;
    }
};