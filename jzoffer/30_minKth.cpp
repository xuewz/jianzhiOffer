/*找到最小的k个数,等价于第k小的数
最简单的思路是先排序，再取前k个数字O(nlogn);
解法一：
与数组中出现次数超过一半相似，可以基于partition实现O(n)
解法二：
创建一个大小为k的堆来存储最小的k个数字，O(nlogk)，适合海量数据
维护这个大根堆，在堆的顶端是最小k个数中最大的数；
然后遍历整个数组，比较当前数和堆顶如果比当前数小，只需要把堆顶元素换成当前数，
然后调整堆，如果不是，继续遍历下一个数，完成遍历后，堆中的k个数就是所有数组中最小的k个数。
*/
//借助堆，查找最小的k个数
//建立大根堆
//调整大根堆
//定义数组存储堆元素
#include <iostream>
#include <vector>

using namespace std;

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
	if(i==A.size()-1)
		return i;
	return i+1;
}
void GetLeastNums(vector<int> &A,int k)
{
	if(A.empty() || k>A.size() || k<=0)
		return;
	int b=0;
	int e=A.size();
	int ind = partition(A,b,e);
	while( ind != k-1 )
	{
		if(ind> k-1)
		{
			e=ind;
			ind=partition(A,b,e);//如果下标比n/2大，那么中位数在其左边
		}
		else
		{
			b=ind;
			ind=partition(A,b,e);//下标小，到右边查找
		}
	}
}
//最大堆的实现比较复杂，但是这个比较简单
void maxHeap(vector<int> &heap, int i)//O(logk）完成插入和删除
{
	int largest = -1;
	int l = i*2+1, r = i*2+2;
	if(l < heap.size() && heap[l] > heap[i])
		largest = l;
	else
		largest = i;
	if(r < heap.size() && heap[r] > heap[largest])
		largest = r;
	if(largest != i)
	{
		int temp = heap[i];
		heap[i] = heap[largest];
		heap[largest] = temp;
		maxHeap(heap, largest);
	}
}
void buildMaxHeap(vector <int> &heap)
{
	if(heap.size()==1)
		return;
	for(int i = heap.size()/2-1; i>=0;i--)
	{
		maxHeap(heap,i);
	}
}

int main()
{
	//int k=8;
	int k=5;
	cin >>k;//5
	vector <int> A;
	//vector<int> heap={4,5,1,6,2};//{4,5,1,6,2,7,3,8};
	//vector<int> heap;
	//c++ 98不支持列表初始化
	int temp;
	while(cin>> temp)
	{
		A.push_back(temp);
		//heap.push_back(temp);
	}
	for(int i=0;i<A.size();++i)
	{
		cout << A[i];
	}
	cout << endl;
    GetLeastNums(A,k);
    for(int i=0;i<k;++i)
	{
		cout << A[i];
	}	
	/*
	int temp = 0;
	//heap.push_back(0);
    heap.push_back(4);
    heap.push_back(5);
    heap.push_back(1);
    heap.push_back(2);
    heap.push_back(6);
	//heap.push_back(7);
	//heap.push_back(3);
	//heap.push_back(8);
	for(int i=0;i<k;++i)
	{
		cout << heap[i];
	}//为什么输出是0
	cout << "haha" <<endl;
	buildMaxHeap(heap);
	int newData;
	while(cin>> newData)
	{
		if(newData < heap[1])
		{
			heap[1] = newData;
			maxHeap(heap,1);//更新堆
		}
	}
	for(int i=1;i<=k;++i)
	{
		cout << heap[i];
	}*/
	return 0;
}