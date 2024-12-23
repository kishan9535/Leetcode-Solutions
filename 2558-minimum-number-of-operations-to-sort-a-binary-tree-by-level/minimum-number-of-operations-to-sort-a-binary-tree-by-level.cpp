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
    int minimumOperations(TreeNode* root) {
      int swaps=0;
      queue<TreeNode*>que;
      que.push(root);
      while(!que.empty()){
         int n=que.size();
         vector<int>vec;
         unordered_map<int,int>mp;
         while(n--){
            TreeNode* node=que.front();
            que.pop();
            vec.push_back(node->val);
            if(node->left){
                que.push(node->left);
            }
            if(node->right){
                que.push(node->right);
            }
         }
         vector<int>temp(vec.begin(),vec.end());
         sort(temp.begin(),temp.end());
         int k=vec.size();
         for(int i=0;i<k;i++){
            mp[vec[i]]=i;
         }
         for(int i=0;i<k;i++){
            if(vec[i]!=temp[i]){
                int idx=mp[temp[i]];
                mp[vec[i]]=idx;
                swap(vec[i],vec[idx]);
                swaps++; 
            }
         }

      }
      return swaps; 
    }
};