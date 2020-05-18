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
class BSTIterator {
public:
    int cnt;
    vector<int> value;
    void inorder(TreeNode* root) {
        if(root == NULL) return;
        inorder(root->left);
        value.push_back(root->val);
        inorder(root->right);
        
    }
    BSTIterator(TreeNode* root) {
        cnt = 0;
        inorder(root);
    }
    
    /** @return the next smallest number */
    int next() {
        int v = value[cnt];
        if(cnt < value.size())
            cnt++;
        return v;
        
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(cnt < value.size())
            return true;
        else return false;
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

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
class BSTIterator {
public:
    stack<TreeNode*> s;
    void leftmostInorder(TreeNode* root) {
        while(root != NULL) {
            s.push(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        leftmostInorder(root);
        
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* topmostNode = s.top();
        s.pop();
        if(topmostNode->right != NULL) {
            leftmostInorder(topmostNode->right);
        }
        return topmostNode->val;
        
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return s.size()>0;
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */