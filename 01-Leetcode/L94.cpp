class Solution {
public:
    vector<int> res;
    void inoder(TreeNode* root){
        if(root == NULL)
            return;
        inoder(root->left);
        res.push_back(root->val);
        inoder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inoder(root);
        return res;
        
    }
};