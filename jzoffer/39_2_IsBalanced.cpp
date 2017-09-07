//判断二叉树是否平衡
class Solution {
public:
//先求二叉树的深度
    int TreeDepth(TreeNode* pRoot){
        if(pRoot==NULL)
            return 0;
        
        int le=TreeDepth(pRoot->left);
        int ri=TreeDepth(pRoot->right);
        
        return le>ri?le+1:ri+1;
    }
	//如果左右深度差比1大则返回假，否则递归调用左结点与上递归调用右节点
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot==NULL)
            return true;
        
        int le=TreeDepth(pRoot->left);
        int ri=TreeDepth(pRoot->right);
        if(ri-le>1 || ri-le<-1)
            return false;
        
        return IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right);
    }
};
//上述重复遍历多次节点效率较低，下面每个节点只遍历一次
class Solution {
public:
    bool IsBalanced(TreeNode* pRoot,int* depth){
        if(pRoot==NULL)
            {
            *depth=0;
            return true;
        }
        
        int le,ri;
		//在遍历到每个节点时判断当前节点的深度，假设已经知道前面节点的深度，
		//分别计算左右子树的深度差，并计算新的深度
        if(IsBalanced(pRoot->left,&le)&&IsBalanced(pRoot->right,&ri)){
            int dif=le-ri;
            if(dif<=1 && dif>=-1){
                *depth=1+(le>ri?le:ri);
                return true;
            }
        }
        
        return false;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth=0;
        return IsBalanced(pRoot,&depth);
    }
};