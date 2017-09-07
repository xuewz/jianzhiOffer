class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff=accumulate(nums.begin(),nums.end(),0,bit_xor<int>());//将所有元素异或
         diff &= -diff;//获取整数的二进制中最后一个1，与n&(n-1)等价
        
        vector<int> ans(2,0);
        
        for(int i=0;i<nums.size();++i){
            if((nums[i]&diff)==0)
                ans[0]^=nums[i];
            else
                ans[1]^=nums[i];
        }
        
        return ans;
    }
};
//数组中只有两个数出现了一次，其他都出现了两次，
//1.从头到尾异或数组元素，只剩下两个单独元素的异或
//2.通过异或值的二进制最后一个1的位置，找到数组中元素在该位置为1和0，将数组分为两部分，每一部分只有一个单独元素
//3.在每部分异或之和得到的元素合起来就是结果


class Solution {
public://数组中只出现一次的数组，2,4,3,6,3,2,5,5
    unsigned int FindRightFirstBit1(int num)
    {
        int index =0;
        while(((num&1)==0)  &&  (index<8*sizeof(int)) )
              {
            index++;
            num=num>>1;
        }
        return num;
    }      
    
    bool IsBit1(int num,unsigned int indexBit){
        num=num>>indexBit;
        return (num&1);
    }
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.empty() || data.size()<2)
            return;
        int ansXOR =0;
        for(int i=0;i<data.size();++i){
            ansXOR^=data[i];
        }
        
        unsigned int indexOf1 = FindRightFirstBit1(ansXOR);
        
        *num1=0;
        *num2=0;
        for(int j=0;j<data.size();++j){
            if(IsBit1(data[j],indexOf1))
                *num1 ^=data[j];
            else
                *num2 ^=data[j];
        }
    }
};