class Solution {
public://求一个数的二进制表达中1出现的个数
     int  NumberOf1(int n) {
         int count = 0;//记录个数
         while(n){
             count++;
             n=(n-1)&n;//把该数和该数减去1相互与，去掉了整数二进制表达中的最后一个1，然后count+1,直到n为0的时候跳出循环
         }
         
         return count;
     }
};