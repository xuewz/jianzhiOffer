/*
��1��n������1���ֵĴ���
�ⷨһ��
O(nlgn)
�ۼ�1��n��ÿ������1���ֵĴ�����ÿ�ζ�10ȡ���жϸ�λ���ǲ���1...
�ⷨ2��
����21345����Ϊ������1-1345��1346~21345
����1346~21345�����λ2������1~19999��9999+1=10000
����λ��2*4*10^3=8000
����1345���Եݹ�
*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

int NumberOf1(unsigned int n)
{
	int sum=0;
	for(unsigned int i=1;i<=n;++i)
	{
		int temp=i;
		int num=0;
		while(temp)
		{
			if(temp%10==1)
				num++;
			temp=temp/10;
		}
		sum+=num;
	}
	return sum;
}

int NumOf1(unsigned int n)
{
	if(n<0)
		return 0;
	char s[50];
	sprintf(s,"%d",n);
	
	if(*s<'0' || *s>'9')
		return 0;
	int first=*s-'0';
	int len=strlen(s);
	if(len==1 && first==0)
		return 0;
	if(len==1 && first>0)
		return 1;
	int numFirst=0;
	if(first==1)
		numFirst=atoi(s+1)+1;
	else if(first>1)
		numFirst=pow(10.0,len-1);
	int numOther=first*(len-1)*pow(10.0,len-2);
	int numRecursive=NumOf1(atoi(s+1));
	cout <<numFirst <<" " << numOther<< endl;
	return numFirst+numOther+numRecursive;	
}

int main()
{
	unsigned int n;
	cin>> n;
	cout << NumberOf1(n) << endl;
	cout <<NumOf1(n) << endl;
	
	return 0;
}