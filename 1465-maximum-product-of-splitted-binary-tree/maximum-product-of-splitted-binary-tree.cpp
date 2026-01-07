class Solution {
public:
    long long maxi = 0;
    int Mod = 1e9 + 7;
    long long total;

    long long total_su(TreeNode* root) {
        if (!root) return 0;
        return root->val + total_su(root->left) + total_su(root->right);
    }

   long long solve(TreeNode* root) {
        if (!root) return 0;

        long long left_sum = solve(root->left);
        long long right_sum = solve(root->right);

        long long cur_sum = root->val + left_sum + right_sum;
        long long rem = total - cur_sum;

        maxi = max(maxi, cur_sum * rem);

        return cur_sum;
    }

    int maxProduct(TreeNode* root) {
       total = total_su(root);  
        solve(root);
        return maxi % Mod;  
    }
};
