/*数组中出现次数超过一半的数字：O(n)
解1：
这个数字出现的次数比其他所有的数字出现的次数和还多，
因此保存两个值，一个数字，一个次数，
当遍历到下一个数字时，如果下个数字和之前保存的相同，则加1；
否则减1；
如果次数为0，则需要保存下一个数字，并设次数为1，
所以找到的最后一个次数设为1的元素就是需要找到的数字O(n)
解2：
对数组排序，n/2对应的数字，即长度为n的数组中第n/2大的数字O(n);
受快排启发，与partition一样，先选定主元，然后将数组分成两部分，
左边比主元小，右边比主元大，如果选中主元下标是n/2为结果，
否则看它下标是大于还是小于，在左边还是右边找。
直到找到和n/2下标相同
注意这种方法会修改输入的数组
*/

#include <iostream>
#include <vector>

using namespace std;
//考虑如果数组中没有超过一半次数的数字？
bool checkTrue(vector<int> A,int num)
{
	int times = 0;
	for(int i = 0; i < A.size(); ++i)
	{
		if(A[i]==num)
			times++;
	}
	if(times*2 <= A.size())
		return 0;
	return 1;
}
int moreThanHalfNum1(vector<int> &A)
{
	if(A.empty())
		return 0;
	int ans = A[0];
	int times = 1;
	for(int i=1;i<A.size();++i)
	{
		if(times==0)//如果次数为0，就更新数字和次数
		{
			ans = A[i];
			times=1;
		}
		else if(ans==A[i])//如果相同加1
		{
			times++;
		}
		else
			times--;//如果不同减1
	}
	if(!checkTrue(A,ans))
		return 0;
	return ans;
}

int partition(vector<int> &A, int b, int e)
{
	int x=A[e-1];
	int i=b-1;
	for(int j=b;j<e-1;++j)
	{
		if(x>=A[j])
		{
			i++;
			int temp = A[j];
			A[j]=A[i];
			A[i]=temp;
		}
	}
	int temp1=A[e-1];
	A[e-1]=A[i+1];
	A[i+1]=temp1;
	return i+1;
}
int moreThanHalfNum2(vector<int> &A)
{
	if(A.empty())
		return 0;
	int mid = (A.size())/2;
	int b=0;
	int e=A.size();
	int ind = partition(A,b,e);
	while( ind != mid )
	{
		if(ind>mid)
		{
			e=ind-1;
			ind=partition(A,b,e);//如果下标比n/2大，那么中位数在其左边
		}
		else
		{
			b=ind+1;
			ind=partition(A,b,e);//下标小，到右边查找
		}
	}
	int ans = A[mid];
	if(!checkTrue(A,ans))
		return 0;
	return ans;
}
int main()
{
	vector<int> A;//{1,2,3,2,2,2,5,4,2}
	int temp;
	while(cin>> temp)
	{
		A.push_back(temp);
	}
	cout << moreThanHalfNum1(A) <<endl;
	cout << moreThanHalfNum2(A) <<endl;
	return 0;
}


class Solution {
public:
    int Partion(vector<int> &numbers,int begin,int end)
    {
        int x=numbers[end-1];
        int i=begin-1;
        for(int j=begin;j<end-1;++j){
            if(x>=numbers[j])
            {
                i++;
                swap(numbers[i],numbers[j]);
            }
        }
        i++;
        swap(numbers[i],numbers[end-1]);
            
        return i;
    }
        
    int MoreThanHalfNum_Solution(vector<int> numbers) {
       /* if(numbers.empty())
            return 0;
        
        int ans=numbers[0];
        int times=1;
        for(int i=1;i<numbers.size();++i){
            if(times==0)
                {
                ans=numbers[i];
                times=1;
            }
            else if(numbers[i]==ans)
                times++;
            else
                times--;
               
        }
        */
        int len=numbers.size();
        int mid=len>>1;
        int begin=0;
        int end=len;
        int index=Partion(numbers,begin,end);
        
        while(index!=mid){
            if(index>mid){
                end=index-1;
                index=Partion(numbers,begin,end);
                
            }
            else{
                begin=index+1;
                index=Partion(numbers,begin,end);
            }
        }
        
        int ans=numbers[mid];
        
        int times=0;
        for(int j=0;j<numbers.size();++j){
            if(numbers[j]==ans)
                times++;
        }
        if(times*2<=numbers.size())
            return 0;
        
        return ans;
        
    }
};