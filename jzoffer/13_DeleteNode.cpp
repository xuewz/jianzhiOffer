/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //删除链表中的给定节点
class Solution {
public:
    void deleteNode(ListNode* pHead, ListNode* node) {
        if(!node ||!pHead)//如果链表或者节点为空，则返回，
            return;
        
		if(!node->next){//如果该节点的下一个不为空，即删除的不是尾节点
			ListNode* p=node->next;//这一句一定要写，不然后面删除的是改变后的
			node->val=node->next->val;//下一个节点的值给当前节点
			node->next=node->next->next;//该节点的下一个指向下一个的下一个
			
			delete p;//删除下一个
			p=NULL;//下一个
		}
		else if(pHead==node){//头结点并且只有一个节点
			delete node;//直接删除
			node=NULL;
			pHead=NULL;
		}
		else{
			ListNode* pNode=pHead;//尾节点，先遍历到前驱节点，然后把next直接指向空
			
			while(pNode->next!=node){
				pNode=pNode->next;
			}
			
			pNode->next=NULL;
			delete node;
			node=NULL;
		}
    }
};