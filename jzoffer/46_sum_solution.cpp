class Solution {
public:
    int Sum_Solution(int n) {
        /*bool a[n][n+1];
        return sizeof(a)>>1;*/
        //不能用条件，循环等语句
        int ans=n;
        ans&&(ans+=Sum_Solution(n-1));//&&是因为要判断0的时候，递归结束条件
        return ans;
    }
};

//递归求和数组
int getSum(int *a,int n){
	return n==0?0:getSum(a,n-1)+a[n-1];
}