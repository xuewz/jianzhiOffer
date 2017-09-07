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
        vector<vector<int> > Print(TreeNode* pRoot){
            vector<vector<int>> ans;
            vector<int> v;
           
            if(pRoot==NULL)
                return ans;
            
            queue<TreeNode*> nodes;
            nodes.push(pRoot);//太逗比了，没写这句，怎么都跳不进循环
            int nextLevel=0;
            int toBePrinted=1;
            while(!nodes.empty()){
                TreeNode* pNode=nodes.front();
                v.push_back(pNode->val);
                
                if(pNode->left){
                    nodes.push(pNode->left);
                    nextLevel++;
                }
                if(pNode->right){
                    nodes.push(pNode->right);
                    nextLevel++;
                }
                
                nodes.pop();
                --toBePrinted;
                if(!toBePrinted){
                    ans.push_back(v);
                    v.clear();
                    toBePrinted=nextLevel;
                    nextLevel=0;
                }
            }
        return ans;
        }
};