/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //��һ��һ�������㶨���Ƚϼ�
 TreeNode* reConstructBinaryTree(vector<int> &pre,vector<int> vin) {
        //ע��preҪ���ã����򱨴�
        TreeNode* root=NULL;
        if(vin.empty())
            return root;
		
        root=new TreeNode(pre[0]);//�������еĵ�һ��Ԫ���Ǹ��ڵ�
        pre.erase(pre.begin());//�����ڵ��pre��ɾ������һ�εݹ�ʱ���ҵ���һ�����ڵ�
        
        vector<int> left;
        vector<int> right;//�½��������飬�洢��������ߵ����������ұߵ�������
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
        
        root->left=reConstructBinaryTree(pre,left);//��������������ֱ���еݹ�
        root->right=reConstructBinaryTree(pre,right);
        
        return root;
    }
	
//�ڶ�����Ҫ�����������Ƚϸ��ӣ�������	
//��֪��������ǰ�����������������ؽ�������
TreeNode* ConstructCore(int* starPreorder, int* endPreorder, int* starInorder, int* endInorder)
{	
	//ǰ�������һ������Ǹ��ڵ�
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
	
	//������������ҵ����ڵ�
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
		//����������
		root->left = ConstructCore(starPreorder+1, leftPreorderEnd, starInorder, rootInorder-1);
	}
	if(leftLen < endPreorder-starPreorder)
	{
		//����������
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


