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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        map<int, vector<int>> m;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        while(!q.empty()) {
            auto a = q.front();
            q.pop();
            m[a.first].push_back(a.second->val); // m[id] means the same level
            if(a.second->left) q.push({a.first-1, a.second->left});
            if(a.second->right) q.push({a.first+1, a.second->right});
        }
        for (auto a: m) {
            res.push_back(a.second); //a is new variable
        }
        return res;
        
    }
};


