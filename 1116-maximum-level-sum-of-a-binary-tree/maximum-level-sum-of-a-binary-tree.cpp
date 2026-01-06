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
       int min_level=1;
       int max_sum=INT_MIN;

       queue<TreeNode*>que;
       que.push(root);
       int level=1;
       while(!que.empty()){
          int n=que.size();
          int sum=0;
          while(n--){
            auto it=que.front();
            if(it->left){
                que.push(it->left);
            }
            if(it->right){
               que.push(it->right);
            }
            sum+=it->val;
            que.pop();
          }
          if(sum>max_sum){
            max_sum=sum;
            min_level=level;
          }
          level++;
       }
      return min_level;
    }
};