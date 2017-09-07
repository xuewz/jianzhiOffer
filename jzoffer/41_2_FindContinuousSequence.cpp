class Solution {
public://求连续子序列的和为给定数
    vector<int> addSequence(int small, int big){
        vector<int> v;//输出一个子序列
        int i;
        for(i=small;i<=big;++i){
            v.push_back(i);
        }
        return v;
    }
    
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> ans;
        if(sum<3)
            return ans;
        
        int small=1;
        int big=2;//前后两个连续的最小数开始计算
        int mid=(sum+1)>>1;//循环终止条件是（1+s）/2
        int curSum=small+big;//计算当前和
        
        while(small<mid){//当small比mid小，继续循环
            if(curSum==sum)//找到一个子序列
            {
                ans.push_back(addSequence(small,big));
            }
            while(curSum>sum && small <mid){//当前和大于sum并且small小于mid
                curSum-=small;//减去第一个数，减小当前和
                small++;
                
                if(curSum==sum)//如果等于给定数找到一个序列
                     ans.push_back(addSequence(small,big));
            }
            
            big++;//没有找到，增大big，增大当前和
            curSum+=big;
        }
        return ans;
    }
};