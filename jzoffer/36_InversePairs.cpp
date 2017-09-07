class Solution {
public://找出逆序对的个数，
    long InversePairCore(vector<int>& data, vector<int>& copy, long begin, long end){//先把数组分割成子数组，找出子数组中逆序对的个数，然后在统计相邻两个子数组的逆序对的个数，在统计过程中，实际上需要对数组进行排序，实际上是归并排序
        if(begin==end)//如果begin==end，也就是每个数组只有一个元素，直接赋值，
        {
            copy[begin]=data[begin];
        	return 0;
        }
        
        long len=(end-begin)>>1;//将数组分成两半
        long le=InversePairCore(copy,data,begin,begin+len);//左边给le，右边给ri
        long ri=InversePairCore(copy,data,begin+len+1,end);
        
        long i=begin+len;//i指向第一个子数组的末尾
        long j=end;//j指向第二个子数组的末尾
        long k=end;
        long ans=0;
        
        while(i>=begin && j>=begin+len+1){
            if(data[i]>data[j])//两个子数组从后往前，计算逆序对
                {
                copy[k--]=data[i--];//合并为copy，下次调用的时候与data调换
                ans+=j-begin-len;
            }
            else
                {
                copy[k--]=data[j--];//如果不是逆序对直接跳过
            }
        }
        
        while(i>=begin){//复制剩下的元素
            copy[k--]=data[i--];
        }
        while(j>=begin+len+1)
            copy[k--]=data[j--];
        
        return (le+ri+ans)%1000000007;
    }
    
    int InversePairs(vector<int> data) {
        if(data.empty())
            return 0;
        
        vector<int> copy(data);//先将数组复制一下
        long ans=InversePairCore(data,copy,0,data.size()-1);//调用核心函数
        
        copy.clear();
        return ans;
    }
};