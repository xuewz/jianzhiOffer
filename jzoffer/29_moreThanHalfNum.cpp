/*�����г��ִ�������һ������֣�O(n)
��1��
������ֳ��ֵĴ������������е����ֳ��ֵĴ����ͻ��࣬
��˱�������ֵ��һ�����֣�һ��������
����������һ������ʱ������¸����ֺ�֮ǰ�������ͬ�����1��
�����1��
�������Ϊ0������Ҫ������һ�����֣��������Ϊ1��
�����ҵ������һ��������Ϊ1��Ԫ�ؾ�����Ҫ�ҵ�������O(n)
��2��
����������n/2��Ӧ�����֣�������Ϊn�������е�n/2�������O(n);
�ܿ�����������partitionһ������ѡ����Ԫ��Ȼ������ֳ������֣�
��߱���ԪС���ұ߱���Ԫ�����ѡ����Ԫ�±���n/2Ϊ�����
�������±��Ǵ��ڻ���С�ڣ�����߻����ұ��ҡ�
ֱ���ҵ���n/2�±���ͬ
ע�����ַ������޸����������
*/

#include <iostream>
#include <vector>

using namespace std;
//�������������û�г���һ����������֣�
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
		if(times==0)//�������Ϊ0���͸������ֺʹ���
		{
			ans = A[i];
			times=1;
		}
		else if(ans==A[i])//�����ͬ��1
		{
			times++;
		}
		else
			times--;//�����ͬ��1
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
			ind=partition(A,b,e);//����±��n/2����ô��λ���������
		}
		else
		{
			b=ind+1;
			ind=partition(A,b,e);//�±�С�����ұ߲���
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