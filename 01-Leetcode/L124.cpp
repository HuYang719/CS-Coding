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
    int max_sum = INT_MIN;
    int max_gain(TreeNode* node) {
        if (node == nullptr) return 0;
        
        int left = max(max_gain(node->left), 0);
        int right =max(max_gain(node->right), 0);
        int new_price = node->val + left + right;
        
        max_sum = max(max_sum, new_price);
        
        // 注意只能返回一边
        return node->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        max_gain(root);
        return max_sum;
        
    }
};