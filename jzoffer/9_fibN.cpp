class Solution {
public://斐波那契数列0,1,1,2,3,5,8，。。。
    int Fibonacci(int n) {
        if(n==0)//如果为0，返回0
            return 0;
        if(n==1)//如果为1返回1
            return 1;
        
        long long one=1;
        long long two=0;
        long long fibN=0;//设置two指向前一个，one指向当前的，fibN是要求的下一个
        for(size_t i=2;i<=n;++i){
            fibN=one+two;//非递归每次求两个数的和
            
            two=one;//然后将one和fibN一次赋值给two，one进行下次更新
            one=fibN;
        }
        return fibN;//返回第n个斐波那契数
    }
};

//青蛙跳台阶
class Solution {//青蛙一次跳1或者2，跳n次的的结果有几种，实际上满足斐波那契数列
public:
    int jumpFloor(int number){
        if(number==1)//第一次只有一种结果
            return 1;
        if(number==2)//第二次两种结果
            return 2;
        
        long long one=2;
        long long two=1;
        long long sum=0;
        for(int i=3; i<=number; ++i){
            sum=one+two;//直到第n次，求得第n个斐波那契数
            
            two=one;
            one=sum;
        }
        return sum;
    }
};

//变态跳台阶
/*
设青蛙一次跳n阶记为f(0)=1;
1.f(1)=f(0);只有一种跳法
2.f(2)=f(1)+f(0)=2;跳一阶后还有f(2-1)=f(1)种，跳2阶还有f(2-2)=f(0)种；
3.f(3)=f(2)+f(1)+f(0)=4;
...
f(n)=f(n-1)+...+f(0);
f(n+1)=f(n)+f(n-1)+...+f(0);
两个等式相减得到f(n+1)=f(n)+f(n)=2*f(n);
所以跳n阶有2^(n-1)
*/