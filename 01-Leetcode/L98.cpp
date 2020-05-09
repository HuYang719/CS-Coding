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
    bool helper(TreeNode* node, int lower_limit, int upper_limit){
        if(node==NULL) return true;
        if((lower_limit!=-1)  && (node->val <=lower_limit))
            return false;
        if((upper_limit!=-1)&&(upper_limit<=node->val))
            return false;
        bool left = node->left!=NULL? helper(node->left,lower_limit,node->val):true;
        bool right=node->right!=NULL? helper(node->right,node->val,upper_limit):true;
        return left&&right;
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        return helper(root,-1,-1);
        
    }
};