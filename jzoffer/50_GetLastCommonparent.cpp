/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //求给定二叉搜索树中给定两个节点的最低公共祖先
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val<root->val && q->val<root->val)//两个节点的值都比根节点小，递归左子树
            return lowestCommonAncestor(root->left,p,q);
        if(p->val>root->val && q->val>root->val)//否则递归右子树
            return lowestCommonAncestor(root->right,p,q);
        
        return root;//返回当前递归跳出的结点，不满足同小于或同大于
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //求给定二叉树中的最低公共祖先
class Solution {
public://如果当前子树包含p,q，结果就是LCA;如果他们中的一个是子树，结果就是自己，如果都不在子树里面，结果就是空
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) //当前的根节点是空的或者p等于根节点或者q等于根节点
			return root;

        TreeNode* left=lowestCommonAncestor(root->left,p,q);//递归左子树得到根
        TreeNode* right=lowestCommonAncestor(root->right,p,q);//递归右子树得到根
        
        if(!left)//若左孩子空返回右孩子
            return right;
        else if(!right && left)//若左孩子不为空，但右孩子为空，返回左孩子
            return left;
        else//若左右孩子都不为空返回根节点，即包含p\q
            return root;
        //return !left ? right : !right ? left : root;
    }
};

