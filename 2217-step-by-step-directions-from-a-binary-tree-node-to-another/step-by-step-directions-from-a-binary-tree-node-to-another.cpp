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

   bool find_path(TreeNode* root ,int target,string &path){
    if(root==NULL)return false;
    if(root->val==target)return true;
    path.push_back('L');
    if(find_path(root->left,target,path)==true){
        return true;
    }
    path.pop_back();
    path.push_back('R');
    if(find_path(root->right,target,path)==true){
       return true;
   }
   path.pop_back();
   return false;
   }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        string rootToDes="";
        string rootToSta="";

        find_path(root,startValue,rootToSta);
        find_path(root,destValue,rootToDes);

        string ans="";

        int i=0,j=0;
        while(i<rootToSta.length() && j<rootToDes.length() &&rootToSta[i]==rootToDes[j]){
            i++;
            j++;
        }
         
        for (int l = i; l < rootToSta.length(); l++) {
            ans.push_back('U');
        }
        
        for(int l=i;l<rootToDes.length();l++){
            ans.push_back(rootToDes[l]);
        }
       return ans;
    }
};