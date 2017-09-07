/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        
        deque<TreeNode*> que;
        que.push_back(root);
        
        while(que.size())
            {
            TreeNode *pNode=que.front();
            que.pop_front();
            
            ans.push_back(pNode->val);
            if(pNode->left)
                que.push_back(pNode->left);
            if(pNode->right)
                que.push_back(pNode->right);
        }
        return ans;
    }
};