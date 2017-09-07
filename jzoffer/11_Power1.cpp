class Solution {
public:
    double Power(double base, int exponent) {
       if(exponent==0)
            return 1;
        if(exponent==1)
            return base;
        
        double ans = Power(base,exponent>>1);
        ans *=ans;
        if(exponent && 0x1 == 1)
            ans *= base;
        
        return ans;
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
    }
};