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
    void FindPath(TreeNode* root,int expectNumber, vector<int>&path,int curSum,vector<vector<int>> &ans){
        curSum+=root->val;
        path.push_back(root->val);
        
        bool isLeaf=root->left==NULL && root->right==NULL;
        if(isLeaf && curSum==expectNumber){
            ans.push_back(path);
        }
        
        if(root->left!=NULL)
            FindPath(root->left,expectNumber,path,curSum,ans);
        if(root->right!=NULL){
            FindPath(root->right,expectNumber,path,curSum,ans);
        }
        path.pop_back();
    }
    
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<int>path;
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        
        int curSum=0;
        FindPath(root,expectNumber,path,curSum,ans);
        
        return ans;
    }
};