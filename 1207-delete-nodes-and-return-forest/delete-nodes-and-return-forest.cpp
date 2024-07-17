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

     TreeNode* delete_Nodes(TreeNode* root,unordered_set<int>&st,vector<TreeNode*>&ans){
        if(root==NULL)return NULL;

        root->left=delete_Nodes(root->left,st,ans);
        root->right=delete_Nodes(root->right,st,ans);

        if(st.find(root->val)!=st.end()){
            if(root->left!=NULL){
                ans.push_back(root->left);
            }
            if(root->right!=NULL){
                ans.push_back(root->right);
            }
            return NULL;
        }
        return root;
     }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
       vector<TreeNode*>ans;
       unordered_set<int>st;
       for(auto i:to_delete){
        st.insert(i);
       }
       delete_Nodes(root,st,ans); 
    
    if(st.find(root->val)==st.end()){
        ans.push_back(root);
        return ans;
    }
    return ans;
    }
};