/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        queue<TreeNode*> q;
        if(pRoot == NULL)
            return vector<vector<int>>();
        q.push(pRoot);
        vector<vector<int>> ans;
        while(!q.empty()) {
            int s = q.size();
            vector<int> v;
            while(s--){
               auto tmp = q.front();
               q.pop();
               v.push_back(tmp->val);
               if(tmp->left) q.push(tmp->left);
               if(tmp->right) q.push(tmp->right);
            }
            ans.push_back(v);
            
        }
        for(int i = 0; i < ans.size(); i++){
            if(i%2 == 1)
                reverse(ans[i].begin(), ans[i].end());
        }
          return ans;
        
    }
    
};