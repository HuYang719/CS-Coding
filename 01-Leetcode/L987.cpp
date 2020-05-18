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
    void dfs(TreeNode* root, int x, int y, vector<tuple<int,int,int>>& v){
        if(root==NULL)
            return;
        auto vi = make_tuple(x,y,root->val);
        v.push_back(vi);
        dfs(root->left,x-1,y+1,v); //因为要从小到大进行排序，所以应该是y+1
        dfs(root->right,x+1,y+1,v);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL)
            return vector<vector<int>>();
        vector<tuple<int,int,int>> v;
        vector<vector<int>> ans;
        dfs(root,0,0,v);
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();){ //这里不应该再有i++了，只需要将i=j即可，否则会省略一个Node
            int j=i;
            vector<int> ansi;
            while(j<v.size()&&get<0>(v[i])==get<0>(v[j])){
                ansi.push_back(get<2>(v[j]));
                j++;
            }
            ans.push_back(ansi);
            i = j;
        }
        
        return ans;
    }
};