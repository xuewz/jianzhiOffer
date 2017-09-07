/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
//求二叉树的深度
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return 0;
        
        int le=TreeDepth(pRoot->left);
        int ri=TreeDepth(pRoot->right);
        
        return le>ri?le+1:ri+1;
    }
};

//非递归求二叉树的深度
int TreeDepth(TreeNode* root){
	//先序遍历一个节点，当前节点所在的最大层数即为深度
	deque<TreeNode*>dq;
	int depth=-1;
	
	while(1){
		while(root!=NULL)
		{
			dq.push_back(root);
			root=root->left;
		}
		//更新深度
		depth=max(dq.size(),depth());
		
		while(1){
			//先判断dq是否为空，若为空直接返回当前深度
			if(dq.empty())
				return depth;
			
			//若不为空说明当前结点已经到达最左边，看其右孩子是否存在，继续
			TreeNode* node=dq.back();
			TreeNode* rNode=node->right;//右孩子
			if(rNode && root!=rNode){//右孩子存在且当前的父结点不等于右孩子节点
			root=rChild;
			break;
				
			}
			root=node;//右孩子为空，说明当前父节点就是最大层
			dq.pop_back();//直到减到0，跳出循环
		}
		
	}
	return depth;
}