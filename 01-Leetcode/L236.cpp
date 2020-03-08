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
    TreeNode* ans;
    
    bool recurseTree(TreeNode* currentNode, TreeNode* p, TreeNode* q) {
        if (currentNode == nullptr) {
            return false;
        }
        
        int left = recurseTree(currentNode->left, p, q)? 1: 0;
        int right = recurseTree(currentNode->right, p, q)? 1:0;
        int mid = (currentNode == p || currentNode == q)? 1:0;
        
        if(left + right +mid >= 2) {
           ans = currentNode;
        }
        
        return (left+right+mid > 0);
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        recurseTree(root, p, q);
        return ans;
        
    }
};