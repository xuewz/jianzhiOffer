#include <iostream>
#include <algorithm>

using namespace std;

//算法时间复杂度太大
class Solution{
	public:
	bool isUglyNumber(int n){
		if(n==1)
			return true;
		if(n==0)
			return false;
		
		while(n>=2 && n%2==0)n/=2;
		while(n>=3 && n%3==0)n/=3;
		while(n>=5 && n%5==0)n/=5;
		return n==1;
	}
	
	  int GetUglyNumber_Solution(int index) {
        if(index<=0)
            return 0;
        
        int num = 0;
        int i=0;
        while(i<index){
            ++num;
            if(isUglyNumber(num))
                ++i;
        }
        return num;
}

//空间换时间
int GetUglyNumber_Solution(int index) {
        list<int> l1;
        list<int> l2;
        list<int> l3;
        l1.push_back(1);
        l2.push_back(1);
        l3.push_back(1);
        int u=0;
        
        for(int i=0;i<index;i++){
            u=l1.front() >l2.front()?l2.front():l1.front();
            u=u>l3.front()?l3.front():u;
            if(l1.front()==u)
                l1.erase(l1.begin());
            if(l2.front()==u)
                l2.erase(l2.begin());
            if(l3.front()==u)
                l3.erase(l3.begin());
            l1.push_back(u*2);
            l2.push_back(u*3);
            l3.push_back(u*5);
        }
        
        return u;
    }
	
int main()
{
	
	return 0;
}