/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> ans;
        vector<int> v;
        
        if(pRoot==NULL)
            return ans;
        
        stack<TreeNode*> levels[2];
        int even=0;
        int odd=1;
        levels[even].push(pRoot);
        
        while(!levels[0].empty() || !levels[1].empty()){
            TreeNode* pNode=levels[even].top();
            levels[even].pop();
            
            v.push_back(pNode->val);
            if(even==0){
                if(pNode->left!=NULL)
                    levels[odd].push(pNode->left);
                if(pNode->right!=NULL)
                    levels[odd].push(pNode->right);
            }
            else{
                if(pNode->right!=NULL)
                    levels[odd].push(pNode->right);
                if(pNode->left!=NULL)
                    levels[odd].push(pNode->left);
            }
            
            if(levels[even].empty()){
                ans.push_back(v);
                v.clear();
                even=1-even;
                odd=1-odd;
            }
        }
        return ans;
    }
    
};