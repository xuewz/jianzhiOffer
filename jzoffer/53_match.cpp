class Solution {
public://模式匹配，.表示任意一个字符，*表示前面字符可以出现0次或者任意次
    bool matchCore(char* str, char* pattern){
        if(*str=='\0' && *pattern=='\0')
            return true;//如果都到末尾了结束
        if(*str!='\0' && *pattern=='\0')
            return false;//字符串结束，模式吗，没有结束返回错误
        
        if(*(pattern+1)=='*'){//下一个模式字符为*
            if(*str==*pattern || (*pattern=='.'&&*str!='\0'))
                return matchCore(str+1,pattern+2)||matchCore(str,pattern+2)||matchCore(str+1,pattern);//当前字符相等，直接比较下一个字符和模式的下下个字符，或者当前字符和下下个字符，或者下一个字符和模式当前字符
            else
                return matchCore(str,pattern+2);//当前不相等直接比较当前和下下个字符
        }  
        
        if(*str==*pattern || (*pattern=='.'&&*str!='\0'))
             return matchCore(str+1,pattern+1);//下一个字符不是*,当前字符和模式相等的话，直接匹配下一个
        
        return false;
    }
    
    bool match(char* str, char* pattern)
    {
        if(str==NULL || pattern==NULL){
            return false;
        }
        
        return matchCore(str,pattern);//调用匹配函数
    }
};