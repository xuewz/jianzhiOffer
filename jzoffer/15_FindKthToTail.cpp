/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {//找到链表中倒数第k个节点
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==NULL || k==0)//判断链表是不是空
            return NULL;
        
        ListNode *p1=pListHead;//直接头结点
        
        for(unsigned int i=0;i<k-1;++i){//p1指向第k个元素
            if(p1->next!=NULL)p1=p1->next;//没有这句会报出堆栈溢出的错误
            else
                return NULL;
        }
        ListNode *p2=pListHead;
        while(p1->next!=NULL){
            p2=p2->next;
            p1=p1->next;
        }
        return p2;
    }
};