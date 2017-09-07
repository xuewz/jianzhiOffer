/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
//找到链表的公共节点
class Solution {
public:
    int GetListLength(ListNode* pHead){//返回链表的长度
        int len=0;
        ListNode* pNode=pHead;
        while(pNode!=NULL){
            len++;
            pNode=pNode->next;
        }
        return len;
    }
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int len1=GetListLength(pHead1);
        int len2=GetListLength(pHead2); 
        int dif=len1-len2;//先找到两个链表的长度差
        ListNode* pheadLong=pHead1;
        ListNode* pheadShort=pHead2;
        if(len1<len2){
            pheadLong=pHead2;
            pheadShort=pHead1;
            dif=len2-len1;//指定长链表和短链表
        }
        
        int i=0;
        while(i<dif){//令长链表先走的步数为前面的差，
            pheadLong=pheadLong->next;
            i++;
        }
        
        while(pheadLong!=NULL && pheadShort!=NULL && pheadLong!=pheadShort){
            pheadLong=pheadLong->next;//两个链表同时走，直到所指元素相等即为第一个公共节点
            pheadShort=pheadShort->next;
            
        }
        ListNode* firstCommonNode=pheadLong;
        return firstCommonNode;
    }
};