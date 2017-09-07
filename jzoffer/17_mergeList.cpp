/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public://合并两个有序链表
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL)
            return pHead2;
        if(pHead2==NULL)
            return pHead1;
        
        ListNode *mergeHead=NULL;
        if(pHead1->val<pHead2->val){
            mergeHead=pHead1;
            mergeHead->next=Merge(pHead1->next,pHead2);//使用递归
        }
        else
            {
            mergeHead=pHead2;
            mergeHead->next=Merge(pHead1,pHead2->next);
        }
        return mergeHead;
    }
};