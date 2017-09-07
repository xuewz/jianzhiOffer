class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int len1=A.size();
        vector<int> B(len1,1);
        if(len1<=1)
            return B;
        
        B[0]=1;//注意画一个矩阵然后推一下
        for(int i=1;i<len1;++i){
            B[i]=B[i-1]*A[i-1];
        }
        
        int temp=1;
        for(int j=len1-2;j>=0;--j){
            temp*=A[j+1];
            B[j]*=temp;
        }
        return B;
    }
};