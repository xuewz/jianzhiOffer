/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode==NULL)
            return NULL;
        
        if(pNode->right!=NULL){
            TreeLinkNode* right=pNode->right;
            
            while(right->left!=NULL){
                right=right->left;
            }
            return right;
        }
        else if(pNode->next!=NULL){
            TreeLinkNode* pCur=pNode;
            TreeLinkNode* parent=pNode->next;
            
            while(parent!=NULL && pCur==parent->right){
                pCur=parent;
                parent=parent->next;
            }
            return parent;
        }
        
        return NULL;
    }
};