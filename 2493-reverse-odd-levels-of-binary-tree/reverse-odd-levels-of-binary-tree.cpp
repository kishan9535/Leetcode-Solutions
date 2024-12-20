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
    TreeNode* reverseOddLevels(TreeNode* root) {
      vector<vector<int>>vec;
      queue<TreeNode*>que;
      que.push(root);
      int level=1;
      
      while(!que.empty()){
        int n=que.size();
        bool flag=false;
        if(level%2==0){
            flag=true;
        }
        vector<int>v;
        while(n--){
          TreeNode* node=que.front();
          que.pop();
          if(flag){
            v.push_back(node->val);
          }
          if(node->left){
            que.push(node->left);
          }
          if(node->right){
            que.push(node->right);
          }
        }
        level++;
        if(flag){
        reverse(v.begin(),v.end());
        vec.push_back(v);
        }
      }
    level = 1;
int idx = -1;
que.push(root);

while (!que.empty()) {
    int n = que.size();
    bool flag = false;
    if (level % 2 == 0) {
        flag = true;
        idx++;
    }

    vector<int> v = (flag && idx < vec.size()) ? vec[idx] : vector<int>();
    int i = 0;

    while (n--) {
        TreeNode* node = que.front();
        que.pop();

        if (flag && i < v.size()) {
            node->val = v[i];
            i++;
        }

        if (node->left) que.push(node->left);
        if (node->right) que.push(node->right);
    }
    level++;
}

      for(auto it:vec){
        for(auto i :it){
            cout<<i<<" ";
        }
        cout<<endl;
      }
      return root;
    }
};