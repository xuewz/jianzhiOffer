class Solution {
public://旋转数组中的最小元素，
    /*int MinIn(vector<int> rotateArray,int i1,int i2){
        int result=rotateArray[i1];//
        for(int i=i1+1;i<=i2;++i)
            {
            if(result>rotateArray[i])
                result=rotateArray[i];
        }
        return result;
    }*/
    int minNumberInRotateArray(vector<int> rotateArray) {//给定一个旋转数组，如1,2,3,4,5-->3,4,5,1,2
        if(rotateArray.empty())//如果数组为空，返回0
            return 0;
        
        int i1=0;
        int i2=rotateArray.size()-1;
        int iMid=i1;//用二分查找找到较小的区间，最先iMid指向开始元素
        
        while(rotateArray[i1]>=rotateArray[i2] && i<j){//如果开始元素比最后元素大，说明数组是旋转的
            if(i2-i1==1)//如果只有两个元素，则得到后面的较小的下标
            {
                iMid=i2;
                break;
            }
            iMid=(i1+i2)/2;//否则取中间元素
            
            /*if(rotateArray[i1]==rotateArray[i2] && rotateArray[iMid]==rotateArray[i1])//如果下标为i1,i2，iMid的三个元素都相等，只能用顺序查找0
                return MinIn(rotateArray,i1,i2);*/
            
            if(rotateArray[iMid]>rotateArray[i2])
                i1=iMid;//中间元素大于后面的，则向后半部分搜索
            else if(rotateArray[iMid)<rotateArray[i2])
                i2=iMid;//中间元素小于后面的，向前面搜索
			else
				i2--;//中间元素等于后面元素，则递减尾指针i2,这句可以代替上面注释的代码，从后面开始顺序查找
         
        }
        return rotateArray[iMid];//返回最小下标对应的元素
    }
};