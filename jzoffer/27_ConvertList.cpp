/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {//
public:
    void Convert(TreeNode* pNode, TreeNode** pLastNode){
        if(pNode==NULL)
            return;
        
        TreeNode* pCur=pNode;
        if(pCur->left!=NULL)//假设左子树已经转换好链表
            Convert(pCur->left,pLastNode);
        
        pCur->left=*pLastNode;//直接让当前节点指向已转换链表的最后一个节点
        if(*pLastNode!=NULL)
            (*pLastNode)->right=pCur;//如果最后一个节点不是空，让他也指向当前节点
        
        *pLastNode=pCur;
        if(pCur->right!=NULL)//然后后移最后一个节点到当前节点，当前节点的右孩子不为空，转换右子树
            Convert(pCur->right,pLastNode);
            
    }
    
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* pLastNode=NULL;
        Convert(pRootOfTree, &pLastNode);
        
        TreeNode* pHead=pLastNode;//指向双链表的尾节点
        while(pHead!=NULL && pHead->left!=NULL)
            pHead=pHead->left;
        
        return pHead;
    }
};