#include <iostream>
#include <string>
using namespace std;
#pragma warning(disable:4996)

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};


void Serialize(TreeNode* root, string& s){
	/*if (root == NULL && root->left==NULL && root->right==NULL)
	{
	s += '$';
	return;
	}*/

	if (root == NULL){
		s += "$,";
		return;
	}

	s += to_string(root->val);
	s += ',';

	Serialize(root->left, s);
	Serialize(root->right, s);

}
char* Serialize(TreeNode *root) {
	if (root == NULL)
		return "$";
	string s;
	Serialize(root, s);
	char* str;
	int i = 0;

	str = new char[s.size()];
	for (i = 0; i < s.size() - 1; ++i)
		str[i] = s[i];
	str[i] = '\0';

	/*const int len = s.size();
	char* str = new char[len + 1];
	strcpy(str, s.c_str());*/

	return str;
}

TreeNode* Deserialize(char *&str) {
	TreeNode* p = NULL;
	int num = 0;

	if (str[0] == '$'){
		str += 2;
		return NULL;
	}

	while (*str != ','){
		num = num * 10 + (*str - '0');
		str++;
	}
	str++;

	p = new TreeNode(num);
	p->left = Deserialize(str);
	p->right = Deserialize(str);

	return p;
}

void Print(TreeNode* root){
	if (root)
	{
		cout << root->val;
		Print(root->left);
		Print(root->right);
	}
}
int main()
{
	char* str = "8,6,10,5,$,$,7,$,$,9,$,$,13,$,$";
	TreeNode* root = Deserialize(str);
	Print(root);

	/*cout << endl;
	char* s = Serialize(root);
	cout << s;*/

	return 0;
}
