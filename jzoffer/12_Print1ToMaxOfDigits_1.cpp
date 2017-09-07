#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

bool Increment(char *num){//实现字符串上的模拟加法
	bool isOverflow=false;//设置一个实现了一次加1的标志
	int len=strlen(num);//当前数字的长度
	int nTakeover=0;//进位
	
	for(int i=len-1;i>=0;--i){//从最低位开始进行字符串累加，
		int nSum=num[i]-'0'+nTakeover;//获取当前位上的数字，
		if(i==len-1)//如果已经到达最高位，当前位加1
			nSum++;
		
		if(nSum>=10){//当前位数字如果大于10，
			if(i==0)//如果最低位，则有进位
				isOverflow=true;
			else
			{
				nSum-=10;//当前数字减去10，
				nTakeover=1;//进位为1
				num[i]='0'+nSum;//将当前数字变为减去10之后的数字
			}
		}
		else
		{
			num[i]='0'+nSum;//如果当前数字小于10，直接赋值
			break;
		}
	}
	return isOverflow;//返回真，则完成一次加1
}

void PrintNum(char *num){//输出字符串表示的数字
	int i=0;
	while(num[i]=='0')
		i++;//排除首位是0的数字
	puts(num+i);
	//cout << num << endl;
}


void PrintToMaxN(int n){
	if(n<=0)
		return;
	
	char *num=new char[n+1];//对数字进行初始化
	memset(num,'0',n);//memset赋值为‘0’
	num[n]='\0';
	
	while (!Increment(num))//如果完成一次加1，输出该数字
		//cout << num << endl;
		PrintNum(num);
	
	delete []num;//new之后要delete
}

//全排列，打印1到最大的n位数，为了防止溢出，在字符串上模拟数字加法，
void PrintToMaxRecursively(char *num,int len,int index){
	if(index=len-1){//用递归实现加1，如果已经设置了数字的最后一位，则输出
		PrintNum(num);
		return;
	}
	
	for(int i=0;i<10;++i){//对于几位数字，所有的位进行全排列，从0开始
		num[index+1]=i+'0';
		PrintToMaxRecursively(num,len,index+1);//递归对1位，2位，。。n位进行排列
	}
}

void PrintToMaxN(int n){
	if(n<=0)
		return;
	
	char *num=new char[n+1];
	num[n]='\0';
	
	for(int i=0;i<10;++i){//
		num[0]=i+'0';
		PrintToMaxRecursively(num,n,0);//对每一个num进行输出
	}
	
	delete []num;
}
int main()
{
	int n;
	cin>>n;
	PrintToMaxN(n);
	return 0;
}

