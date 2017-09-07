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
    TreeNode* KthNodeCore(TreeNode* pRoot,int& k){//这里必须是引用，否则k没有更新，结果错误
        TreeNode* target=NULL;
        
        if(pRoot->left)
            target=KthNodeCore(pRoot->left,k);
        
        if(target==NULL){
            if(k==1)
                target=pRoot;
            --k;
        }
        
        if(target==NULL && pRoot->right!=NULL)
            target=KthNodeCore(pRoot->right,k);
        
        return target;
    }
    
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==NULL || k==0)
            return NULL;
        
        return KthNodeCore(pRoot,k);
    }
};