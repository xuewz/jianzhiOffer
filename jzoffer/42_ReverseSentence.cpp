class Solution {
public:
    string ReverseSentence(string s) {
        int i=0;
        int b,e;
        
    reverse(s.begin(),s.end());//先逆转整个串
    while(i<s.size())
        {
        b=i;
        while(s[i]!=' '&& s[i]!='\0')
            {
            i++;//找到单个单词，遇到空格跳出
        }
        e=i;
        i++;
       reverse(s.begin()+b,s.begin()+e);//逆转当前的单词
    }
    return s;
    }
};
//没有考虑全是空格，多个空格在首部或者尾部