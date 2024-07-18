/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr, right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void makeGraph(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, vector<TreeNode*>>& mp, unordered_set<TreeNode*>& st) {
        if (root == NULL) return;

        if (root->left == NULL && root->right == NULL) {
            st.insert(root);
        }
        if (prev != NULL) {
            mp[root].push_back(prev);
            mp[prev].push_back(root);
        }
        makeGraph(root->left, root, mp, st);
        makeGraph(root->right, root, mp, st);
    }

    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> mp;
        unordered_set<TreeNode*> st;
        makeGraph(root, NULL, mp, st); 
        int ans = 0;
        for (auto& leaf : st) {
            queue<TreeNode*> que;
            unordered_set<TreeNode*> visited;
            que.push(leaf);
            visited.insert(leaf);

            int currentDistance = 0;
            while (!que.empty() && currentDistance < distance) {
                int size = que.size();
                currentDistance++;
                for (int i = 0; i < size; i++) {
                    TreeNode* curr = que.front();
                    que.pop();
                    for (auto neighbor : mp[curr]) {
                        if (!visited.count(neighbor)) {
                            que.push(neighbor);
                            visited.insert(neighbor);
                            if (st.count(neighbor) && neighbor != leaf) {
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        return ans / 2; 
    }
};
