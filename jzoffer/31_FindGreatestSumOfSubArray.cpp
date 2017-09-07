class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int sum=array[0];
        int curSum=array[0];
        if(array.empty())
            return sum;
        
        int i=0;
        for(i=0;i<array.size();++i){
            if(curSum<=0)
                curSum=array[i];
            else
                curSum+=array[i];
            
            if(curSum>sum)
                sum=curSum;
        }
        
        return sum;
    }
};//只适用于sum是正数的例子

//给定一个数组，找到连续子数组的最大和
int FindGreatestSumOfSubArray(vector<int> array) {
        vector<int> f(array.size(),0);//采用动态规划，初始化n个0
        if(array.empty())
            return 0;
        
        int sum=array[0];
        for(int i=0;i<array.size();++i){
            if(i==0 || f[i-1]<=0)//如果当前f小于等于0，意思是前面的和比当前数组还小，或者i=0开始，f为当前的数组值
                f[i]=array[i];
            
            if(f[i-1]>0)//如果前面的和比当前数组还大，继续增加f
                f[i]=f[i-1]+array[i];
            
            sum=max(f[i],sum);//每次取f和sum的最大值给sum
        }
        return sum;
    }//动态规划，比较全面