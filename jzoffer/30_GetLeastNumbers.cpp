/*class Solution {
public:
    void GetLeastNumbers(vector<int> &input,multiset<int,greater<int>> &leastNumbers,int k){
        if(k<1 || input.size()<k)
            return;
        
        for(auto it=input.begin();it!=input.end();++it){
            if(leastNumbers.size()<k)
                leastNumbers.insert(*it);
            else
                {
                auto leastIt=leastNumbers.begin();
                if(*it<*(leastIt))
                    {
                    leastNumbers.erase(leastIt);
                    leastNumbers.insert(*it);
                }
            }
         
        }
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        multiset<int,greater<int>> leastNumbers;
        GetLeastNumbers(input,leastNumbers,k );
        
        vector<int> ans;
        for(auto it=leastNumbers.begin();it!=leastNumbers.end();++it){
            ans.push_back(*it);
        }
        
        return ans;
    }
};
*/
#include <iostream>
#include <vector>

using namespace std;


int Partion(vector<int> &numbers, int begin, int end)//划分，找到下标i，左边比i小，右边比i大
{
	if (begin>end)
		return -1;
	int x = numbers[end];
	int i = begin - 1;
	for (int j = begin; j<end; ++j){
		if (x >= numbers[j])
		{
			i++;
			swap(numbers[i], numbers[j]);
		}
	}
	i++;
	swap(numbers[i], numbers[end]);

	return i;
}
    vector<int> GetLeastNumbers_Solution(vector<int> &input, int k) {

        int len=input.size();
        int begin=0;
		int end = len;
        int index=Partion(input,begin,end);
        vector<int> ans;
        ans.clear();
        if(k<=0 || k>input.size()||input.empty())
            return ans;
        
        while(index!=k-1){//找到下标在k-1的数，为第k小的数，包括他前面的数表示前k小的数
            if(index>k-1){//如果index大于k-1，减小end;
                end=index-1;
                index=Partion(input,begin,end);
                
            }
            else{
                begin=index+1;//index小于k-1,增大begin
                index=Partion(input,begin,end);
            }
        }
        
        for(int i=0;i<k;++i)
            {
            ans.push_back(input[i]);
        }
        
        return ans;
    }
	
	int main(){
		int a[] = { 7,6,5,4,3,2,1 };
		vector<int> v(a,a+7);
		vector<int> ans=GetLeastNumbers_Solution(v,4);
		
		for(int i=0;i<4;++i)
			cout << ans[i]<< endl;
		
		return 0;
	}