class Solution {
public://判断有没有顺子
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.empty())
            return false;
        
        sort(numbers.begin(),numbers.end());//先排序
        
        int numOfZero=0;
        int numOfGap=0;
		//统计0的个数
        for(int i=0;i<numbers.size();++i){
            if(numbers[i]==0)
                numOfZero++;
            else
                break;
        }
        //统计间隔数目
        int small=numOfZero;
        int big=small+1;
        while(big<numbers.size()){
            if(numbers[small]==numbers[big]){//两个数相等，不可能是顺子
                return false;
            }
            
            numOfGap+=numbers[big]-numbers[small]-1;
            small++;
            big++;
           
        }
		//如果间隔的总数小于等于0的个数，数组连续，否则数组不连续
        return (numOfGap>numOfZero)?false:true;
    }
};