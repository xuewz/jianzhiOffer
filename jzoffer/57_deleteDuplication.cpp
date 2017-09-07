ListNode* deleteDuplication(ListNode* pHead)
{//在链表中删除重复的点，
	//if(pHead==NULL)
	// return NULL;

	ListNode* preNode = NULL;
	ListNode* pNode = pHead;

	while (pNode != NULL){
		ListNode* pNext = pNode->next;
		bool toBeDel = false;
		if (pNext != NULL && pNext->val == pNode->val)
			toBeDel = true;//找到一个重复节点

		if (!toBeDel)//如果没有重复继续下一个
		{
			preNode = pNode;//记录前一个结点，保证删除掉重复的点之后和后面大的结点相连接
			pNode = pNode->next;
		}
		else{
			while (pNext != NULL &&pNode->val == pNext->val){
				pNext = pNext->next;
			}//pNext是重复的，删除pNext,直到找到不相同的

			if (preNode == NULL)//如果前一个节点是空的，直接返回不重复的结点
				pHead = pNext;
			else
				preNode->next = pNext;//连接不重复的

			pNode = pNext;//pNode向后移动
		}

	}
	return pHead;
}

ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL)
		return NULL;

	ListNode* pNode = new ListNode(-1);
	pNode->next = pHead;
	ListNode* preNode = pNode;
	ListNode* pTmp = pHead;

	while (pTmp != NULL && pTmp->next != NULL){
		if (pTmp->val == pTmp->next->val){
			int value = pTmp->val;

			while (pTmp != NULL && pTmp->val == value){
				pTmp = pTmp->next;
			}

			preNode->next = pTmp;
		}
		else{
			preNode = pTmp;
			pTmp = pTmp->next;
		}
	}

	return pNode->next;
}


#include <iostream>

using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
void creatList(ListNode** pHead){
	*pHead = new ListNode(1);
	ListNode* pNode = *pHead;
	ListNode* pNext = new ListNode(2);
	pNode->next = pNext;
	pNode = pNext;

	for (int i = 2; i < 7; ++i){
		ListNode* pTmp = new ListNode(i);
		pNode->next = pTmp;
		pNode = pTmp;
	}
}

ListNode* deleteDuplication(ListNode** pHead)
{
	if (*pHead == NULL)
		return NULL;

	ListNode* pNode = new ListNode(-1);
	pNode->next = *pHead;
	ListNode* preNode = pNode;
	ListNode* pTmp = *pHead;

	while (pTmp != NULL && pTmp->next != NULL){
		if (pTmp->val == pTmp->next->val){
			int value = pTmp->val;

			while (pTmp->val == value && pTmp != NULL){
				pTmp = pTmp->next;
			}

			preNode->next = pTmp;
		}
		else{
			preNode = pTmp;
			pTmp = pTmp->next;
		}
	}

	return pNode->next;
}

int main()
{
	ListNode* pHead = NULL;// new ListNode(1);
	creatList(&pHead);
	deleteDuplication(&pHead);
	cout << pHead->val;
	cout << endl << pHead->next->val;
	return 0;
}

