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
    int ans = 0;
    int depth(TreeNode* node) {
        if(node == nullptr) return 0;
        int L = depth(node->left);
        int R = depth(node->right);
        ans = max(ans, L+R);
        return max(L, R)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {

        depth(root);
        return ans;
        
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)