/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {//有随机链表的节点，复制链表
public:
    void CloneNode(RandomListNode* pHead){
        RandomListNode* pNode=pHead;//先克隆节点到该节点后面，将random置空
        while(pNode!=NULL){
            RandomListNode* pCloned=new RandomListNode(0);
            pCloned->label=pNode->label;
            pCloned->next=pNode->next;
            pCloned->random=NULL;
            
            pNode->next=pCloned;
            pNode=pCloned->next;
        }
    }
    
    void ConnectRandom(RandomListNode* pHead){
        RandomListNode* pNode=pHead;//连接随机节点
        
        while(pNode!=NULL){
            RandomListNode* pCloned=pNode->next;
            if(pNode->random!=NULL)
            	pCloned->random=pNode->random->next;//根据节点的随机指向复制节点的随机节点
            
            pNode=pCloned->next;
            
        }
    }
    
    RandomListNode* ReconnectRandom(RandomListNode* pHead){
        RandomListNode* pNode=pHead;
        RandomListNode* pClonedHead=NULL;
        RandomListNode* pClonedNode=NULL;
        
        if(pNode!=NULL){//后移pNode一个
            pClonedHead=pClonedNode=pNode->next;
            pNode->next=pClonedNode->next;
            pNode=pNode->next;
        }
        
        while(pNode!=NULL){//pNode不为空，将pNode的next给复制节点的next
            pClonedNode->next=pNode->next;
            pClonedNode=pClonedNode->next;
            pNode->next=pClonedNode->next;
            pNode=pNode->next;
        }
        return pClonedHead;
    }
    
    RandomListNode* Clone(RandomListNode* pHead)
    {
        CloneNode(pHead);
        ConnectRandom(pHead);
        return ReconnectRandom(pHead);
    }
};