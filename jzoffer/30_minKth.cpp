/*�ҵ���С��k����,�ȼ��ڵ�kС����
��򵥵�˼·����������ȡǰk������O(nlogn);
�ⷨһ��
�������г��ִ�������һ�����ƣ����Ի���partitionʵ��O(n)
�ⷨ����
����һ����СΪk�Ķ����洢��С��k�����֣�O(nlogk)���ʺϺ�������
ά���������ѣ��ڶѵĶ�������Сk��������������
Ȼ������������飬�Ƚϵ�ǰ���ͶѶ�����ȵ�ǰ��С��ֻ��Ҫ�ѶѶ�Ԫ�ػ��ɵ�ǰ����
Ȼ������ѣ�������ǣ�����������һ��������ɱ����󣬶��е�k��������������������С��k������
*/
//�����ѣ�������С��k����
//���������
//���������
//��������洢��Ԫ��
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
			ind=partition(A,b,e);//����±��n/2����ô��λ���������
		}
		else
		{
			b=ind;
			ind=partition(A,b,e);//�±�С�����ұ߲���
		}
	}
}
//���ѵ�ʵ�ֱȽϸ��ӣ���������Ƚϼ�
void maxHeap(vector<int> &heap, int i)//O(logk����ɲ����ɾ��
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
	//c++ 98��֧���б��ʼ��
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
	}//Ϊʲô�����0
	cout << "haha" <<endl;
	buildMaxHeap(heap);
	int newData;
	while(cin>> newData)
	{
		if(newData < heap[1])
		{
			heap[1] = newData;
			maxHeap(heap,1);//���¶�
		}
	}
	for(int i=1;i<=k;++i)
	{
		cout << heap[i];
	}*/
	return 0;
}