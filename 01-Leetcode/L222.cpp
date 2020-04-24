/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root) {
        if(root == NULL)
            return 0;
        int ans = 1;
        ans += dfs(root->left);
        ans += dfs(root->right);
        return ans;
    }
    int countNodes(TreeNode* root) {
        int ans = dfs(root);
        return ans;
        
    }
};