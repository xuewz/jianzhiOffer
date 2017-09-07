class Solution {
public://不用加减乘除作加法
    int Add(int num1, int num2)
    {
        int sum,carry;
        do{
            sum=num1^num2;//两个数先异或
            carry=(num1&num2)<<1;//找到进位
            
            num1=sum;//继续相加sum和进位
            num2=carry;
        }while(num2);//直到进位为0
            
        return num1;//返回num1
    }
};