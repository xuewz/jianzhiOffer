/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* meetingNode(ListNode* pHead){
        if(pHead==NULL)
            return NULL;
        
        ListNode* pSlow=pHead;
        ListNode* pFast=pSlow->next;
        while(pSlow!=NULL && pFast!=NULL){
            if(pFast==pSlow)
                return pFast;
            
            pSlow=pSlow->next;
            pFast=pFast->next;
            if(pFast!=NULL)
                pFast=pFast->next;
            
        }
        return NULL;
    }
    
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* meetNode=meetingNode(pHead);
        if(meetNode==NULL)
            return NULL;
        
        int cNode=1;
        ListNode* pMeetNode=meetNode;
        while(pMeetNode->next!=meetNode){
            pMeetNode=pMeetNode->next;
            cNode++;
        }
        
        pMeetNode=pHead;
        for(int i=0;i<cNode;++i){
            pMeetNode=pMeetNode->next;
        }
        
        ListNode* pNode=pHead;
        while(pNode!=pMeetNode){
            pNode=pNode->next;
            pMeetNode=pMeetNode->next;
        }
        return pNode;
    }
};

//找到链表中环的入口地址
class Solution {
public:    
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead==NULL)//如果链表为空返回空
            return NULL;
        
        ListNode* pSlow=pHead;//快指针和慢指针相差一步
        ListNode* pFast=pSlow->next;
        
        pSlow=pSlow->next;
        if(pFast)
            pFast=pFast->next;//都向后移一个
        
        while(pSlow!=NULL && pFast!=NULL && pFast!=pSlow){  //都不为空，并且快指针一次走两步，慢指针一次走一步，直到两个指针指向元素相等，即为环内的一个元素          
            pSlow=pSlow->next;
            pFast=pFast->next;
            if(pFast!=NULL)
                pFast=pFast->next;
        }
        if(pFast==NULL)
            return NULL;//如果最后跳出指针指向空则返回空
        
        ListNode* pNode=pHead;//一个指针从前面找到的环中元素地址开始，另一个从链表头开始，相遇时即为链表的入口地址
        while(pNode!=pFast){
            pNode=pNode->next;
            pFast=pFast->next;
        }
        return pNode;
    }
};