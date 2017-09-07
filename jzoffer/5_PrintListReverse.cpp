/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
//从尾到头输出链表，实际上可以从头到尾读链表的值到数组，然后翻转数组即可
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ans;//存放元素的数组
        ListNode* pNode=head;//节点指向链表
        
        while(pNode!=NULL){//当节点不为空时，将节点值放进数组，并且节点后移
            ans.push_back(pNode->val);
            pNode=pNode->next;
        }
        
        reverse(ans.begin(),ans.end());//将数组转置即可
        return ans;
    }
};

//另一种解法，用递归，递归本身就是一个栈，先入后出，正好满足
 void print(ListNode* head,vector<int>& ans){
        if(head){//传入链表的头结点，一个可改变的数组，链表结点不为空时候，递归打印下一个节点，将该节点值加入到数组，实际上是先入，当递归结束之后，后出
            print(head->next,ans);
            ans.push_back(head->val);
        }
    }
    
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ans;
        print(head,ans);//调用递归函数，后入的节点值先进入到数组中，即实现链表逆转
        
        return ans;
    }

