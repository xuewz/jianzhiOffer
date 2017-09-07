class Solution
{
public:
  //Insert one char from stringstream
    string s;
    int h[256]={0};
    void Insert(char ch)
    {
        s+=ch;
        h[ch]++;
         
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
    	for(int i=0;i<s.size();++i){
            if(h[s[i]]==1)
                return s[i];
        }
        return '#';
    }

};