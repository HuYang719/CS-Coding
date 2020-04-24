class Solution {
public:
    TreeNode* divide(vector<int>& preorder, vector<int>& inorder,int lp,int rp,int li,int ri){
        if(lp>rp) return NULL;
        TreeNode* root = new TreeNode(preorder[lp]);
        // find in inorder [li,ri]
        for(int i=li; i<=ri;i++){
            if(inorder[i]==preorder[lp]){
                //已知root在inorder中位置为i，则左子树有i-1-li+1(包含i-1和li，要加1)个元素，而preorder从lp+1算起的i-li个元素
                root->left = divide(preorder,inorder,lp+1,lp+i-li,li,i-1);
                root->right = divide(preorder,inorder, lp+i-li+1,rp,i+1,ri);
            }
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return divide(preorder,inorder,0,int(preorder.size())-1,0,int(inorder.size())-1);
        
    }
};