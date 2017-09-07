class Solution {
public://全排列字符串
    vector<string> Permutation(string str) {
        vector<string> ans;
        if(str.empty())
            return ans;
        
        Permutation(str,0,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
    
    void Permutation(string str, int b,vector<string> &ans){
        if(b>=str.size()){
            //递归的出口，当大于字符串的长度时，把序列压栈，此时一个序列完成
            ans.push_back(str);
            return;
        }
        
        for(int i=b;i<str.size();++i){
            //判断是否有重复的字符，如果有则不用做
            if(str[i]==str[b] && i!=b)
				continue;
            swap(str[b],str[i]);
            //交换第一个后，对后面的进行递归交换
            Permutation(str,b+1,ans);
            //当完成第一个字符交换，后面也都交换后，把第一个位置还原，便于后面的交换
            swap(str[b],str[i]);
        }
        
    }
};

//指针
 void Permutation(char* str){
        if(str==NULL)
            return;
        
        Permutation(str,str);
    }
    
    void Permutation(char* str, char* pBegin){
        if(*pBegin=='\0')
            cout << str << endl;
        else{
            for(char* ch=pBegin;*ch!='\0';++ch){
                swap(*ch,*pBegin);
                Permutation(str,pBegin+1);
                swap(*ch,*pBegin);
            }
        }
    }