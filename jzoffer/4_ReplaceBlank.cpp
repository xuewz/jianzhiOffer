#include <iostream>
#include <stdlib.h>

using namespace std;
//将空格替换成%20，首先求出空格的个数，那么替换之后的长度应该是原长度+2*空格数，然后设置一个数组新长度，分别指向两个数组的尾部，开始向前面复制
void replaceBlank(char* s,int len1)
{
	if (s == NULL || len1<=0)//先判断字符串是否为空，为空直接返回
		return;
	len1 = strlen(s);
	int i,c=0;
	
	for(i=0;i<len1;++i)
	{
		if(s[i] == ' ')//求出字符串中空格的长度
			c++;
	}
	
	int len2 = len1+c*2;//求出替换后字符串的长度
	
	while(len1>=0 && len2>len1)//从后往前开始复制
	{
		if(s[len1] == ' ')//当遇到空格时，复制02%
		{
			s[len2--] = '0';
			s[len2--] = '2';
			s[len2--] = '%';
		}
		else
			s[len2--] = s[len1];//非空格，直接赋值
		--len1;//复制非空格字符或者没有复制空格都需要直接向前减1
	}
}


//删除空格
void DeleteBlank(char *s)
{
	if (s == NULL)//用指针表示字符串会比较简单，当字符串为空直接返回
		return;

	char *p1 = s;
	char *p2 = s;

	while (*p1 != '\0')//P1,p2指向原始字符串，
	{
		if (*p2 != ' ')
			*(p1++) = *(p2++);//当p2指向非空格时，将p2赋值给p1，
		else
			p2++;//当p2遇到空格时，直接向后移动
	}
}

int main()
{
	char s[30] = "hello world!";
	int len1 = 30;
	//replaceBlank(s,len1);
	DeleteBlank(s);
	cout << s<<endl;
	return 0;
}