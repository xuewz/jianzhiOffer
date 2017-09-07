class Solution {
public:
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