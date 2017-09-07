class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(!str.empty()){
        int len = str.size();
        int b1=0;
        int e1=n-1;
        int b2=n;
        int e2=len-1;
        
        reverse(str.begin()+b1,str.begin()+e1+1);
        reverse(str.begin()+b2,str.begin()+e2+1);
        reverse(str.begin(),str.end());
    }
    return str;
    }
};