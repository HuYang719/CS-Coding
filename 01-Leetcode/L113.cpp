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
    vector<vector<int>> ans;
    int summ=0;
    void calHeight(TreeNode* root, vector<int>& ary, int curnum){
        if(root==NULL) return ;
        if(root->left==NULL&&root->right==NULL){
            if(curnum==summ){
                ans.push_back(ary);
            }
        }
        vector<int> arynext=ary;
        bool hasleft = false;
        if(root->left!=NULL){
            hasleft = true;
            arynext.push_back((root->left)->val);
            calHeight(root->left,arynext,(root->left)->val+curnum);
        }
        if(root->right!=NULL){
            if(hasleft == true) arynext.pop_back();
            arynext.push_back((root->right)->val);
            calHeight(root->right,arynext,(root->right)->val+curnum);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        summ=sum;
        if(root==NULL) return vector<vector<int>>();
        vector<int> ary;
        ary.push_back(root->val);
        calHeight(root,ary,root->val);
        return ans;
        
    }
};