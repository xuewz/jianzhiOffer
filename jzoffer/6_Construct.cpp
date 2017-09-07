/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //第一种一个函数搞定，比较简单
 TreeNode* reConstructBinaryTree(vector<int> &pre,vector<int> vin) {
        //注意pre要引用，否则报错
        TreeNode* root=NULL;
        if(vin.empty())
            return root;
		
        root=new TreeNode(pre[0]);//先序序列的第一个元素是根节点
        pre.erase(pre.begin());//将根节点从pre中删除，下一次递归时候找到下一个根节点
        
        vector<int> left;
        vector<int> right;//新建两个数组，存储中序中左边的左子树和右边的右子树
        int i=0;
        while(vin[i]!=root->val && i<vin.size()){
            left.push_back(vin[i]);
            i++;
        }
        
        i++;
        while(i<vin.size()){
            right.push_back(vin[i]);
            i++;
        }
        
        root->left=reConstructBinaryTree(pre,left);//对左右两个数组分别进行递归
        root->right=reConstructBinaryTree(pre,right);
        
        return root;
    }
	
//第二种需要两个函数，比较复杂，不建议	
//已知二叉树的前序遍历和中序遍历，重建二叉树
TreeNode* ConstructCore(int* starPreorder, int* endPreorder, int* starInorder, int* endInorder)
{	
	//前序遍历第一个结点是根节点
	int rootVal = starPreorder[0];
	TreeNode* root = new TreeNode(0);
	root->val = rootVal;
	root->left = root->right = NULL;
	
	if(starPreorder == endPreorder)
	{
		if(starInorder == endInorder && *starInorder == *starPreorder)
			return root;
		else
			throw "Invalid input.";
	}
	
	//在中序遍历中找到根节点
	int* rootInorder = starInorder;
	while(rootInorder <= endInorder && *rootInorder ! = rootVal)
	{
		++rootInorder;
	}
	
	if(rootInorder == endInorder && *rootInorder != rootVal)
	{
		throw "Invalid input.";
	}
	
	int leftLen = rootInorder - starInorder;
	int* leftPreorderEnd = starPreorder + leftLen;
	if(leftLen > 0)
	{
		//构建左子树
		root->left = ConstructCore(starPreorder+1, leftPreorderEnd, starInorder, rootInorder-1);
	}
	if(leftLen < endPreorder-starPreorder)
	{
		//构建右子树
		root->right = ConstructCore(leftPreorderEnd+1, endPreorder, rootInorder+1, endInorder);
	}
	return root;
}

TreeNode* Construct(int* preorder, int* inorder, int len)
{
	if(preorder == NULL || inorder == NULL || len <= 0)
	{
		return NULL;
	}
	return ConstructCore(preorder, preorder+len-1,inorder, inorder+len-1);
}


int main()
{
	TreeNode* root;
	int pre[]={1,2,4,7,3,5,6,8};
	int in[]={4,7,2,1,5,3,8,6};
	TreeNode* root1 = Construct(pre,in,8);
	PreOrder(root1);
	return 0;
}


