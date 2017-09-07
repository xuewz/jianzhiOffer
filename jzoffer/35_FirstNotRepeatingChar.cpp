class Solution {
public://第一次不重复的字符串，一个哈希表，对字符串进行一次扫描，第一个为1的即为结果
    int FirstNotRepeatingChar(string s) {
        int h[256] = {0};
        int flag = -1;
        for(size_t i = 0; i< s.size();++i)
            {
            h[s[i]]++;
        }
        

        for(size_t j=0;j<s.size();++j){
            if(h[s[j]]==1)
            {
                //cout << s[j];
                flag=j;
                return flag;
            }
        }
        return flag;
    }
};