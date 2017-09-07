class Solution {
public: //给定一个数，求数组中两个数的和
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> ans;
        if(array.empty())
            return ans;
        
        int ahead=array.size()-1;
        int behind=0;
        
        while(ahead>behind){//左边和右边同时比较两个数的和，如果当前和大，减小右边下标，否则增大左边
            
            long long curSum=array[ahead]+array[behind];
            if(curSum==sum)
                {
                if(array[ahead]<array[behind])
                {
                    ans.push_back(array[ahead]);
                	ans.push_back(array[behind]);
                }
                else{
                    ans.push_back(array[behind]);
                	ans.push_back(array[ahead]);                    
                }
                break;
            }
            else if(curSum>sum)
                ahead--;
            else
                behind++;
                
        }
        return ans;
    }
};