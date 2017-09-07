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
//判断二叉树是否是对称的
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot1,TreeNode* pRoot2){
        if(pRoot1==NULL && pRoot2==NULL)//都为空返回真
            return true;
        if(pRoot1==NULL || pRoot2==NULL)//一个为空，另一个不为空返回假
            return false;
        if(pRoot1->val!=pRoot2->val)//对应的值不相等返回假
            return false;
        
        return isSymmetrical(pRoot1->left,pRoot2->right)&& isSymmetrical(pRoot1->right,pRoot2->left);//判断做字数和右子树是否对称，并返回与的结果
            
    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        return isSymmetrical(pRoot,pRoot);
        
    }
    

};