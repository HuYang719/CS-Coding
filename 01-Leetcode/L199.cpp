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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<int,TreeNode*>>  q;
        if(root == NULL)
            return vector<int>{};
        q.push({0,root});
        vector<int> res;
        map<int, vector<int>> m;
        m[0] = vector<int>{root->val};
        while(!q.empty()){
            auto tmp = q.front();
            q.pop();
            if(m[tmp.first].empty()==false){
                m[tmp.first].clear();
                m[tmp.first].push_back(tmp.second->val);
            }else{
                m[tmp.first].push_back(tmp.second->val);
            }
            if(tmp.second->left) q.push({tmp.first+1, tmp.second->left});
             if(tmp.second->right) q.push({tmp.first+1, tmp.second->right});
            
        }
        for(auto a:m) {
            res.push_back(a.second[0]);
        }
        return res;
    }
};