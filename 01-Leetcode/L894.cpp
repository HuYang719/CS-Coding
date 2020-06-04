/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<TreeNode*>> memo;　 
    vector<TreeNode*> allPossibleFBT(int N) {
        if(memo.find(N) == memo.end()) {
            vector<TreeNode*> ans;
            if(N == 1) {
                TreeNode* bns = new TreeNode(0);
                ans.push_back(bns);
            } else if(N % 2 == 1) {
                for(int x = 0; x < N; ++x) {
                    int y = N - 1 - x;
                    for(auto left: allPossibleFBT(x)) {
                        for(auto right: allPossibleFBT(y)){
                            TreeNode* bns = new TreeNode(0);
                            bns->left = left;
                            bns->right = right;
                            ans.push_back(bns);
                        }
                    }
                }
               
            }
             memo[N] = ans;
        }
        
        return memo[N];
    }
};