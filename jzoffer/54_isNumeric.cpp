class Solution {
public://检验是不是数值的字符串
    bool isNumeric(string str)
    {
        bool hasE=false,decimal=false,sign=false;
        
        for(int i=0;i<str.size();++i){
            if(str[i]=='e' || str[i]=='E'){
                //后面一定要有数字
                if(i==str.size()-1)
                    return false;
                if(hasE)//不能出现两个e
                    return false;
                hasE=true;
            }
            else if(str[i]=='+' || str[i]=='-'){
                if(sign && str[i-1]!='e' && str[i-1]!='E')//第二次出现前面必须有e
                    return false;
                if(!sign&&i>0 &&str[i-1]!='e'&&str[i-1]!='E')//第一次不能在开头前面有e
                    return false;
                sign=true;
            }
            else if(str[i]=='.'){
                if(hasE|| decimal)//e、小数点后面不能出现
                    return false;
                decimal=true;
            }
            else if(str[i]>'9' || str[i]<'0'){//非法数字
                return false;
            }
        }
        return true;
    }

};