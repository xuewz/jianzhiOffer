class Solution {
public://整数幂次方
    double Power(double base, int exponent) {
       /*if(exponent==0)
            return 1;
        if(exponent==1)
            return base;
        
        double ans = Power(base,exponent>>1);
        ans *=ans;
        if(exponent && 0x1 == 1)
            ans *= base;
        
        return ans;*/
       
        /*double ans=1;
        if(exponent ==0)
            return 1;
        else if(exponent <0){
            while(exponent)
                {
                ans/=base;
                exponent++;
            }
        }
        else{
            while(exponent>0)
                {
                ans*=base;
                exponent--;
            }
        }
        return ans;*/
        //没有考虑到边界条件
        int e=abs(exponent);//先对幂取绝对值
        double r=1.0;//返回结果初始化
        
        while(e){//对幂二进制形式边右移，边进行乘方
            if(e&1==1)r*=base;//若最后一位是1，则直接乘以一个base
            base*=base;//否则，base乘以base，
            e>>=1;//e右移一位
        }
        return exponent<0?1/r:r;//如果幂小于0返回倒数，否则返回原数
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        /*if(x==-1 && (n&0x1==1)
            return -1;*/
        if(n==1)
            return x;
        if(n==INT_MIN){
            if(x==1 || x==-1)
                return 1;
            else
                return 0;
        }
        
        int e=abs(n);
        double ans=1;
        while(e){
            
            if(e&0x1==1){
                ans*=x;
            }
            x*=x;
            e>>=1;
        }
        return n>=0?ans:1.0/ans;
    }
};