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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        bool seennull = false; //这个是判断的一个关键
        while(!que.empty()) {
            TreeNode *cur = que.front();
            que.pop();
            if(cur == NULL) {
                if(!seennull) seennull = true;
                continue;
            }else { //cur != NULL
                if(seennull == true) return false;
            }
            que.push(cur->left); //if left is null, push null and check in the next //round, if we found it is null, seennull = true. if right is not null, return //false.
            que.push(cur->right);
        }
        return true;
        
    }
};