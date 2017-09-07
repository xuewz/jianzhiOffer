/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*///翻转链表
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==NULL)
            return NULL;
        
        ListNode *newHead=NULL;
        ListNode *pNode=pHead;
        ListNode *pre=NULL;
        
        while(pNode!=NULL){
            ListNode *pNext=pNode->next;//先保存后面的结点，防止链表断开
            
            if(pNext==NULL)
                newHead=pNode;
            
            pNode->next=pre;
            pre=pNode;
            pNode=pNext;
        }
        return newHead;
    }
};

ListNode* ReverseList(ListNode* pHead) {
        //如果链表为空或者链表中只有一个元素 
        if(pHead==NULL||pHead->next==NULL) return pHead;
         
        //先反转后面的链表，走到链表的末端结点
        ListNode* pReverseNode=ReverseList(pHead->next);
         
        //再将当前节点设置为后面节点的后续节点
        pHead->next->next=pHead;
        pHead->next=NULL;
         
        return pReverseNode;
         
    }
/*递归的方法其实是非常巧的，它利用递归走到链表的末端，然后再更新每一个node的next 值 ，实现链表的反转。而newhead的值没有发生改变，为该链表的最后一个结点，所以，反转后，我们可以得到新链表的head。 
注意关于链表问题的常见注意点的思考： 
1、如果输入的头结点是 NULL，或者整个链表只有一个结点的时候 
2、链表断裂的考虑 
*/
